#ifndef AISD_4_FIND_MATCH_H
#define AISD_4_FIND_MATCH_H

#include <iostream>
#include <cstring>

const uint32_t p = 1000;
const uint32_t M = 10000;

uint32_t add(uint32_t a, uint32_t b) {
    return (a + b) % M;
}
uint32_t sub(uint32_t a, uint32_t b) {
    return (a - b) % M;
}
uint32_t mul(uint32_t a, uint32_t b) {
    return (a * b) % M;
}
uint32_t pow(uint32_t a, uint32_t n) {
    uint32_t res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

void find_match(const char* pattern, const char* text, std::ostream& out = std::cout) {

    const uint32_t pattern_len = strlen(pattern);
    const uint32_t text_len = strlen(text);

    if (pattern_len == 0 || pattern_len > text_len)
        return;

    const uint32_t p_n = pow(p, pattern_len - 1);

    uint32_t pattern_h = 0;

    for (uint32_t i = 0; i < pattern_len; ++i)
        pattern_h = add(mul(pattern_h, p), pattern[i]);

    uint32_t cur_h = 0;

    for (uint32_t i = 0; i < pattern_len; ++i)
        cur_h = add(mul(cur_h, p), text[i]);

    for (uint32_t i = 0; i < text_len - pattern_len + 1; ++i) {
        if (cur_h == pattern_h) {
            bool eq = true;
            for (uint32_t j = i; j < i + pattern_len; ++j) {
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