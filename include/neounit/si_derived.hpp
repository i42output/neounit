// si_derived.hpp
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

    #define Hz_EXPONENTS -1, 0, 0, 0, 0, 0, 0
    #define N_EXPONENTS -2, 1, 1, 0, 0, 0, 0
    #define Pa_EXPONENTS -2, -1, 1, 0, 0, 0, 0
    #define J_EXPONENTS -2, 2, 1, 0, 0, 0, 0
    #define W_EXPONENTS -3, 2, 1, 0, 0, 0, 0
    #define C_EXPONENTS 1, 0, 0, 1, 0, 0, 0
    #define V_EXPONENTS -3, 2, 1, -1, 0, 0, 0
    #define F_EXPONENTS 4, -2, -1, 2, 0, 0, 0
    #define Ω_EXPONENTS -3, 2, 1, -2, 0, 0, 0
    #define S_EXPONENTS 3, -2, -1, 2, 0, 0, 0
    #define Wb_EXPONENTS -2, 2, 1, -1, 0, 0, 0
    #define T_EXPONENTS -2, 0, 1, -1, 0, 0, 0
    #define H_EXPONENTS -2, 2, 1, -2, 0, 0, 0
    #define degC_EXPONENTS 0, 0, 0, 0, 1, 0, 0
    #define lm_EXPONENTS 0, 0, 0, 0, 0, 0, 1
    #define lx_EXPONENTS 0, -2, 0, 0, 0, 0, 1
    #define Bq_EXPONENTS -1, 0, 0, 0, 0, 0, 0
    #define Gy_EXPONENTS -2, 2, 0, 0, 0, 0, 0
    #define Sv_EXPONENTS -2, 2, 0, 0, 0, 0, 0
    #define kat_EXPONENTS -1, 0, 0, 0, 0, 1, 0

    template<typename T = double>
    using Hz = scalar<T, dimension, exponents<Hz_EXPONENTS>, ratios<one, none, none, none, none, none, none>>;
    template<typename T = double>
    using rad = T;
    template<typename T = double>
    using sr = T;
    template<typename T = double>
    using N = scalar<T, dimension, exponents<N_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>;
    template<typename T = double>
    using Pa = scalar<T, dimension, exponents<Pa_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>;
    template<typename T = double>
    using J = scalar<T, dimension, exponents<J_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>;
    template<typename T = double>
    using W = scalar<T, dimension, exponents<W_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>;
    template<typename T = double>
    using C = scalar<T, dimension, exponents<C_EXPONENTS>, ratios<one, none, none, one, none, none, none>>;
    template<typename T = double>
    using V = scalar<T, dimension, exponents<V_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T = double>
    using F = scalar<T, dimension, exponents<F_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T = double>
    using Ω = scalar<T, dimension, exponents<Ω_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T = double>
    using S = scalar<T, dimension, exponents<S_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T = double>
    using Wb = scalar<T, dimension, exponents<Wb_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T_ = double>
    using T = scalar<T_, dimension, exponents<T_EXPONENTS>, ratios<one, none, kilo, one, none, none, none>>;
    template<typename T = double>
    using H = scalar<T, dimension, exponents<H_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>;
    template<typename T = double>
    using degC = scalar<T, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, one, none, none>>;
    template<typename T = double>
    using lm = scalar<T, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, one>>;
    template<typename T = double>
    using lx = scalar<T, dimension, exponents<lx_EXPONENTS>, ratios<none, one, none, none, none, none, one>>;
    template<typename T = double>
    using Bq = scalar<T, dimension, exponents<Bq_EXPONENTS>, ratios<one, none, none, none, none, none, none>>;
    template<typename T = double>
    using Gy  = scalar<T, dimension, exponents<Gy_EXPONENTS>, ratios<one, one, none, none, none, none, none>>;
    template<typename T = double>
    using Sv = scalar<T, dimension, exponents<Sv_EXPONENTS>, ratios<one, one, none, none, none, none, none>>;
    template<typename T = double>
    using kat = scalar<T, dimension, exponents<kat_EXPONENTS>, ratios<one, none, none, none, none, one, none>>;

    using hertz = Hz<>;
    using radian = rad<>;
    using steradian = sr<>;
    using newton = N<>;
    using pascal = Pa<>;
    using joule = J<>;
    using watt = W<>;
    using coulomb = C<>;
    using volt = V<>;
    using farad = F<>;
    using ohm = Ω<>;
    using siemens = S<>;
    using weber = Wb<>;
    using tesla = T<>;
    using henry = H<>;
    using Celsius = degC<>;
    using lumen = lm<>;
    using lux = lx<>;
    using becquerel = Bq<>;
    using gray = Gy<>;
    using sievert = Sv<>;
    using katal = kat<>;

    namespace literals
    {
        inline auto operator "" _Hz(long double n) { return scalar<double, dimension, exponents<Hz_EXPONENTS>, ratios<one, none, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _rad(long double n) { return static_cast<double>(n); }
        inline auto operator "" _sr(long double n) { return static_cast<double>(n); }
        inline auto operator "" _N(long double n) { return scalar<double, dimension, exponents<N_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _Pa(long double n) { return scalar<double, dimension, exponents<Pa_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _J(long double n) { return scalar<double, dimension, exponents<J_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _W(long double n) { return scalar<double, dimension, exponents<W_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _C(long double n) { return scalar<double, dimension, exponents<C_EXPONENTS>, ratios<one, none, none, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _V(long double n) { return scalar<double, dimension, exponents<V_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _F(long double n) { return scalar<double, dimension, exponents<F_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _Ω(long double n) { return scalar<double, dimension, exponents<Ω_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _S(long double n) { return scalar<double, dimension, exponents<S_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _Wb(long double n) { return scalar<double, dimension, exponents<Wb_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _T(long double n) { return scalar<double, dimension, exponents<T_EXPONENTS>, ratios<one, none, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _H(long double n) { return scalar<double, dimension, exponents<H_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _degC(long double n) { return scalar<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, one, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _lm(long double n) { return scalar<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, one>>{ static_cast<double>(n) }; }
        inline auto operator "" _lx(long double n) { return scalar<double, dimension, exponents<lx_EXPONENTS>, ratios<none, one, none, none, none, none, one>>{ static_cast<double>(n) }; }
        inline auto operator "" _Bq(long double n) { return scalar<double, dimension, exponents<Bq_EXPONENTS>, ratios<one, none, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _Gy(long double n) { return scalar<double, dimension, exponents<Gy_EXPONENTS>, ratios<one, one, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _Sv(long double n) { return scalar<double, dimension, exponents<Sv_EXPONENTS>, ratios<one, one, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _kat(long double n) { return scalar<double, dimension, exponents<kat_EXPONENTS>, ratios<one, none, none, none, none, one, none>>{ static_cast<double>(n) }; }
    }

    #define define_si_derived_prefix(ShortPrefix, Ratio)\
    using ShortPrefix ## Hz = scalar<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>;\
    using ShortPrefix ## N = scalar<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## Pa = scalar<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## J = scalar<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## W = scalar<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## C = scalar<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>>;\
    using ShortPrefix ## V = scalar<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## F = scalar<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## Ω = scalar<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## S = scalar<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## Wb = scalar<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## T = scalar<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## H = scalar<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using ShortPrefix ## degC = scalar<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>>;\
    using ShortPrefix ## lm = scalar<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>>;\
    using ShortPrefix ## lx = scalar<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>>;\
    using ShortPrefix ## Bq = scalar<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>;\
    using ShortPrefix ## Gy = scalar<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>;\
    using ShortPrefix ## Sv = scalar<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>;\
    using ShortPrefix ## kat = scalar<double, dimension, exponents<kat_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>>;\
    using Ratio ## hertz = scalar<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>;\
    using Ratio ## newton = scalar<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using Ratio ## pascal = scalar<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using Ratio ## joule = scalar<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using Ratio ## watt = scalar<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>;\
    using Ratio ## coulomb = scalar<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>>;\
    using Ratio ## volt = scalar<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## farad = scalar<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## ohm = scalar<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## siemens = scalar<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## weber = scalar<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## tesla = scalar<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## henry = scalar<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>;\
    using Ratio ## Celsius = scalar<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>>;\
    using Ratio ## lumen = scalar<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>>;\
    using Ratio ## lux = scalar<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>>;\
    using Ratio ## becquerel = scalar<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>;\
    using Ratio ## gray = scalar<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>;\
    using Ratio ## sievert = scalar<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>;\
    using Ratio ## katal = scalar<double, dimension, exponents<kat_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## Hz(long double n) { return scalar<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## N(long double n) { return scalar<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Pa(long double n) { return scalar<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## J(long double n) { return scalar<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## W(long double n) { return scalar<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## C(long double n) { return scalar<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## V(long double n) { return scalar<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## F(long double n) { return scalar<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Ω(long double n) { return scalar<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## S(long double n) { return scalar<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Wb(long double n) { return scalar<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## T(long double n) { return scalar<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## H(long double n) { return scalar<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, ratio_multiply<kilo, Ratio>, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## degC(long double n) { return scalar<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## lm(long double n) { return scalar<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## lx(long double n) { return scalar<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Bq(long double n) { return scalar<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Gy(long double n) { return scalar<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Sv(long double n) { return scalar<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## kat(long double n) { return scalar<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>>{ static_cast<double>(n) }; }\
    }

    // Visual Studio hack
    #ifdef _MT
    #define MT_ _MT
    #undef _MT
    #endif

    define_si_derived_prefix(q, quecto)
    define_si_derived_prefix(r, ronto)
    define_si_derived_prefix(y, yocto)
    define_si_derived_prefix(z, zepto)
    define_si_derived_prefix(a, atto)
    define_si_derived_prefix(f, femto)
    define_si_derived_prefix(p, pico)
    define_si_derived_prefix(n, nano)
    define_si_derived_prefix(u, micro)
    define_si_derived_prefix(m, milli)
    define_si_derived_prefix(c, centi)
    define_si_derived_prefix(d, deci)
    define_si_derived_prefix(da, deca)
    define_si_derived_prefix(h, hecto)
    define_si_derived_prefix(k, kilo)
    define_si_derived_prefix(M, mega)
    define_si_derived_prefix(G, giga)
    define_si_derived_prefix(T, tera)
    define_si_derived_prefix(P, peta)
    define_si_derived_prefix(E, exa)
    define_si_derived_prefix(Z, zetta)
    define_si_derived_prefix(Y, yotta)
    define_si_derived_prefix(R, ronna)
    define_si_derived_prefix(Q, quetta)

    // Visual Studio hack
    #ifdef MT_
    #define _MT MT_
    #undef MT_
    #endif
}