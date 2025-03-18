/* The main file of the program.
 * @author: Norbert Pocs
 */

#include <unistd.h>
#include <iostream>

#include "Parser.h"
#include "aoc.h"

std::vector<void (*) (Parser&)> day_f = {solve_one};

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

    Parser p(day, dummy);
    day_f[day-1](p);

    return 0;
}
