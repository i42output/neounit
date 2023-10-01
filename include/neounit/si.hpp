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

    using second = unit<double, dimension, exponents<1, 0, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using metre = unit<double, dimension, exponents<0, 1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using gram = unit<double, dimension, exponents<0, 0, 1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using ampere = unit<double, dimension, exponents<0, 0, 0, 1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using kelvin = unit<double, dimension, exponents<0, 0, 0, 0, 1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, 1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;

    using second_sq = unit<double, dimension, exponents<2, 0, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using metre_sq = unit<double, dimension, exponents<0, 2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using gram_sq = unit<double, dimension, exponents<0, 0, 2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using ampere_sq = unit<double, dimension, exponents<0, 0, 0, 2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, 2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;

    using inv_second = unit<double, dimension, exponents<-1, 0, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_metre = unit<double, dimension, exponents<0, -1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_gram = unit<double, dimension, exponents<0, 0, -1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_ampere = unit<double, dimension, exponents<0, 0, 0, -1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_kelvin = unit<double, dimension, exponents<0, 0, 0, 0, -1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, -1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;

    using inv_second_sq = unit<double, dimension, exponents<-2, 0, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_metre_sq = unit<double, dimension, exponents<0, -2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_gram_sq = unit<double, dimension, exponents<0, 0, -2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_ampere_sq = unit<double, dimension, exponents<0, 0, 0, -2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, -2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, -2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;
    using inv_candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;

    #define define_si_prefix(Prefix, Ratio)\
    using Prefix ## second = unit<double, dimension, exponents<1, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## metre = unit<double, dimension, exponents<0, 1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## gram = unit<double, dimension, exponents<0, 0, 1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## ampere = unit<double, dimension, exponents<0, 0, 0, 1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## kelvin = unit<double, dimension, exponents<0, 0, 0, 0, 1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, 1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using Prefix ## candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    \
    using Prefix ## second_sq = unit<double, dimension, exponents<2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## metre_sq = unit<double, dimension, exponents<0, 2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## gram_sq = unit<double, dimension, exponents<0, 0, 2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## ampere_sq = unit<double, dimension, exponents<0, 0, 0, 2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, 2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using Prefix ## mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using Prefix ## candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, 2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    \
    using inv_ ## Prefix ## second = unit<double, dimension, exponents<-1, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## metre = unit<double, dimension, exponents<0, -1, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## gram = unit<double, dimension, exponents<0, 0, -1, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## ampere = unit<double, dimension, exponents<0, 0, 0, -1, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## kelvin = unit<double, dimension, exponents<0, 0, 0, 0, -1, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## mole = unit<double, dimension, exponents<0, 0, 0, 0, 0, -1, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## Prefix ## candela = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -1>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;\
    \
    using inv_ ## Prefix ## second_sq = unit<double, dimension, exponents<-2, 0, 0, 0, 0, 0, 0>, ratios<Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## metre_sq = unit<double, dimension, exponents<0, -2, 0, 0, 0, 0, 0>, ratios<std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## gram_sq = unit<double, dimension, exponents<0, 0, -2, 0, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## ampere_sq = unit<double, dimension, exponents<0, 0, 0, -2, 0, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## kelvin_sq = unit<double, dimension, exponents<0, 0, 0, 0, -2, 0, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>, std::ratio<1>>>;\
    using inv_ ## Prefix ## mole_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, -2, 0>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio, std::ratio<1>>>;\
    using inv_ ## Prefix ## candela_sq = unit<double, dimension, exponents<0, 0, 0, 0, 0, 0, -2>, ratios<std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, std::ratio<1>, Ratio>>;

    define_si_prefix(atto, std::atto)
    define_si_prefix(femto, std::femto)
    define_si_prefix(pico, std::pico)
    define_si_prefix(nano, std::nano)
    define_si_prefix(micro, std::micro)
    define_si_prefix(milli, std::milli)
    define_si_prefix(centi, std::centi)
    define_si_prefix(deci, std::deci)
    define_si_prefix(deca, std::deca)
    define_si_prefix(hecto, std::hecto)
    define_si_prefix(kilo, std::kilo)
    define_si_prefix(mega, std::mega)
    define_si_prefix(giga, std::giga)
    define_si_prefix(tera, std::tera)
    define_si_prefix(peta, std::peta)
    define_si_prefix(exa, std::exa)
}