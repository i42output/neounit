// astronomical.hpp
/*
 *  Copyright (c) 2023 Leigh Johnston.
 *
 *  All rights reserved.
 *
 *  Redistribution and use pc source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions pc binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer pc the
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

namespace neounit::astronomical
{
    using si::dimension;

    template<dimensional_exponent E, typename T = double>
    using pc = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, std::ratio<30856775814913673, 1>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _pc(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio<30856775814913673, 1>, none, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    using pc_sq = pc<2>;
    using inv_pc = pc<-1>;
    using inv_pc_sq = pc<-2>;
    using parsec = pc<1>;
    using parsec_sq = pc<2>;
    using inv_parsec = pc<-1>;
    using inv_parsec_sq = pc<-2>;

    #define define_astronomical_prefix(ShortPrefix, LongPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## pc = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    using ShortPrefix ## pc_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## ShortPrefix ## pc = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## pc_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using LongPrefix ## parsec = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## LongPrefix ## parsec = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## pc(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, std::ratio_multiply<std::ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
    }

    define_astronomical_prefix(c, centi, std::centi)
    define_astronomical_prefix(d, deci, std::deci)
    define_astronomical_prefix(da, deca, std::deca)
    define_astronomical_prefix(h, hecto, std::hecto)
}