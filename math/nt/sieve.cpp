#pragma once

#include <cstdint>
#include <vector>

namespace sieve {

    std::vector<std::int32_t> fcts;
    std::vector<std::int32_t> prms;

    void reserve(std::int32_t cap) {

        fcts.resize(cap + 1);

        for (std::int32_t i = 2; i <= cap; ++i) {
            if (fcts[i] == 0) {
                fcts[i] = i;
                prms.push_back(i);
            }
            for (auto x : prms) {
                if (i * x > cap) {
                    break;
                }
                fcts[i * x] = x;
                if (x == fcts[i]) {
                    break;
                }
            }
        }

    }

}
