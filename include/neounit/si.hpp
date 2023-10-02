// neounit.hpp
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

    template<dimensional_exponent E>
    using s = unit<double, dimension, exponents<E, 0, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using m = unit<double, dimension, exponents<0, E, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using g = unit<double, dimension, exponents<0, 0, E, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using A = unit<double, dimension, exponents<0, 0, 0, E, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using K = unit<double, dimension, exponents<0, 0, 0, 0, E, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using mol = unit<double, dimension, exponents<0, 0, 0, 0, 0, E, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    template<dimensional_exponent E>
    using cd = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, E>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;

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
    template<dimensional_exponent E>\
    using ShortPrefix ## s = unit<double, dimension, exponents<E, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## m = unit<double, dimension, exponents<0, E, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## g = unit<double, dimension, exponents<0, 0, E, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## A = unit<double, dimension, exponents<0, 0, 0, E, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## K = unit<double, dimension, exponents<0, 0, 0, 0, E, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## mol = unit<double, dimension, exponents<0, 0, 0, 0, 0, E, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    template<dimensional_exponent E>\
    using ShortPrefix ## cd = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, E>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using ShortPrefix ## s_sq = unit<double, dimension, exponents<2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using ShortPrefix ## m_sq = unit<double, dimension, exponents<0, 2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using ShortPrefix ## g_sq = unit<double, dimension, exponents<0, 0, 2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using ShortPrefix ## A_sq = unit<double, dimension, exponents<0, 0, 0, 2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using ShortPrefix ## K_sq = unit<double, dimension, exponents<0, 0, 0, 0, 2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using ShortPrefix ## mol_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using ShortPrefix ## cd_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using inv_ ## ShortPrefix ## s = unit<double, dimension, exponents<-1, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## m = unit<double, dimension, exponents<0, -1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## g = unit<double, dimension, exponents<0, 0, -1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## A = unit<double, dimension, exponents<0, 0, 0, -1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## K = unit<double, dimension, exponents<0, 0, 0, 0, -1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## mol = unit<double, dimension, exponents<0, 0, 0, 0, 0, -1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## cd = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using inv_ ## ShortPrefix ## s_sq = unit<double, dimension, exponents<-2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## m_sq = unit<double, dimension, exponents<0, -2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## g_sq = unit<double, dimension, exponents<0, 0, -2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## A_sq = unit<double, dimension, exponents<0, 0, 0, -2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## K_sq = unit<double, dimension, exponents<0, 0, 0, 0, -2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## mol_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, -2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## ShortPrefix ## cd_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using LongPrefix ## second = unit<double, dimension, exponents<1, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## metre = unit<double, dimension, exponents<0, 1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## gram = unit<double, dimension, exponents<0, 0, 1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## ampere = unit<double, dimension, exponents<0, 0, 0, 1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## kelvin = unit<double, dimension, exponents<0, 0, 0, 0, 1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, 1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using LongPrefix ## candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using LongPrefix ## second_sq = unit<double, dimension, exponents<2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## metre_sq = unit<double, dimension, exponents<0, 2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## gram_sq = unit<double, dimension, exponents<0, 0, 2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## ampere_sq = unit<double, dimension, exponents<0, 0, 0, 2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, 2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using LongPrefix ## mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using LongPrefix ## candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using inv_ ## LongPrefix ## second = unit<double, dimension, exponents<-1, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## metre = unit<double, dimension, exponents<0, -1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## gram = unit<double, dimension, exponents<0, 0, -1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## ampere = unit<double, dimension, exponents<0, 0, 0, -1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## kelvin = unit<double, dimension, exponents<0, 0, 0, 0, -1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, -1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    using inv_ ## LongPrefix ## second_sq = unit<double, dimension, exponents<-2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## metre_sq = unit<double, dimension, exponents<0, -2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## gram_sq = unit<double, dimension, exponents<0, 0, -2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## ampere_sq = unit<double, dimension, exponents<0, 0, 0, -2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, -2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, -2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## LongPrefix ## candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;

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