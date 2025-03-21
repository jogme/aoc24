/* File to solve the second task of aoc 24
 * @author: Norbert Pocs
 */

#include <stdlib.h>
#include <iostream>

#include "Parser.h"

using std::vector;

static int solve_two_a(vector<vector<int>>& in) {
    int safe = 0;
    for (auto& v : in) {
        bool desc = v[1] < v[0];
        bool good = true;
        for (size_t i=1; i<v.size(); i++) {
            if (v[i] == v[i-1] || ((v[i] >= v[i-1]) ^ !desc) || (abs(v[i]-v[i-1]) > 3)) {
                good = false;
                break;
            }
        }
        if (good) {
            safe++;
        }
    }

    return safe;
}

void solve_two(Parser& p) {
    p.tokenize_data_int();

    std::cout << "a: " << solve_two_a(p.tokens_int) << "\n";
    //std::cout << "b: " << solve(p.tokens_int, true) << "\n";
}
