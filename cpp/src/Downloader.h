#pragma once

#include <string>

class Downloader {
    private:
        const std::string token_file = "auth_token";
        const std::string url_templ1 = "https://adventofcode.com/2024/day/";
        const std::string url_templ2 = "/input";
        std::string url;
        std::string token;
    public:
        int day;

        std::string get_input_data();
        std::vector<std::string> read_file(std::string file_name);
        void write_file(std::string file_name, std::vector<std::string> data);
        Downloader(int day);
};
