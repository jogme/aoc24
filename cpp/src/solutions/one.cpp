/* File to solve the first task of aoc 24
 * @author: Norbert Pocs
 */

#include <iostream>

#include "Parser.h"

/* Parser should already be loaded here */
static int solve_a(Parser& p) {
    (void)p;
    return 0;
}

/* Parser should already be loaded here */
static int solve_b(Parser& p) {
    (void)p;
    return 0;
}

void solve_one(Parser& p) {
    p.tokenize_data();
    int a, b;

    a = solve_a(p);
    b = solve_b(p);

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
}
