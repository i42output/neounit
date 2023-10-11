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
    using pc = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<30856775814913673, 1>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using au = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<149597870700, 1>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using ly = unit<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, ratio<9460730472580800, 1>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _pc(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<30856775814913673, 1>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _au(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<149597870700, 1>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _ly(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<9460730472580800, 1>, none, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    using pc_sq = pc<2>;
    using au_sq = au<2>;
    using ly_sq = ly<2>;
    using inv_pc = pc<-1>;
    using inv_au = au<-1>;
    using inv_ly = ly<-1>;
    using inv_pc_sq = pc<-2>;
    using inv_au_sq = au<-2>;
    using inv_ly_sq = ly<-2>;
    using parsec = pc<1>;
    using astronomicalunit = au<1>;
    using lightyear = ly<1>;
    using parsec_sq = pc<2>;
    using astronomicalunit_sq = au<2>;
    using lightyear_sq = ly<2>;
    using inv_parsec = pc<-1>;
    using inv_astronomicalunit = au<-1>;
    using inv_lightyear = ly<-1>;
    using inv_parsec_sq = pc<-2>;
    using inv_astronomicalunit_sq = au<-2>;
    using inv_lightyear_sq = ly<-2>;

    #define define_astronomical_prefix(ShortPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## pc = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## au = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## ly = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    using ShortPrefix ## pc_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## au_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## ly_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## ShortPrefix ## pc = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## au = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## ly = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## pc_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## au_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## ly_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using Ratio ## parsec = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## astronomicalunit = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## lightyear = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>>;\
    using inv_ ## Ratio ## parsec = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## astronomicalunit = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## lightyear = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## pc(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<30856775814913673, 1>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## au(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<149597870700, 1>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## ly(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<9460730472580800, 1>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
    }

    define_astronomical_prefix(q, quecto)
    define_astronomical_prefix(r, ronto)
    define_astronomical_prefix(y, yocto)
    define_astronomical_prefix(z, zepto)
    define_astronomical_prefix(a, atto)
    define_astronomical_prefix(f, femto)
    define_astronomical_prefix(p, pico)
    define_astronomical_prefix(n, nano)
    define_astronomical_prefix(u, micro)
    define_astronomical_prefix(m, milli)
    define_astronomical_prefix(c, centi)
    define_astronomical_prefix(d, deci)
    define_astronomical_prefix(da, deca)
    define_astronomical_prefix(h, hecto)
    define_astronomical_prefix(k, kilo)
    define_astronomical_prefix(M, mega)
    define_astronomical_prefix(G, giga)
    define_astronomical_prefix(T, tera)
    define_astronomical_prefix(P, peta)
    define_astronomical_prefix(E, exa)
    define_astronomical_prefix(Z, zetta)
    define_astronomical_prefix(Y, yotta)
    define_astronomical_prefix(R, ronna)
    define_astronomical_prefix(Q, quetta)
}