/* The main file of the program.
 * @author: Norbert Pocs
 */

#include <unistd.h>
#include <iostream>

#include "Parser.h"
#include "aoc.h"

std::vector<void (*) (Parser&)> day_f = {solve_one, solve_two, solve_three};

int main(int argc, char **argv) {
    int opt, day;
    bool dummy = false;

    while((opt = getopt(argc, argv, "d")) != -1) {
        switch (opt) {
            case 'd': dummy = true;
        }
    }

    if (optind >= argc) {
        std::cerr << "Please provide the requested day as an argument\n";
        return -1;
    }

    day = std::stoi(argv[optind]);

    /* it is never going to be bigger than MAX_INT */
    if (day > (int)day_f.size()) {
        std::cerr << "No implementation for day " << day << "\n";
        return -1;
    }

    Parser p(day, dummy);
    day_f[day-1](p);

    return 0;
}
