/* File to solve the first task of aoc 24
 * @author: Norbert Pocs
 */

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <map>

#include "Parser.h"

using std::vector;
using std::string;
using std::cout;
using std::sort;

/* Parser should already be loaded here */
static int solve_a(vector <int> vi1, vector <int> vi2) {
    vector <int> tmp(vi1.size());
    std::transform(vi1.begin(), vi1.end(), vi2.begin(), tmp.begin(), [](int a, int b){return std::abs(a-b);});

    return std::reduce(tmp.begin(), tmp.end());
}

/* Parser should already be loaded here */
static int solve_b(vector <int> vi1, vector <int> vi2) {
    std::map <int, int> occurrence;
    vector <int> tmp;

    for (const auto& i : vi1) {
        int o = std::count(vi2.begin(), vi2.end(), i);
        occurrence[i] = o;
    }
    for (const auto& i : vi1) {
        tmp.push_back(i*occurrence[i]);
    }
    return std::reduce(tmp.begin(), tmp.end());
}

void solve_one(Parser& p) {
    p.tokenize_data();
    int a, b;
    vector <int> vi1;
    vector <int> vi2;

    for (const vector<string>& vs : p.tokens) {
        vi1.push_back(std::stoi(vs[0]));
        vi2.push_back(std::stoi(vs[1]));
    }
    sort(vi1.begin(), vi1.end());
    sort(vi2.begin(), vi2.end());

    a = solve_a(vi1, vi2);
    b = solve_b(vi1, vi2);

    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
}
