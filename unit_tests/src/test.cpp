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
        return std::abs(lhs - rhs) < 1e-6;
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
    auto m9 = m5 / (m1 * m1);
    auto m10 = 1.0 / m1;
    auto m11 = 1.0 / m1 / m1;
    auto m12 = 1.0 / (m1 * m1);

    auto m20 = conversion_cast<kilogram>(m1);
    auto m21 = conversion_cast<gram>(m1);

    kilometre_sq m30 = 42.0;
    auto m31 = conversion_cast<metre_sq>(m30);
    inv_kilometre_sq m32 = 1.0 / 42.0;
    auto m33 = conversion_cast<inv_metre_sq>(m32);
    auto m34 = 1.0 / m33;
    auto m35 = conversion_cast<inv_kilometre_sq>(m33);

    static_assert(std::is_same_v<decltype(m5), kilogram_sq>);
    static_assert(std::is_same_v<decltype(m6), double>);
    static_assert(std::is_same_v<decltype(m7), kilogram>);
    static_assert(std::is_same_v<decltype(m8), double>);
    static_assert(std::is_same_v<decltype(m9), double>);
    static_assert(std::is_same_v<decltype(m10), inv_kilogram>);
    static_assert(std::is_same_v<decltype(m11), inv_kilogram_sq>);
    static_assert(std::is_same_v<decltype(m12), inv_kilogram_sq>);
    static_assert(std::is_same_v<decltype(m20), kilogram>);
    static_assert(std::is_same_v<decltype(m21), gram>);
    static_assert(std::is_same_v<decltype(m31), metre_sq>);
    static_assert(std::is_same_v<decltype(m33), inv_metre_sq>);
    static_assert(std::is_same_v<decltype(m34), metre_sq>);
    static_assert(std::is_same_v<decltype(m35), inv_kilometre_sq>);

    test_assert(m0 == 0.0);
    test_assert(0.0 == m0);
    test_assert(near_enough(m4, m1));
    test_assert(near_enough(m5, 7.0 * 42.0));
    test_assert(near_enough(m6, 7.0 / 42.0));
    test_assert(m5 != 0.0);
    test_assert(0.0 != m5);
    test_assert(near_enough(m11, m12));
    test_assert(m20 == m1);
    test_assert(near_enough(m21, 7000.0));
    test_assert(near_enough(m30, 42.0));
    test_assert(near_enough(m31, 42000000.0));
    test_assert(near_enough(m32, 1.0 / 42.0));
    test_assert(near_enough(m33, 1.0 / 42000000.0));
    test_assert(near_enough(m34, 42000000.0));
    test_assert(near_enough(m35, 1.0 / 42.0));
}