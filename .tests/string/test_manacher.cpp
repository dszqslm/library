#include <cstdint>
#include <string>
#include <vector>

#include "external/doctest.h"

#include "string/manacher.cpp"

TEST_CASE("manacher") {

    using vec = std::vector<std::int32_t>;

    const std::string s("aabaaab");
    const std::string t("-a-b-c-b-c-b-a-");

    CHECK(manacher(std::begin(s), std::end(s)) == vec({1, 1, 3, 1, 3, 1, 1}));
    CHECK(
        manacher(std::begin(t), std::end(t)) == vec({1, 2, 1, 2, 1, 4, 1, 8, 1, 4, 1, 2, 1, 2, 1})
    );

}
