// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <type_traits>
#include <cmath>
#include <iostream>
#include <neounit/neounit.hpp>
#include <neounit/imperial.hpp>

namespace
{
    void test_assert(bool assertion)
    {
        if (!assertion)
            throw std::logic_error("Test failed");
    }

    bool near_enough(double lhs, double rhs)
    {
        return std::abs(lhs - rhs) < 1e-20;
    }

    bool near_enough(long double lhs, long double rhs)
    {
        return std::abs(lhs - rhs) < 1e-20;
    }
}

//#define STATIC_CHECK_1
//#define STATIC_CHECK_2

int main()
{
    using namespace neounit::si;
    using namespace neounit::si::literals;

    auto d0 = 1.0_us;
    inv_us foo;
    inv_Ms bar;
    auto f0 = 1.0 / d0;
    auto f1 = 10.0_MHz;
    auto d1 = 1.0 / f1;
    auto f2 = 1.0 / d1;
    auto f3 = 1.0 / 10.0_s;

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
#ifdef STATIC_CHECK_1
    gram g1 = 2.0;
    auto bad1 = m0 * g1; // compilation failure if enabled
#endif

    auto l0 = 0.2_km;
    auto l1 = 0.3_km;
    auto l2 = l0 * l1;
    auto l3 = l2;
    km_sq l4 = l2;
    l3 = 42.0;
    auto l5 = l2 * 2.0;
    auto l6 = conversion_cast<km<2>>(l2) * km<2, double>{ 1.0 };

    using cm_per_s = decltype(cm<1>{} / s<1>{});
    cm_per_s v1 = 1.0;
    using m_per_s = decltype(m<1>{} / s<1>{});
    auto v2 = conversion_cast<m_per_s>(v1);
#ifdef STATIC_CHECK_2
    auto bad2 = v1 + v2; // compilation failure if enabled
#endif

    auto m20 = conversion_cast<kilogram>(m1);
    auto m21 = conversion_cast<gram>(m1);

    kilometre_sq m30 = 42.0;
    auto m31 = conversion_cast<metre_sq>(m30);
    inv_kilometre_sq m32 = 1.0 / m30;
    auto m33 = conversion_cast<inv_metre_sq>(m32);
    auto m34 = conversion_cast<inv_kilometre_sq>(m33);
    auto m35 = 1.0 / m34;

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

    auto p1 = 100.0_V;
    auto p2 = 7.0_mV;
    milliampere a1;
    millivolt p3 = p2;
    auto r1 = p1 / conversion_cast<ampere>(42.0_mA);
    auto r2 = p2 / conversion_cast<milliampere>(0.007_A);

    static_assert(std::is_same_v<second, s<1>>);
    static_assert(std::is_same_v<second, s<1, double>>);
    static_assert(!std::is_same_v<second, s<1, long double>>);
    static_assert(std::is_same_v<decltype(1.0 / 1.0_us), inv_us>);
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
    static_assert(std::is_same_v<decltype(f1), megahertz>);
    static_assert(std::is_same_v<decltype(d1), microsecond>);
    static_assert(std::is_same_v<decltype(f2), megahertz>);
    static_assert(std::is_same_v<decltype(f3), hertz>);
    static_assert(std::is_same_v<decltype(m5), kilogram_sq>);
    static_assert(std::is_same_v<decltype(m6), double>);
    static_assert(std::is_same_v<decltype(m7), kilogram>);
    static_assert(std::is_same_v<decltype(m8), double>);
    static_assert(std::is_same_v<decltype(m9), double>);
    static_assert(std::is_same_v<decltype(m10), inv_kilogram>);
    static_assert(std::is_same_v<decltype(m11), inv_kilogram_sq>);
    static_assert(std::is_same_v<decltype(m12), inv_kilogram_sq>);
    static_assert(std::is_same_v<decltype(l0), km<1, double>>);
    static_assert(std::is_same_v<decltype(l1), km<1, double>>);
    static_assert(std::is_same_v<decltype(l2), km<2, double>>);
    static_assert(std::is_same_v<decltype(l3), km<2, double>>);
    static_assert(std::is_same_v<decltype(l4), km<2, double>>);
    static_assert(std::is_same_v<decltype(l5), km<2, double>>);
    static_assert(std::is_same_v<decltype(l6), km<4, double>>);
    static_assert(std::is_same_v<decltype(m20), kilogram>);
    static_assert(std::is_same_v<decltype(m21), gram>);
    static_assert(std::is_same_v<decltype(m31), metre_sq>);
    static_assert(std::is_same_v<decltype(m33), inv_metre_sq>);
    static_assert(std::is_same_v<decltype(m34), inv_kilometre_sq>);
    static_assert(std::is_same_v<decltype(m35), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m36), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m37), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m38), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m39), inv_kilometre_sq>);
    static_assert(std::is_same_v<decltype(m40), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m41), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m42), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m43), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m50), kilometre_sq>);
    static_assert(std::is_same_v<decltype(m51), kilometre_sq>);
    static_assert(std::is_same_v<decltype(p1), volt>);
    static_assert(std::is_same_v<decltype(p2), millivolt>);
    static_assert(std::is_same_v<decltype(r1), ohm>);

    static_assert(std::is_same_v<decltype(1.0 / 1.0_s), hertz>);
    static_assert(std::is_same_v<decltype(1.0 / 1.0_Hz), second>);
    static_assert(std::is_same_v<decltype(1.0 / 1.0_us), megahertz>);
    static_assert(std::is_same_v<decltype(1.0 / 1.0_MHz), microsecond>);

    test_assert(near_enough(d1, 0.1_s));
    test_assert(near_enough(f2, 10.0_MHz));
    test_assert(near_enough(f3, 0.1_MHz));
    test_assert(m0 == 0.0);
    test_assert(0.0 == m0);
    test_assert(near_enough(m4, m1));
    test_assert(near_enough(m5, 7.0 * 42.0));
    test_assert(near_enough(m6, 7.0 / 42.0));
    test_assert(m5 != 0.0);
    test_assert(0.0 != m5);
    test_assert(near_enough(m11, m12));
    test_assert(near_enough(l0, 0.2));
    test_assert(near_enough(l1, 0.3));
    test_assert(near_enough(l2, 0.06));
    test_assert(near_enough(l3, 42.0));
    test_assert(near_enough(l4, 0.06));
    test_assert(near_enough(l5, 0.12));
    test_assert(near_enough(l6, 0.06));
    test_assert(near_enough(v1, 1.0));
    test_assert(near_enough(v2, 0.01));
    test_assert(m20 == m1);
    test_assert(near_enough(m21, 7000.0));
    test_assert(near_enough(m30, 42.0));
    test_assert(near_enough(m31, 42000000.0));
    test_assert(near_enough(m32, 1.0 / 42.0));
    test_assert(near_enough(m33, 1.0 / 42000000.0));
    test_assert(near_enough(m34, 1.0 / 42.0));
    test_assert(near_enough(m35, 42.0));
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
    test_assert(near_enough(p1, 100.0));
    test_assert(near_enough(r1, 100.0 / 0.042));
    test_assert(near_enough(r2, 1.0));

    // imperial, just for fun. where's my pint?

    using namespace neounit::imperial;
    using namespace neounit::imperial::literals;

    inch imperialLength = 42.0;
    auto metricLength = conversion_cast<centimetre>(imperialLength);
    test_assert(near_enough(metricLength, 106.68));
    auto lol = conversion_cast<picoinch>(imperialLength);
    auto lol2 = conversion_cast<nanoinch>(lol);
    auto lol3 = conversion_cast<kilofoot>(lol2);
    test_assert(near_enough(lol, 42e12));
    test_assert(near_enough(lol2, 42e9));
    test_assert(near_enough(lol3, 42e9 / 1e9 / 1e3 / 12.0));
    auto imperialLength2 = conversion_cast<foot>(imperialLength);
    test_assert(near_enough(imperialLength2, imperialLength / 12.0));
    auto oneMile = 1.0_mi;
    auto oneKilometre = 1.0_km;
    test_assert(near_enough(conversion_cast<kilometre>(oneMile) / oneKilometre, 1.609344));
    test_assert(near_enough(conversion_cast<centimetre>(1.0_ft), 12 * 2.54));
    auto fiveYards = 5.0_yd;
    test_assert(near_enough(conversion_cast<picometre>(fiveYards), 4.572e12));
    auto nineYards = fiveYards * 9.0 / 5.0;
    test_assert(near_enough(conversion_cast<nanometre>(nineYards), 8.2296e9));
}