/* This files holds the purpose to read in the input files.
 * The file can be either "dummy" or "input".
 * @author: Norbert Pocs
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Parser.h"
#include "Downloader.h"

using std::string;
using std::stringstream;
using std::vector;
using std::runtime_error;

Parser::Parser(int day, bool dummy)
              : day{day}, dummy{dummy} {
    stringstream ss;
    ss << this->input_file_dir << day << "." << (dummy ? "dummy" : "input");
    this->path = ss.str();
    Downloader d(day);

    try {
        this->input_data = d.read_file(this->path);
    } catch (const std::exception& e) {
        if (!dummy) {
            this->input_data = this->deserialize_input(d.get_input_data());
            d.write_file(this->path, this->input_data);
        }
    }
}

vector<string> Parser::deserialize_input(string s) {
    string line;
    stringstream ss(s);
    vector<string> ret;

    while(getline(ss, line)) {
        ret.push_back(line);
    }

    return ret;
}

vector<string> Parser::deserialize_input(std::ifstream& s) {
    string line;
    vector<string> ret;

    while(std::getline(s, line)) {
        ret.push_back(line);
    }

    return ret;
}

void Parser::read_file(void) {
    std::ifstream file;
    string line;

    file.open(this->path);
    if (!file.is_open()) {
        throw runtime_error("Could not open file: \"" + this->path + "\"");
    }

    this->input_data = this->deserialize_input(file);

    file.close();
}

void Parser::tokenize_data() {
    if (this->input_data.empty()) {
        throw runtime_error("Can't tokenize; the input data was not yet read!");
    }
    for (string& s : this->input_data) {
        std::istringstream iss(s);
        vector<string> tmp_v;
        string word;
        while (iss >> word) {
            tmp_v.push_back(word);
        }
        this->tokens.push_back(tmp_v);
    }
}

void Parser::tokenize_data_int() {
    if (this->input_data.empty()) {
        throw runtime_error("Can't tokenize; the input data was not yet read!");
    }
    for (string& s : this->input_data) {
        std::istringstream iss(s);
        vector<int> tmp_v;
        string word;
        while (iss >> word) {
            tmp_v.push_back(std::stoi(word));
        }
        this->tokens_int.push_back(tmp_v);
    }
}

/* TODO write test here */
/*
int main() {
    try {
        Parser p = Parser(1, true);
        cout << "file contents:\n";
        for (const auto& l : p.input_data) {
            cout << l << '\n';
        }
        p.tokenize_data();
    } catch (const exception& e) {
        cerr << e.what() << '\n';
        return -1;
    }
    
    return 0;
}
*/
