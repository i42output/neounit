﻿// si_other.hpp
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

namespace neounit::si
{
    // s m g A K mol cd

    #define h_EXPONENTS 1, 0, 0, 0, 0, 0, 0
    #define t_EXPONENTS 0, 0, 1, 0, 0, 0, 0

    template<typename T = double> using h = scalar<T, dimension, exponents<h_EXPONENTS>, ratios<ratio<60 * 60>, none, none, none, none, none, none>>;
    template<typename T = double> using t = scalar<T, dimension, exponents<t_EXPONENTS>, ratios<none, none, mega, none, none, none, none>>;

    using hour = h<>;
    using tonne = t<>;
    using ton = tonne;

    namespace literals
    {
        inline auto operator "" _h(long double n) { return scalar<double, dimension, exponents<h_EXPONENTS>, ratios<ratio<60 * 60>, none, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _t(long double n) { return scalar<double, dimension, exponents<t_EXPONENTS>, ratios<none, none, mega, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    template <dimensional_exponent E> struct base_unit_pre_exponent_to_string<dimension::Time, E, ratio<60 * 60>> { static inline auto const value = std::string{ ratio_short_prefix<apply_power_sign_t<ratio<60 * 60>, E>>::prefix } + "h"; };
    template <dimensional_exponent E> struct base_unit_pre_exponent_to_u8string<dimension::Time, E, ratio<60 * 60>> { static inline auto const value = std::u8string{ ratio_short_u8prefix<apply_power_sign_t<ratio<60 * 60>, E>>::prefix } + u8"h"; };

    #define define_si_other_prefix(ShortPrefix, Ratio)\
    template <dimensional_exponent E> struct base_unit_pre_exponent_to_string<dimension::Time, E, ratio_multiply<ratio<60 * 60>, Ratio>> { static inline auto const value = std::string{ ratio_short_prefix<apply_power_sign_t<Ratio, E>>::prefix } + "h"; };\
    template <dimensional_exponent E> struct base_unit_pre_exponent_to_u8string<dimension::Time, E, ratio_multiply<ratio<60 * 60>, Ratio>> { static inline auto const value = std::u8string{ ratio_short_u8prefix<apply_power_sign_t<Ratio, E>>::prefix } + u8"h"; };\
    using ShortPrefix ## hour = scalar<double, dimension, exponents<h_EXPONENTS>, ratios<ratio_multiply<ratio<60 * 60>, Ratio>, none, none, none, none, none, none>>;\
    using ShortPrefix ## t = scalar<double, dimension, exponents<t_EXPONENTS>, ratios<none, none, ratio_multiply<mega, Ratio>, none, none, none, none>>;\
    using Ratio ## hour = scalar<double, dimension, exponents<h_EXPONENTS>, ratios<ratio_multiply<ratio<60 * 60>, Ratio>, none, none, none, none, none, none>>;\
    using Ratio ## tonne = scalar<double, dimension, exponents<t_EXPONENTS>, ratios<none, none, ratio_multiply<mega, Ratio>, none, none, none, none>>;\
    using Ratio ## ton = scalar<double, dimension, exponents<t_EXPONENTS>, ratios<none, none, ratio_multiply<mega, Ratio>, none, none, none, none>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## h(long double n) { return scalar<double, dimension, exponents<h_EXPONENTS>, ratios<ratio_multiply<ratio<60 * 60>, Ratio>, none, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## t(long double n) { return scalar<double, dimension, exponents<t_EXPONENTS>, ratios<none, none, ratio_multiply<mega, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
    }

    define_si_other_prefix(q, quecto)
    define_si_other_prefix(r, ronto)
    define_si_other_prefix(y, yocto)
    define_si_other_prefix(z, zepto)
    define_si_other_prefix(a, atto)
    define_si_other_prefix(f, femto)
    define_si_other_prefix(p, pico)
    define_si_other_prefix(n, nano)
    define_si_other_prefix(u, micro)
    define_si_other_prefix(m, milli)
    define_si_other_prefix(c, centi)
    define_si_other_prefix(d, deci)
    define_si_other_prefix(da, deca)
    define_si_other_prefix(h, hecto)
    define_si_other_prefix(k, kilo)
    define_si_other_prefix(M, mega)
    define_si_other_prefix(G, giga)
    define_si_other_prefix(T, tera)
    define_si_other_prefix(P, peta)
    define_si_other_prefix(E, exa)
    define_si_other_prefix(Z, zetta)
    define_si_other_prefix(Y, yotta)
    define_si_other_prefix(R, ronna)
    define_si_other_prefix(Q, quetta)
}