/* main.c
* Main program to run a specific day solution of Advent of Code
*/

#include <stdio.h>
#include <stdlib.h>

#include "aoc_input.h"
#include "solutions.h"

size_t solve1(char *input);

size_t (*solutions[25]) (char*) = {
    solve1, solve2, solve3, solve4, solve5,
    solve6, solve7, solve8, solve9, solve10,
    solve11, solve12, solve13, solve14, solve15,
    solve16, solve17, solve18, solve19, solve20,
    solve21, solve22, solve23, solve24, solve25
};

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    char *input = NULL;
    int rc = 0;

    for(int i = 0; i < 25; i++) {
        rc = read_file(i+1, &input);
        if (rc != 0) {
            fprintf(stderr, "No input file for day %d\n", i+1);
            return -1;
        }
        rc = solutions[i](input);
        printf("%d\n", rc);
        free(input);
    }

    return 0;
}
