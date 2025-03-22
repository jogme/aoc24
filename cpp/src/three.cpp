/* File to solve the third task of aoc 24
 * @author: Norbert Pocs
 */

#include <regex>
#include <iostream>
#include <string>

#include "Parser.h"

using std::vector;
using std::string;
using std::smatch;

int solve_three_a(vector<string> input) {
    const std::regex mul_regex("mul\\(\\d{1,3},\\d{1,3}\\)");
    const std::regex mul_num_regex("\\d{1,3}");
    int ret = 0;

    for (auto& data : input) {
        for(smatch mul_match; std::regex_search(data, mul_match, mul_regex);) {
            smatch mul_nums_match;
            string tmp = mul_match[0];
            string num1, num2;

            std::regex_search(tmp, mul_nums_match, mul_num_regex);
            num1 = mul_nums_match[0];

            tmp = mul_nums_match.suffix();
            std::regex_search(tmp, mul_nums_match, mul_num_regex);
            num2 = mul_nums_match[0];

            data = mul_match.suffix();

            ret += stoi(num1) * stoi(num2);
        }
    }

    return ret;
}

void solve_three(Parser& p) {
    std::cout << "a: " << solve_three_a(p.input_data) << "\n";
}
