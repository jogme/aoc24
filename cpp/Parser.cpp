/* This files holds the purpose to read in the input files.
 * The file can be either "dummy" or "input".
 * @author: Norbert Pocs
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Parser.h"

Parser::Parser(int day, bool dummy)
              : day{day}, dummy{dummy} {
    std::stringstream ss;
    ss << this->input_file_dir << day << "." << (dummy ? "dummy" : "input");
    this->path = ss.str();

    Parser::read_file();
}


void Parser::read_file(void) {
    std::ifstream file;
    std::string line;

    file.open(this->path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: \"" + this->path + "\"");
    }

    while(std::getline(file, line)) {
        input_data.push_back(line);
    }

    file.close();
}

void Parser::tokenize_data() {
    if (this->input_data.empty()) {
        throw std::runtime_error("Can't tokenize; the input data was not yet read!");
    }
    for (std::string& s : this->input_data) {
        std::istringstream iss(s);
        std::vector<std::string> tmp_v;
        std::string word;
        while (iss >> word) {
            tmp_v.push_back(word);
        }
        this->tokens.push_back(tmp_v);
    }
}

int main() {
    try {
        Parser p = Parser(1, true);
        std::cout << "file contents:\n";
        for (const auto& l : p.input_data) {
            std::cout << l << '\n';
        }
        p.tokenize_data();
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
    
    return 0;
}
