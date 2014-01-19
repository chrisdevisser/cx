#pragma once
#ifndef CX_ALGORITHM_RANDOM_H
#define CX_ALGORITHM_RANDOM_H

#include <assert.h>
#include <stdlib.h>

#include "../boost_pp/facilities/overload.hpp"
#include "../template.hh"

//generate random number in range without modulus bias
//credit to comments on http://stackoverflow.com/a/10984975/962089
static int cxRandIn(int minimum, int maximum) {
    int n = maximum - minimum;
    assert((n - 1 <= RAND_MAX) && "RAND_MAX too small for range.");

    int x;
    do {
        x = rand();
    } while (x > RAND_MAX - ((RAND_MAX%n)+1)%n);

    return (x % n) + minimum;
}

#endif
