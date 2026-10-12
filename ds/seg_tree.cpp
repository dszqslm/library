#pragma once

#include <bit>
#include <cstdint>
#include <utility>

namespace seg_tree {

    constexpr std::int32_t log_2(std::int32_t x) {

        return std::bit_width<std::uint32_t>(x) - 1;

    }

    template <typename F>
    void for_pars(std::int32_t nd, std::int32_t dir, F f) {

        const std::int32_t lg = log_2(nd);

        for (std::int32_t i = 1; i <= lg; ++i) {
            f(nd >> (dir == 0 ? lg - i + 1 : i));
        }

    }

    template <typename F>
    void for_rng(std::int32_t nd_1, std::int32_t nd_2, F f) {

        while (nd_1 < nd_2) {
            if (nd_1 & 1) {
                f(nd_1);
                ++nd_1;
            }
            if (nd_2 & 1) {
                --nd_2;
                f(nd_2);
            }
            nd_1 >>= 1;
            nd_2 >>= 1;
        }

    }

    template <typename F>
    void for_ord(std::int32_t nd_1, std::int32_t nd_2, F f) {

        if (nd_1 == nd_2) {
            return;
        }

        const bool rev = nd_1 > nd_2;

        if (rev) {
            std::swap(nd_1, nd_2);
            ++nd_1;
            ++nd_2;
        }

        const std::int32_t msk = (1 << log_2((nd_1 - 1) ^ nd_2)) - 1;
        const std::int32_t amt = !rev ? 1 : -1;

        std::int32_t bs = !rev ? nd_1 - 1 : nd_2;
        std::int32_t nd = (!rev ? -nd_1 : nd_2) & msk;

        while (nd) {
            const std::int32_t bit = std::countr_zero<std::uint32_t>(nd);
            f((bs >> bit) + amt);
            nd ^= 1 << bit;
        }

        bs = !rev ? nd_2 : nd_1 - 1;
        nd = (!rev ? nd_2 : -nd_1) & msk;

        while (nd) {
            const std::int32_t bit = log_2(nd);
            f((bs >> bit) - amt);
            nd ^= 1 << bit;
        }

    }

}
