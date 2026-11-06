#pragma once

template <typename T, typename U>
T bin_pow(T a, U b, const T& id = T(1)) {

    T res = id;

    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        b >>= 1;
        if (b > 0) {
            a *= a;
        }
    }

    return res;

}
