// si.hpp
/*
 *  Copyright (c) 2023 Leigh Johnston.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of Leigh Johnston nor the names of any
 *       other contributors to this software may be used to endorse or
 *       promote products derived from this software without specific prior
 *       written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 *  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 *  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <cstdint>

#include <neounit/unit.hpp>

namespace neounit::si
{
    enum class dimension : integer
    {
        Time                = 0,
        Length              = 1,
        Mass                = 2,
        ElectricCurrent     = 3,
        AbsoluteTemperature = 4,
        AmountOfSubstance   = 5,
        LuminousIntensity   = 6,

        T = Time,
        L = Length,
        M = Mass,
        I = ElectricCurrent,
        H = AbsoluteTemperature,
        N = AmountOfSubstance,
        J = LuminousIntensity
    };

    #define s_EXPONENTS(E) E, 0, 0, 0, 0, 0, 0
    #define m_EXPONENTS(E) 0, E, 0, 0, 0, 0, 0
    #define g_EXPONENTS(E) 0, 0, E, 0, 0, 0, 0
    #define A_EXPONENTS(E) 0, 0, 0, E, 0, 0, 0
    #define K_EXPONENTS(E) 0, 0, 0, 0, E, 0, 0
    #define mol_EXPONENTS(E) 0, 0, 0, 0, 0, E, 0
    #define cd_EXPONENTS(E) 0, 0, 0, 0, 0, 0, E

    template<dimensional_exponent E, typename T = double>
    using s = unit<T, dimension, exponents<s_EXPONENTS(E)>, typename ratios<one, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using m = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, one, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using g = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, one, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using A = unit<T, dimension, exponents<A_EXPONENTS(E)>, typename ratios<none, none, none, one, none, none, none>::apply_power_sign_t<A_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using K = unit<T, dimension, exponents<K_EXPONENTS(E)>, typename ratios<none, none, none, none, one, none, none>::apply_power_sign_t<K_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using mol = unit<T, dimension, exponents<mol_EXPONENTS(E)>, typename ratios<none, none, none, none, none, one, none>::apply_power_sign_t<mol_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using cd = unit<T, dimension, exponents<cd_EXPONENTS(E)>, typename ratios<none, none, none, none, none, none, one>::apply_power_sign_t<cd_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _s(long double n) { return unit<double, dimension, exponents<s_EXPONENTS(1)>, ratios<one, none, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _m(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, one, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _g(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, one, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _A(long double n) { return unit<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _K(long double n) { return unit<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, one, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _mol(long double n) { return unit<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, one, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _cd(long double n) { return unit<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, one>>{ static_cast<double>(n) }; }
    }

    using s_sq = s<2>;
    using m_sq = m<2>;
    using g_sq = g<2>;
    using A_sq = A<2>;
    using K_sq = K<2>;
    using mol_sq = mol<2>;
    using cd_sq = cd<2>;

    using inv_s = s<-1>;
    using inv_m = m<-1>;
    using inv_g = g<-1>;
    using inv_A = A<-1>;
    using inv_K = K<-1>;
    using inv_mol = mol<-1>;
    using inv_cd = cd<-1>;

    using inv_s_sq = s<-2>;
    using inv_m_sq = m<-2>;
    using inv_g_sq = g<-2>;
    using inv_A_sq = A<-2>;
    using inv_K_sq = K<-2>;
    using inv_mol_sq = mol<-2>;
    using inv_cd_sq = cd<-2>;

    using second = s<1>;
    using metre = m<1>;
    using gram = g<1>;
    using ampere = A<1>;
    using kelvin = K<1>;
    using mole = mol<1>;
    using candela = cd<1>;

    using second_sq = s<2>;
    using metre_sq = m<2>;
    using gram_sq = g<2>;
    using ampere_sq = A<2>;
    using kelvin_sq = K<2>;
    using mole_sq = mol<2>;
    using candela_sq = cd<2>;

    using inv_second = s<-1>;
    using inv_metre = m<-1>;
    using inv_gram = g<-1>;
    using inv_ampere = A<-1>;
    using inv_kelvin = K<-1>;
    using inv_mole = mol<-1>;
    using inv_candela = cd<-1>;

    using inv_second_sq = s<-2>;
    using inv_metre_sq = m<-2>;
    using inv_gram_sq = g<-2>;
    using inv_ampere_sq = A<-2>;
    using inv_kelvin_sq = K<-2>;
    using inv_mole_sq = mol<-2>;
    using inv_candela_sq = cd<-2>;

    #define define_si_prefix(ShortPrefix, LongPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## s = unit<T, dimension, exponents<s_EXPONENTS(E)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## m = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## g = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## A = unit<T, dimension, exponents<A_EXPONENTS(E)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## K = unit<T, dimension, exponents<K_EXPONENTS(E)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## mol = unit<T, dimension, exponents<mol_EXPONENTS(E)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## cd = unit<T, dimension, exponents<cd_EXPONENTS(E)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(E)>>;\
    using ShortPrefix ## s_sq = unit<double, dimension, exponents<s_EXPONENTS(2)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using ShortPrefix ## m_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using ShortPrefix ## g_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using ShortPrefix ## A_sq = unit<double, dimension, exponents<A_EXPONENTS(2)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using ShortPrefix ## K_sq = unit<double, dimension, exponents<K_EXPONENTS(2)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using ShortPrefix ## mol_sq = unit<double, dimension, exponents<mol_EXPONENTS(2)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using ShortPrefix ## cd_sq = unit<double, dimension, exponents<cd_EXPONENTS(2)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using inv_ ## ShortPrefix ## s = unit<double, dimension, exponents<s_EXPONENTS(-1)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## m = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## g = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## A = unit<double, dimension, exponents<A_EXPONENTS(-1)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## K = unit<double, dimension, exponents<K_EXPONENTS(-1)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## mol = unit<double, dimension, exponents<mol_EXPONENTS(-1)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## cd = unit<double, dimension, exponents<cd_EXPONENTS(-1)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## s_sq = unit<double, dimension, exponents<s_EXPONENTS(-2)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## m_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## g_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## A_sq = unit<double, dimension, exponents<A_EXPONENTS(-2)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## K_sq = unit<double, dimension, exponents<K_EXPONENTS(-2)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## mol_sq = unit<double, dimension, exponents<mol_EXPONENTS(-2)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## cd_sq = unit<double, dimension, exponents<cd_EXPONENTS(-2)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-2)>>;\
    using LongPrefix ## second = unit<double, dimension, exponents<s_EXPONENTS(1)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using LongPrefix ## metre = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using LongPrefix ## gram = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using LongPrefix ## ampere = unit<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using LongPrefix ## kelvin = unit<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using LongPrefix ## mole = unit<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using LongPrefix ## candela = unit<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using LongPrefix ## second_sq = unit<double, dimension, exponents<s_EXPONENTS(2)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using LongPrefix ## metre_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using LongPrefix ## gram_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using LongPrefix ## ampere_sq = unit<double, dimension, exponents<A_EXPONENTS(2)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using LongPrefix ## kelvin_sq = unit<double, dimension, exponents<K_EXPONENTS(2)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using LongPrefix ## mole_sq = unit<double, dimension, exponents<mol_EXPONENTS(2)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using LongPrefix ## candela_sq = unit<double, dimension, exponents<cd_EXPONENTS(2)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using inv_ ## LongPrefix ## second = unit<double, dimension, exponents<s_EXPONENTS(-1)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## metre = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## gram = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## ampere = unit<double, dimension, exponents<A_EXPONENTS(-1)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## kelvin = unit<double, dimension, exponents<K_EXPONENTS(-1)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## mole = unit<double, dimension, exponents<mol_EXPONENTS(-1)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## candela = unit<double, dimension, exponents<cd_EXPONENTS(-1)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-1)>>;\
    using inv_ ## LongPrefix ## second_sq = unit<double, dimension, exponents<s_EXPONENTS(-2)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## metre_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## gram_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## ampere_sq = unit<double, dimension, exponents<A_EXPONENTS(-2)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## kelvin_sq = unit<double, dimension, exponents<K_EXPONENTS(-2)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## mole_sq = unit<double, dimension, exponents<mol_EXPONENTS(-2)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-2)>>;\
    using inv_ ## LongPrefix ## candela_sq = unit<double, dimension, exponents<cd_EXPONENTS(-2)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-2)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## s(long double n) { return unit<double, dimension, exponents<s_EXPONENTS(1)>, ratios<Ratio, none, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## m(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, Ratio, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## g(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, Ratio, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## A(long double n) { return unit<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## K(long double n) { return unit<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, Ratio, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## mol(long double n) { return unit<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, Ratio, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## cd(long double n) { return unit<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, Ratio>>{ static_cast<double>(n) }; }\
    }

    define_si_prefix(a, atto, std::atto)
    define_si_prefix(f, femto, std::femto)
    define_si_prefix(p, pico, std::pico)
    define_si_prefix(n, nano, std::nano)
    define_si_prefix(u, micro, std::micro)
    define_si_prefix(m, milli, std::milli)
    define_si_prefix(c, centi, std::centi)
    define_si_prefix(d, deci, std::deci)
    define_si_prefix(da, deca, std::deca)
    define_si_prefix(h, hecto, std::hecto)
    define_si_prefix(k, kilo, std::kilo)
    define_si_prefix(M, mega, std::mega)
    define_si_prefix(G, giga, std::giga)
    define_si_prefix(T, tera, std::tera)
    define_si_prefix(P, peta, std::peta)
    define_si_prefix(E, exa, std::exa)
}