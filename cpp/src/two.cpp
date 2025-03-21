/* File to solve the second task of aoc 24
 * @author: Norbert Pocs
 */

#include <stdlib.h>
#include <iostream>

#include "Parser.h"

using std::vector;

static int solve(vector<vector<int>>& in) {
    int safe = 0;
    for (auto& v : in) {
        bool desc = v[1] < v[0];
        size_t good = 0;
        for (size_t i=1; i<v.size(); i++) {
            if (v[i] != v[i-1]) {
                if (!((v[i] < v[i-1]) ^ desc) && abs(v[i]-v[i-1]) <= 3) {
                    good++;
                } else {
                    break;
                }
            }
        }
        /* as the difference are counted, the counted number is always all-1 */
        size_t v_size = v.size()-1;
        if (good == v_size) {
            safe++;
        }
    }

    return safe;
}

void solve_two(Parser& p) {
    p.tokenize_data_int();

    std::cout << "a: " << solve(p.tokens_int) << "\n";
    //std::cout << "b: " << solve(p.tokens_int, true) << "\n";
}
