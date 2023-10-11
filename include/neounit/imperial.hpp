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
    template<dimensional_exponent E, typename T = double>
    using gr = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<6479891, 1, -8>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>                          
    using dr = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<17718451953125, 1, -13>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>                          
    using oz = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<28349523125, 1, -9>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>                          
    using lb = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<45359237, 1, -5>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>                          
    using st = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<635029318, 1, -5>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>                          
    using qr = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<1270058636, 1, -5>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using cwt = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<5080234544, 1, -5>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using t_ = unit<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, ratio<10160469088, 1, -4>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _ft(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254 * 12, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _yd(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<254 * 12 * 3, 10000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _mi(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio<1609344, 1000>, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _gr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<6479891, 1, -8>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _dr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<17718451953125, 1, -13>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _oz(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<28349523125, 1, -9>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _lb(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<45359237, 1, -5>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _st(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<635029318, 1, -5>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _qr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<1270058636, 1, -5>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _cwt(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<5080234544, 1, -5>, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _t_(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio<10160469088, 1, -4>, none, none, none, none>>{ static_cast<double>(n) }; }
    }

    using in_sq = in<2>;
    using ft_sq = ft<2>;
    using yd_sq = yd<2>;
    using mi_sq = mi<2>;
    using gr_sq = gr<2>;
    using dr_sq = dr<2>;
    using oz_sq = oz<2>;
    using lb_sq = lb<2>;
    using st_sq = st<2>;
    using qr_sq = qr<2>;
    using cwt_sq = cwt<2>;
    using t_sq = t_<2>;
    using inv_in = in<-1>;
    using inv_ft = ft<-1>;
    using inv_yd = yd<-1>;
    using inv_mi = mi<-1>;
    using inv_gr = gr<-1>;
    using inv_dr = dr<-1>;
    using inv_oz = oz<-1>;
    using inv_lb = lb<-1>;
    using inv_st = st<-1>;
    using inv_qr = qr<-1>;
    using inv_cwt = cwt<-1>;
    using inv_t = t_<-1>;
    using inv_in_sq = in<-2>;
    using inv_ft_sq = ft<-2>;
    using inv_yd_sq = yd<-2>;
    using inv_mi_sq = mi<-2>;
    using inv_gr_sq = gr<-2>;
    using inv_dr_sq = dr<-2>;
    using inv_oz_sq = oz<-2>;
    using inv_lb_sq = lb<-2>;
    using inv_st_sq = st<-2>;
    using inv_qr_sq = qr<-2>;
    using inv_cwt_sq = cwt<-2>;
    using inv_t_sq = t_<2>;
    using inch = in<1>;
    using foot = ft<1>;
    using yard = yd<1>;
    using mile = mi<1>;
    using grain = gr<1>;
    using drachm = dr<1>;
    using ounce = oz<1>;
    using pound = lb<1>;
    using stone = st<1>;
    using quarter = qr<1>;
    using hundredweight = cwt<1>;
    using ton = t_<1>;
    using inch_sq = in<2>;
    using foot_sq = ft<2>;
    using yard_sq = yd<2>;
    using mile_sq = mi<2>;
    using grain_sq = gr<2>;
    using drachm_sq = dr<2>;
    using ounce_sq = oz<2>;
    using pound_sq = lb<2>;
    using stone_sq = st<2>;
    using quarter_sq = qr<2>;
    using hundredweight_sq = cwt<2>;
    using ton_sq = t_<2>;
    using inv_inch = in<-1>;
    using inv_foot = ft<-1>;
    using inv_yard = yd<-1>;
    using inv_mile = mi<-1>;
    using inv_grain = gr<-1>;
    using inv_drachm = dr<-1>;
    using inv_ounce = oz<-1>;
    using inv_pound = lb<-1>;
    using inv_stone = st<-1>;
    using inv_quarter = qr<-1>;
    using inv_hundredweight = cwt<-1>;
    using inv_ton = t_<-1>;
    using inv_inch_sq = in<-2>;
    using inv_foot_sq = ft<-2>;
    using inv_yard_sq = yd<-2>;
    using inv_mile_sq = mi<-2>;
    using inv_grain_sq = gr<-2>;
    using inv_drachm_sq = dr<-2>;
    using inv_ounce_sq = oz<-2>;
    using inv_pound_sq = lb<-2>;
    using inv_stone_sq = st<-2>;
    using inv_quarter_sq = qr<-2>;
    using inv_hundredweight_sq = cwt<-2>;
    using inv_ton_sq = t_<-2>;

    #define define_imperial_prefix(ShortPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## in = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## ft = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## yd = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## mi = unit<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## gr = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## dr = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## oz = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## lb = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## st = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## qr = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## cwt = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## t_ = unit<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    using ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## ft_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## yd_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## mi_sq = unit<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>;\
    using ShortPrefix ## gr_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## dr_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## oz_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## lb_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## st_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## qr_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## cwt_sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>>;\
    using ShortPrefix ## t__sq = unit<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>>;\
    using inv_ ## ShortPrefix ## in = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## ft = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## yd = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## mi = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<21609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## gr = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## dr = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## oz = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## lb = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## st = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## qr = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## cwt = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## t_ = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## in_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## ft_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## yd_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## mi_sq = unit<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## gr_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## dr_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## oz_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## lb_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## st_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## qr_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## cwt_sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## t__sq = unit<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using Ratio ## inch = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## foot = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## yard = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## mile = unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>;\
    using Ratio ## grain = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>>;\
    using Ratio ## drachm = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>>;\
    using Ratio ## ounce = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>>;\
    using Ratio ## pound = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>>;\
    using Ratio ## stone = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>>;\
    using Ratio ## quarter = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>>;\
    using Ratio ## hundredweight = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>>;\
    using Ratio ## ton = unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>>;\
    using inv_ ## Ratio ## inch = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## foot = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## yard = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## mile = unit<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## grain = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## drachm = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## ounce = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## pound = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## stone = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## quarter = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## hundredweight = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## ton = unit<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## in(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## ft(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## yd(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<254 * 12 * 3, 10000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## mi(long double n) { return unit<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, ratio_multiply<ratio<1609344, 1000>, Ratio>, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## gr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<6479891, 1, -8>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## dr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<17718451953125, 1, -13>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## oz(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<28349523125, 1, -9>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## lb(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<45359237, 1, -5>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## st(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<635029318, 1, -5>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## qr(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<1270058636, 1, -5>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## cwt(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<5080234544, 1, -5>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## t_(long double n) { return unit<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, ratio_multiply<ratio<10160469088, 1, -4>, Ratio>, none, none, none, none>>{ static_cast<double>(n) }; }\
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