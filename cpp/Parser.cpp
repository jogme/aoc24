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

int main() {
    try {
        Parser p = Parser(1, false);
        std::cout << "file contents:\n";
        for (const auto& l : p.input_data) {
            std::cout << l << '\n';
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }
    
    return 0;
}
