/* File to solve the second task of aoc 24
 * @author: Norbert Pocs
 */

#include <stdlib.h>
#include <iostream>

#include "Parser.h"

using std::vector;

static bool solve_two_sub(vector<int>& v) {
    bool desc = v[1] < v[0];
    for (size_t i=1; i<v.size(); i++) {
        if (v[i] == v[i-1] || ((v[i] >= v[i-1]) ^ !desc) || (abs(v[i]-v[i-1]) > 3)) {
            return false;
        }
    }
    return true;
}

static int solve_two_a(vector<vector<int>>& in) {
    int safe = 0;
    for (auto& v : in) {
        if (solve_two_sub(v)) {
            safe++;
        }
    }

    return safe;
}

static int solve_two_b(vector<vector<int>>& in) {
    int safe = 0;
    for (auto& v : in) {
        if (solve_two_sub(v)) {
            safe++;
        } else {
            for (size_t i=0; i<v.size(); i++) {
                vector<int> sub = v;
                sub.erase(sub.begin() + i);
                if (solve_two_sub(sub)) {
                    safe++;
                    break;
                }
            }
        }
    }

    return safe;
}

void solve_two(Parser& p) {
    p.tokenize_data_int();

    std::cout << "a: " << solve_two_a(p.tokens_int) << "\n";
    std::cout << "b: " << solve_two_b(p.tokens_int) << "\n";
}
