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

    using kilo = std::ratio<1000>;

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
    using Hz = unit<T, dimension, exponents<Hz_EXPONENTS>, typename ratios<one, none, none, none, none, none, none>::dont_apply_power_sign_t<Hz_EXPONENTS>>;
    template<typename T = double>
    using rad = T;
    template<typename T = double>
    using sr = T;
    template<typename T = double>
    using N = unit<T, dimension, exponents<N_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<N_EXPONENTS>>;
    template<typename T = double>
    using Pa = unit<T, dimension, exponents<Pa_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<Pa_EXPONENTS>>;
    template<typename T = double>
    using J = unit<T, dimension, exponents<J_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<J_EXPONENTS>>;
    template<typename T = double>
    using W = unit<T, dimension, exponents<W_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<W_EXPONENTS>>;
    template<typename T = double>
    using C = unit<T, dimension, exponents<C_EXPONENTS>, ratios<one, none, none, one, none, none, none>::dont_apply_power_sign_t<C_EXPONENTS>>;
    template<typename T = double>
    using V = unit<T, dimension, exponents<V_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<V_EXPONENTS>>;
    template<typename T = double>
    using F = unit<T, dimension, exponents<F_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<F_EXPONENTS>>;
    template<typename T = double>
    using Ω = unit<T, dimension, exponents<Ω_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<Ω_EXPONENTS>>;
    template<typename T = double>
    using S = unit<T, dimension, exponents<S_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<S_EXPONENTS>>;
    template<typename T = double>
    using Wb = unit<T, dimension, exponents<Wb_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<Wb_EXPONENTS>>;
    template<typename T_ = double>
    using T = unit<T_, dimension, exponents<T_EXPONENTS>, ratios<one, none, kilo, one, none, none, none>::dont_apply_power_sign_t<T_EXPONENTS>>;
    template<typename T = double>
    using H = unit<T, dimension, exponents<H_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<H_EXPONENTS>>;
    template<typename T = double>
    using degC = unit<T, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, one, none, none>::dont_apply_power_sign_t<degC_EXPONENTS>>;
    template<typename T = double>
    using lm = unit<T, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, one>::dont_apply_power_sign_t<lm_EXPONENTS>>;
    template<typename T = double>
    using lx = unit<T, dimension, exponents<lx_EXPONENTS>, ratios<none, one, none, none, none, none, one>::dont_apply_power_sign_t<lx_EXPONENTS>>;
    template<typename T = double>
    using Bq = unit<T, dimension, exponents<Bq_EXPONENTS>, ratios<one, none, none, none, none, none, none>::dont_apply_power_sign_t<Bq_EXPONENTS>>;
    template<typename T = double>
    using Gy  = unit<T, dimension, exponents<Gy_EXPONENTS>, ratios<one, one, none, none, none, none, none>::dont_apply_power_sign_t<Gy_EXPONENTS>>;
    template<typename T = double>
    using Sv = unit<T, dimension, exponents<Sv_EXPONENTS>, ratios<one, one, none, none, none, none, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>;
    template<typename T = double>
    using kat = unit<T, dimension, exponents<kat_EXPONENTS>, ratios<one, none, none, none, none, one, none>::dont_apply_power_sign_t<kat_EXPONENTS>>;

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
        inline auto operator "" _Hz(long double n) { return unit<double, dimension, exponents<Hz_EXPONENTS>, ratios<one, none, none, none, none, none, none>::dont_apply_power_sign_t<Hz_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _rad(long double n) { return static_cast<double>(n); }
        inline auto operator "" _sr(long double n) { return static_cast<double>(n); }
        inline auto operator "" _N(long double n) { return unit<double, dimension, exponents<N_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<N_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _Pa(long double n) { return unit<double, dimension, exponents<Pa_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<Pa_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _J(long double n) { return unit<double, dimension, exponents<J_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<J_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _W(long double n) { return unit<double, dimension, exponents<W_EXPONENTS>, ratios<one, one, kilo, none, none, none, none>::dont_apply_power_sign_t<W_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _C(long double n) { return unit<double, dimension, exponents<C_EXPONENTS>, ratios<one, none, none, one, none, none, none>::dont_apply_power_sign_t<C_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _V(long double n) { return unit<double, dimension, exponents<V_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<V_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _F(long double n) { return unit<double, dimension, exponents<F_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<F_EXPONENTS>> { static_cast<double>(n) }; }
        inline auto operator "" _Ω(long double n) { return unit<double, dimension, exponents<Ω_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<Ω_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _S(long double n) { return unit<double, dimension, exponents<S_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<S_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _Wb(long double n) { return unit<double, dimension, exponents<Wb_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<Wb_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _T(long double n) { return unit<double, dimension, exponents<T_EXPONENTS>, ratios<one, none, kilo, one, none, none, none>::dont_apply_power_sign_t<T_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _H(long double n) { return unit<double, dimension, exponents<H_EXPONENTS>, ratios<one, one, kilo, one, none, none, none>::dont_apply_power_sign_t<H_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _degC(long double n) { return unit<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, one, none, none>::dont_apply_power_sign_t<degC_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _lm(long double n) { return unit<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, one>::dont_apply_power_sign_t<lm_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _lx(long double n) { return unit<double, dimension, exponents<lx_EXPONENTS>, ratios<none, one, none, none, none, none, one>::dont_apply_power_sign_t<lx_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _Bq(long double n) { return unit<double, dimension, exponents<Bq_EXPONENTS>, ratios<one, none, none, none, none, none, none>::dont_apply_power_sign_t<Bq_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _Gy(long double n) { return unit<double, dimension, exponents<Gy_EXPONENTS>, ratios<one, one, none, none, none, none, none>::dont_apply_power_sign_t<Gy_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _Sv(long double n) { return unit<double, dimension, exponents<Sv_EXPONENTS>, ratios<one, one, none, none, none, none, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>{ static_cast<double>(n) }; }
        inline auto operator "" _kat(long double n) { return unit<double, dimension, exponents<kat_EXPONENTS>, ratios<one, none, none, none, none, one, none>::dont_apply_power_sign_t<kat_EXPONENTS>>{ static_cast<double>(n) }; }
    }

    #define define_si_derived_prefix(ShortPrefix, LongPrefix, Ratio)\
    using ShortPrefix ## Hz = unit<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Hz_EXPONENTS>>;\
    using ShortPrefix ## N = unit<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<N_EXPONENTS>>;\
    using ShortPrefix ## Pa = unit<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<Pa_EXPONENTS>>;\
    using ShortPrefix ## J = unit<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<J_EXPONENTS>>;\
    using ShortPrefix ## W = unit<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<W_EXPONENTS>>;\
    using ShortPrefix ## C = unit<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>::dont_apply_power_sign_t<C_EXPONENTS>>;\
    using ShortPrefix ## V = unit<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<V_EXPONENTS>>;\
    using ShortPrefix ## F = unit<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<F_EXPONENTS>>;\
    using ShortPrefix ## Ω = unit<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Ω_EXPONENTS>>;\
    using ShortPrefix ## S = unit<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<S_EXPONENTS>>;\
    using ShortPrefix ## Wb = unit<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Wb_EXPONENTS>>;\
    using ShortPrefix ## T = unit<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<T_EXPONENTS>>;\
    using ShortPrefix ## H = unit<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<H_EXPONENTS>>;\
    using ShortPrefix ## degC = unit<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>::dont_apply_power_sign_t<degC_EXPONENTS>>;\
    using ShortPrefix ## lm = unit<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>::dont_apply_power_sign_t<lm_EXPONENTS>>;\
    using ShortPrefix ## lx = unit<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>::dont_apply_power_sign_t<lx_EXPONENTS>>;\
    using ShortPrefix ## Bq = unit<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Bq_EXPONENTS>>;\
    using ShortPrefix ## Gy = unit<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Gy_EXPONENTS>>;\
    using ShortPrefix ## Sv = unit<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>;\
    using ShortPrefix ## kat = unit<double, dimension, exponents<kat_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>::dont_apply_power_sign_t<kat_EXPONENTS>>;\
    using LongPrefix ## hertz = unit<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Hz_EXPONENTS>>;\
    using LongPrefix ## newton = unit<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<N_EXPONENTS>>;\
    using LongPrefix ## pascal = unit<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<Pa_EXPONENTS>>;\
    using LongPrefix ## joule = unit<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<J_EXPONENTS>>;\
    using LongPrefix ## watt = unit<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<W_EXPONENTS>>;\
    using LongPrefix ## coulomb = unit<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>::dont_apply_power_sign_t<C_EXPONENTS>>;\
    using LongPrefix ## volt = unit<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<V_EXPONENTS>>;\
    using LongPrefix ## farad = unit<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<F_EXPONENTS>>;\
    using LongPrefix ## ohm = unit<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Ω_EXPONENTS>>;\
    using LongPrefix ## siemens = unit<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<S_EXPONENTS>>;\
    using LongPrefix ## weber = unit<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Wb_EXPONENTS>>;\
    using LongPrefix ## tesla = unit<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<T_EXPONENTS>>;\
    using LongPrefix ## henry = unit<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<H_EXPONENTS>>;\
    using LongPrefix ## Celsius = unit<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>::dont_apply_power_sign_t<degC_EXPONENTS>>;\
    using LongPrefix ## lumen = unit<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>::dont_apply_power_sign_t<lm_EXPONENTS>>;\
    using LongPrefix ## lux = unit<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>::dont_apply_power_sign_t<lx_EXPONENTS>>;\
    using LongPrefix ## becquerel = unit<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Bq_EXPONENTS>>;\
    using LongPrefix ## gray = unit<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Gy_EXPONENTS>>;\
    using LongPrefix ## sievert = unit<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>;\
    using LongPrefix ## katal = unit<double, dimension, exponents<kat_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>::dont_apply_power_sign_t<kat_EXPONENTS>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## Hz(long double n) { return unit<double, dimension, exponents<Hz_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Hz_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## N(long double n) { return unit<double, dimension, exponents<N_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<N_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Pa(long double n) { return unit<double, dimension, exponents<Pa_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<Pa_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## J(long double n) { return unit<double, dimension, exponents<J_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<J_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## W(long double n) { return unit<double, dimension, exponents<W_EXPONENTS>, ratios<Ratio, Ratio, Ratio, none, none, none, none>::dont_apply_power_sign_t<W_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## C(long double n) { return unit<double, dimension, exponents<C_EXPONENTS>, ratios<Ratio, none, none, Ratio, none, none, none>::dont_apply_power_sign_t<C_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## V(long double n) { return unit<double, dimension, exponents<V_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<V_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## F(long double n) { return unit<double, dimension, exponents<F_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<F_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Ω(long double n) { return unit<double, dimension, exponents<Ω_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Ω_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## S(long double n) { return unit<double, dimension, exponents<S_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<S_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Wb(long double n) { return unit<double, dimension, exponents<Wb_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<Wb_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## T(long double n) { return unit<double, dimension, exponents<T_EXPONENTS>, ratios<Ratio, none, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<T_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## H(long double n) { return unit<double, dimension, exponents<H_EXPONENTS>, ratios<Ratio, Ratio, Ratio, Ratio, none, none, none>::dont_apply_power_sign_t<H_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## degC(long double n) { return unit<double, dimension, exponents<degC_EXPONENTS>, ratios<none, none, none, none, Ratio, none, none>::dont_apply_power_sign_t<degC_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## lm(long double n) { return unit<double, dimension, exponents<lm_EXPONENTS>, ratios<none, none, none, none, none, none, Ratio>::dont_apply_power_sign_t<lm_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## lx(long double n) { return unit<double, dimension, exponents<lx_EXPONENTS>, ratios<none, Ratio, none, none, none, none, Ratio>::dont_apply_power_sign_t<lx_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Bq(long double n) { return unit<double, dimension, exponents<Bq_EXPONENTS>, ratios<Ratio, none, none, none, none, none, none>::dont_apply_power_sign_t<Bq_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Gy(long double n) { return unit<double, dimension, exponents<Gy_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Gy_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## Sv(long double n) { return unit<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, Ratio, none, none, none, none, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## kat(long double n) { return unit<double, dimension, exponents<Sv_EXPONENTS>, ratios<Ratio, none, none, none, none, Ratio, none>::dont_apply_power_sign_t<Sv_EXPONENTS>>{ static_cast<double>(n) }; }\
    }

    // Visual Studio hack
    #ifdef _MT
    #define MT_ _MT
    #undef _MT
    #endif

    define_si_derived_prefix(a, atto, std::atto)
    define_si_derived_prefix(f, femto, std::femto)
    define_si_derived_prefix(p, pico, std::pico)
    define_si_derived_prefix(n, nano, std::nano)
    define_si_derived_prefix(u, micro, std::micro)
    define_si_derived_prefix(m, milli, std::milli)
    define_si_derived_prefix(c, centi, std::centi)
    define_si_derived_prefix(d, deci, std::deci)
    define_si_derived_prefix(da, deca, std::deca)
    define_si_derived_prefix(h, hecto, std::hecto)
    define_si_derived_prefix(k, kilo, std::kilo)
    define_si_derived_prefix(M, mega, std::mega)
    define_si_derived_prefix(G, giga, std::giga)
    define_si_derived_prefix(T, tera, std::tera)
    define_si_derived_prefix(P, peta, std::peta)
    define_si_derived_prefix(E, exa, std::exa)

    // Visual Studio hack
    #ifdef MT_
    #define _MT MT_
    #endif
}