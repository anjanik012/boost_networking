//
// Created by Anjani Kumar <anjanik012@gmail.com> on 4/25/20.
//

#ifndef BOOST_TEST_RANDOM_STRING_H
#define BOOST_TEST_RANDOM_STRING_H

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <ctime>

class random_string {
private:
    boost::random::mt19937 rng;
    char chars[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_+=[{]";
public:
    random_string():rng(std::time(nullptr)){}
    std::string gen(uint16_t sz);
};


#endif //BOOST_TEST_RANDOM_STRING_H
