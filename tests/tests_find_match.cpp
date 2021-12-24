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