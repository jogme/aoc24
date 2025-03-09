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
    public:
        std::vector <std::string> input_data;

        Parser(int day, bool dummy);
};
