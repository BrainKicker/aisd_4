#include <iostream>

#include "find_match.h"

const int max_string_size = 500000;

char pattern[max_string_size+1];
char text[max_string_size+1];

int main() {

    std::cin.getline(pattern, max_string_size);
    std::cin.getline(text, max_string_size);

    find_match(pattern, text);
}