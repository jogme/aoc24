/* This files handles "automatic" input download from the aoc site
 * @author: Norbert Pocs
 */

#include <curl/curl.h>
#include <stdexcept>
#include <format>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>

#include "Downloader.h"

Downloader::Downloader(int day) : day{day} {
    std::stringstream ss;
    std::vector<std::string> tmp;

    ss << this->url_templ1 << day << this->url_templ2;
    this->url = ss.str();
    tmp = this->read_file(this->token_file);
    this->token = tmp[0];
}

static size_t callback(char *data, size_t size, size_t nmemb, void **userp) {
    size_t total_size = nmemb*size;
    static size_t current_size = 0;

    *userp = realloc(*userp, current_size+total_size+1);
    memset(*(char**)userp+current_size, 0, total_size+1);
    memcpy(*(char**)userp+current_size, data, total_size);
    current_size += total_size;

    return total_size;
}

std::string Downloader::get_input_data() {
    CURL *handle;
    CURLcode result;
    char* response_data = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    handle = curl_easy_init();
    if (!handle) {
        throw std::runtime_error("Could not initialize curl handle\n");
    }
    curl_easy_setopt(handle, CURLOPT_URL, this->url.c_str());
    curl_easy_setopt(handle, CURLOPT_COOKIE, this->token.c_str());
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response_data);

    result = curl_easy_perform(handle);

    if (result != CURLE_OK) {
        curl_easy_cleanup(handle);
        curl_global_cleanup();
        throw std::runtime_error("Could not read input data from the cloud\n");
    }

    curl_easy_cleanup(handle);
    curl_global_cleanup();

    std::string s(response_data);
    free(response_data);

    return s;
}

/* The token is awaited to be on a single line */
std::vector<std::string> Downloader::read_file(std::string file_name) {
    std::ifstream file;
    std::string line;
    std::vector<std::string> input_data;

    file.open(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: \"" + file_name + "\"");
    }

    while(std::getline(file, line)) {
        input_data.push_back(line);
    }

    file.close();

    return input_data;
}

void Downloader::write_file(std::string file_name, std::vector<std::string> data) {
    std::ofstream file;

    file.open(file_name);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: \"" + file_name + "\"");
    }

    for (const auto& s : data) {
        file << s;
    }

    file.close();
}
