/* tests for utility functions */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// turn off for detailed debugging
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
#include "doctest.h"

#include <unistd.h>
#include <cstdio>

#define READ_FILE_TEST_NAME "build/tests/read_test"
#define READ_FILE_TEST_CONTENT "Ay-Ay-Ay Your soul's too dry,"

#define WRITE_FILE_TEST_NAME "build/tests/write_test"
#define WRITE_FILE_TEST_CONTENT "Rick and Morty in the parallel universe"

#include "Downloader.h"

using std::string;
using std::vector;

TEST_SUITE_BEGIN("downloader" * doctest::description("Tests the class Downloader"));

TEST_CASE("read_file function") {
    Downloader d(1);
    vector<string> vs;

    CHECK_THROWS(d.read_file("non_existento_filo"));
    vs = d.read_file(READ_FILE_TEST_NAME);
    CHECK(vs[0] == READ_FILE_TEST_CONTENT);
}

TEST_CASE("write_file function") {
    Downloader d(1);
    vector<string> vs = {WRITE_FILE_TEST_CONTENT};

    d.write_file(WRITE_FILE_TEST_NAME, vs);
    CHECK_FALSE(access(WRITE_FILE_TEST_NAME, F_OK) == -1);

    vs.clear();
    vs = d.read_file(WRITE_FILE_TEST_NAME);
    CHECK(vs[0] == WRITE_FILE_TEST_CONTENT);

    std::remove(WRITE_FILE_TEST_NAME);
}

TEST_CASE("get_input_data function") {
    Downloader d(1);
    string s;

    s = d.get_input_data();
}

TEST_SUITE_END();

TEST_SUITE_BEGIN("parser" * doctest::description("Tests the class Parser"));
TEST_SUITE_END();
