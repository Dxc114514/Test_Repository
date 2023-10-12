#include <bits/stdc++.h>
#include "base/big_integer/definition.hpp"

int main() {
    try {
        std::string number;
        std::cin >> number;
        BigInteger test(number);
        std::cout << test;
    } catch (BigIntegerException e) {
        std::cout << e.what();
    }
    return 0;
}