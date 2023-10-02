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

//#define CHECK_STATIC_ASSERTS

int main()
{
    using namespace neounit::si;

    kilogram m0 = 0.0;
    kg<1> m1 = 7.0;
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

    using cm_per_s = decltype(cm<1>{} / s<1>{});
    cm_per_s v1 = 1.0;
    using m_per_s = decltype(m<1>{} / s<1>{});
    auto v2 = conversion_cast<m_per_s>(v1);
#ifdef CHECK_STATIC_ASSERTS
    auto mixingUnitsBad = v1 + v2; // compilation failure if enabled
#endif

    auto m20 = conversion_cast<kilogram>(m1);
    auto m21 = conversion_cast<gram>(m1);

    kilometre_sq m30 = 42.0;
    auto m31 = conversion_cast<metre_sq>(m30);
    inv_kilometre_sq m32 = 1.0 / 42.0;
    auto m33 = conversion_cast<inv_metre_sq>(m32);
    auto m34 = 1.0 / m33;
    auto m35 = conversion_cast<inv_kilometre_sq>(m33);

    auto m36 = m30 * 2.0;
    auto m37 = 2.0 * m30;
    auto m38 = m30 / 2.0;
    auto m39 = 2.0 / m30;
    auto m40 = m30 + 2.0;
    auto m41 = 2.0 + m30;
    auto m42 = m30 - 2.0;
    auto m43 = 2.0 - m30;

    auto m50 = -m30;
    auto m51 = +m30;

    static_assert(std::is_same_v<second, s<1>>);
    static_assert(std::is_same_v<second, s<1, double>>);
    static_assert(!std::is_same_v<second, s<1, long double>>);
    static_assert(std::is_same_v<kilogram, kg<1>>);
    static_assert(std::is_same_v<gram, g<1>>);
    static_assert(std::is_same_v<kilometre_sq, km<2>>);
    static_assert(std::is_same_v<kilometre_sq, km_sq>);
    static_assert(std::is_same_v<metre_sq, m<2>>);
    static_assert(std::is_same_v<metre_sq, m_sq>);
    static_assert(std::is_same_v<inv_metre_sq, m<-2>>);
    static_assert(std::is_same_v<inv_metre_sq, inv_m_sq>);
    static_assert(std::is_same_v<inv_kilometre_sq, km<-2>>);
    static_assert(std::is_same_v<inv_kilometre_sq, inv_km_sq>);
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
    static_assert(std::is_same_v<decltype(m30), decltype(m36)>);

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
    test_assert(near_enough(m36, 42.0 * 2.0));
    test_assert(near_enough(m37, 2.0 * 42.0));
    test_assert(near_enough(m38, 42.0 / 2.0));
    test_assert(near_enough(m39, 2.0 / 42.0));
    test_assert(near_enough(m40, 42.0 + 2.0));
    test_assert(near_enough(m41, 2.0 + 42.0));
    test_assert(near_enough(m42, 42.0 - 2.0));
    test_assert(near_enough(m43, 2.0 - 42.0));
    test_assert(near_enough(m50, -42.0));
    test_assert(near_enough(m51, 42.0));
}