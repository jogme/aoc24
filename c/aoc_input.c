/* aoc_input.c
 * Reading input for advent of code.
 * @author Norbert Pocs
*/

#include <stdio.h>
#include <stdlib.h>

#ifdef ONLINE_GET
/* TODO when implemented put it into a file and put into gitignore
 * to not leak it */
const char *token = "";
const char *url = "https://adventofcode.com/2023/day/%s/input";

static int write_file(short n_day, char *text) {
    return 0;
}

static int get_file(short n_day) {
    return 0;
}
#endif /* ONLINE_GET */

// TODO change back to .input
const char *aoc_input_file_template = "input_files/%d.dummy";

/*
 * @param n_day The number of the day which should be loaded
 * @param input A double pointer for the input text which is going
 *              to be allocated by this function. Please free it after use
 */
int read_file(short n_day, char **input) {
    FILE *f = NULL;
    char file_name[400] = {0};
    char *tmp = NULL;
    size_t file_size = 0;
    int rc;
    size_t rc_f;

    if (n_day < 0 || n_day > 25 || *input != NULL) {
        return -1;
    }

    rc = snprintf(file_name, 400, aoc_input_file_template, n_day);
    /* this does not check if all the bytes were written or not */
    if (rc < 0) {
        return -1;
    }

    f = fopen(file_name, "r");
    if (f == NULL) {
        return -1;
    }

    /* get the file length for string allocation */
    rc = fseek(f, 0L, SEEK_END);
    if (rc < 0) {
        fclose(f);
        return -1;
    }
    file_size = ftell(f);

    rc = fseek(f, 0L, SEEK_SET);
    if (rc < 0) {
        fclose(f);
        return -1;
    }

    tmp = calloc(file_size, 1);
    if (tmp == NULL) {
        fclose(f);
        return -1;
    }
    rc_f = fread(tmp, 1, file_size, f);
    if (rc_f != file_size) {
        free(tmp);
        fclose(f);
        return -1;
    }

    *input = tmp;

    fclose(f);
    return rc;
}
