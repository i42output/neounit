// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <type_traits>
#include <cmath>
#include <iostream>
#include <neounit/si.hpp>

namespace
{
    void test_assert(bool assertion)
    {
        if (!assertion)
            throw std::logic_error("Test failed");
    }

    bool near_enough(double lhs, double rhs)
    {
        return std::abs(lhs - rhs) < 1e-9;
    }
}

int main()
{
    using namespace neounit::si;

    kilogram m0 = 0.0;
    kilogram m1 = 7.0;
    kilogram m2 = 42.0;
    kilogram m3 = m1 + m2;
    kilogram m4 = m3 - m2;
    auto m5 = m1 * m2;
    auto m6 = m1 / m2;
    auto m7 = m5 / m1;
    auto m8 = m5 / m1 / m1;
    auto m9 = 1.0 / m1;

    static_assert(std::is_same_v<decltype(m5), kilogram_sq>);
    static_assert(std::is_same_v<decltype(m6), double>);
    static_assert(std::is_same_v<decltype(m7), kilogram>);
    static_assert(std::is_same_v<decltype(m8), double>);
    static_assert(std::is_same_v<decltype(m9), inv_kilogram>);

    test_assert(m0 == 0.0);
    test_assert(0.0 == m0);
    test_assert(near_enough(m4, m1));
    test_assert(near_enough(m5, 7.0 * 42.0));
    test_assert(near_enough(m6, 7.0 / 42.0));
    test_assert(m5 != 0.0);
    test_assert(0.0 != m5);
}