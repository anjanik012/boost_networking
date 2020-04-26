//
// Created by Anjani Kumar <anjanik012@gmail.com> on 4/25/20.
//

#include "random_string.h"
#include <ctime>

std::string random_string::gen(const uint16_t sz) {
    boost::random::uniform_int_distribution<uint16_t> dist(0, sz-1);
    std::string res;
    res.resize(sz);
    for (int i = 0; i < sz; ++i) {
        res[i] = chars[dist(rng)];
    }
    return res;
}
