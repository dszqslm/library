#include <vector>

#include "external/doctest.h"

#include "math/nt/sieve.cpp"

TEST_CASE("sieve") {

    sieve::reserve(50);

    CHECK(sieve::fcts[2] == 2);
    CHECK(sieve::fcts[5] == 5);
    CHECK(sieve::fcts[9] == 3);
    CHECK(sieve::fcts[13] == 13);
    CHECK(sieve::fcts[21] == 3);
    CHECK(sieve::fcts[25] == 5);
    CHECK(sieve::fcts[31] == 31);
    CHECK(sieve::fcts[49] == 7);
    CHECK(sieve::fcts[50] == 2);

    CHECK(sieve::prms == std::vector({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}));

}
