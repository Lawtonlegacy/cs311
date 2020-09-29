// dp3.cpp
// Robert Lawton
// 2020-09-17
//
// For CS 311 Fall 2020
// Source for Project 3 functions

#include "dp3.h" // For Project 3 prototypes & templates

#include <functional>
using std::function;


void didItThrow(const function<void()>& ff,
    bool& threw)
{
    threw = false;
    try {
        ff();
    }
    catch (...) {
        threw = true;
        throw;
    }
}


int gcd(int a,
    int b)
{
    if (a == 0)
        return b;

    if (a > b)
        gcd(b, a);

    gcd(b % a, a);
}