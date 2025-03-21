#pragma once

#include <string>
#include <vector>

class Parser {
    private:
        int day;
        bool dummy;
        const std::string input_file_dir = "../input_files/";
        std::string path;

        void read_file(void);
        std::vector<std::string> deserialize_input(std::string s);
std::vector<std::string> deserialize_input(std::ifstream& s);
    public:
        std::vector <std::string> input_data;
        std::vector <std::vector <std::string>> tokens;
        std::vector <std::vector<int>> tokens_int;
        void tokenize_data();
        void tokenize_data_int();

        Parser(int day, bool dummy);
};
