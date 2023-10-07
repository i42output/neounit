// imperial.hpp
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
#include <neounit/si.hpp>

namespace neounit::imperial
{
    using si::dimension;

    template<dimensional_exponent E, typename T = double>
    using in = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, std::ratio<254, 10000>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio<254, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    using in_sq = in<2>;
    using inv_in = in<-1>;
    using inv_in_sq = in<-2>;
    using inch = in<1>;
    using inch_sq = in<2>;
    using inv_inch = in<-1>;
    using inv_inch_sq = in<-2>;

    #define define_imperial_prefix(ShortPrefix, LongPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## in = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    using ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## ShortPrefix ## in = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using LongPrefix ## inch = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## LongPrefix ## inch = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio_multiply<std::ratio<254, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
    }

    define_imperial_prefix(f, femto, std::femto)
    define_imperial_prefix(p, pico, std::pico)
    define_imperial_prefix(n, nano, std::nano)
    define_imperial_prefix(u, micro, std::micro)
    define_imperial_prefix(m, milli, std::milli)
    define_imperial_prefix(c, centi, std::centi)
    define_imperial_prefix(d, deci, std::deci)
    define_imperial_prefix(da, deca, std::deca)
    define_imperial_prefix(h, hecto, std::hecto)
    define_imperial_prefix(k, kilo, std::kilo)
    define_imperial_prefix(M, mega, std::mega)
    define_imperial_prefix(G, giga, std::giga)
    define_imperial_prefix(T, tera, std::tera)
    define_imperial_prefix(P, peta, std::peta)
    define_imperial_prefix(E, exa, std::exa)
}