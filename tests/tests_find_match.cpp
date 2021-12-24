#include <catch2/catch.hpp>

#include <sstream>
#include <vector>

#include "../source/find_match.h"

TEST_CASE("Find match test 1", "[test]") {
    const char* pattern = "aba";
    const char* text = "abacaba";
    std::vector<int> expected_output = { 0, 4 };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}

TEST_CASE("Find match test 2", "[test]") {
    const char* pattern = "aba";
    const char* text = "ababababa";
    std::vector<int> expected_output = { 0, 2, 4, 6 };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}

TEST_CASE("Find match test 3", "[test]") {
    const char* pattern = "a";
    const char* text = "aaaaba";
    std::vector<int> expected_output = { 0, 1, 2, 3, 5 };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}

TEST_CASE("Find match test empty", "[test]") {
    const char* pattern = "";
    const char* text = "aaaaba";
    std::vector<int> expected_output = {  };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}

TEST_CASE("Find match test pattern longer than text", "[test]") {
    const char* pattern = "abcdefg";
    const char* text = "aaaaba";
    std::vector<int> expected_output = {  };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}

TEST_CASE("Find match test equal", "[test]") {
    const char* pattern = "qwe";
    const char* text = "qwe";
    std::vector<int> expected_output = { 0 };
    std::stringstream ss;
    find_match(pattern, text, ss);
    std::vector<int> output;
    int index;
    while (ss >> index)
        output.push_back(index);
    REQUIRE(expected_output == output);
}