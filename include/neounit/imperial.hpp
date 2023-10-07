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
    using in = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<254, 10000>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using ft = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<254 * 12, 10000>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using yd = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<254 * 12 * 3, 10000>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using mi = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<1609344, 1000>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _ft(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254 * 12, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _yd(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254 * 12 * 3, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _mi(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<1609344, 1000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    using in_sq = in<2>;
    using ft_sq = ft<2>;
    using yd_sq = yd<2>;
    using mi_sq = mi<2>;
    using inv_in = in<-1>;
    using inv_ft = ft<-1>;
    using inv_yd = yd<-1>;
    using inv_mi = mi<-1>;
    using inv_in_sq = in<-2>;
    using inv_ft_sq = ft<-2>;
    using inv_yd_sq = yd<-2>;
    using inv_mi_sq = mi<-2>;
    using inch = in<1>;
    using foot = ft<1>;
    using yard = yd<1>;
    using mile = mi<1>;
    using inch_sq = in<2>;
    using foot_sq = ft<2>;
    using yard_sq = yd<2>;
    using mile_sq = mi<2>;
    using inv_inch = in<-1>;
    using inv_foot = ft<-1>;
    using inv_yard = yd<-1>;
    using inv_mile = mi<-1>;
    using inv_inch_sq = in<-2>;
    using inv_foot_sq = ft<-2>;
    using inv_yard_sq = yd<-2>;
    using inv_mile_sq = mi<-2>;

    #define define_imperial_prefix(ShortPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## in = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## ft = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## yd = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## mi = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    using ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## ft_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## yd_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## mi_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## ShortPrefix ## in = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## ft = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## yd = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## mi = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<21609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## ft_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## yd_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## mi_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using Ratio ## inch = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## foot = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## yard = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## mile = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## Ratio ## inch = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## foot = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## yard = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## mile = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## ft(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## yd(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## mi(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
    }

    define_imperial_prefix(q, quecto)
    define_imperial_prefix(r, ronto)
    define_imperial_prefix(y, yocto)
    define_imperial_prefix(z, zepto)
    define_imperial_prefix(a, atto)
    define_imperial_prefix(f, femto)
    define_imperial_prefix(p, pico)
    define_imperial_prefix(n, nano)
    define_imperial_prefix(u, micro)
    define_imperial_prefix(m, milli)
    define_imperial_prefix(c, centi)
    define_imperial_prefix(d, deci)
    define_imperial_prefix(da, deca)
    define_imperial_prefix(h, hecto)
    define_imperial_prefix(k, kilo)
    define_imperial_prefix(M, mega)
    define_imperial_prefix(G, giga)
    define_imperial_prefix(T, tera)
    define_imperial_prefix(P, peta)
    define_imperial_prefix(E, exa)
    define_imperial_prefix(Z, zetta)
    define_imperial_prefix(Y, yotta)
    define_imperial_prefix(R, ronna)
    define_imperial_prefix(Q, quetta)
}