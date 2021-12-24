#ifndef AISD_4_FIND_MATCH_H
#define AISD_4_FIND_MATCH_H

#include <iostream>
#include <cstring>

const int p = 1000;
const int M = 10000;

int add(int a, int b) {
    return (a + b) % M;
}
int sub(int a, int b) {
    return (a - b) % M;
}
int mul(int a, int b) {
    return (a * b) % M;
}
int pow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

void find_match(const char* pattern, const char* text, std::ostream& out = std::cout) {

    const int pattern_len = strlen(pattern);
    const int text_len = strlen(text);

    const int p_n = pow(p, pattern_len - 1);

    int pattern_h = 0;

    for (int i = 0; i < pattern_len; ++i)
        pattern_h = add(mul(pattern_h, p), pattern[i]);

    int cur_h = 0;

    for (int i = 0; i < pattern_len; ++i)
        cur_h = add(mul(cur_h, p), text[i]);

    for (int i = 0; i < text_len - pattern_len + 1; ++i) {
        if (cur_h == pattern_h) {
            bool eq = true;
            for (int j = i; j < i + pattern_len; ++j) {
                if (pattern[j-i] != text[j]) {
                    eq = false;
                    break;
                }
            }
            if (eq) {
                out << i << ' ';
            }
        }
        cur_h = sub(cur_h, mul(text[i], p_n));
        cur_h = add(mul(cur_h, p), text[i+pattern_len]);
    }

    out << std::endl;
}

#endif //AISD_4_FIND_MATCH_H