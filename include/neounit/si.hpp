// si.hpp
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
#include <array>
#include <string>

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

    #define s_EXPONENTS(E) E, 0, 0, 0, 0, 0, 0
    #define m_EXPONENTS(E) 0, E, 0, 0, 0, 0, 0
    #define g_EXPONENTS(E) 0, 0, E, 0, 0, 0, 0
    #define A_EXPONENTS(E) 0, 0, 0, E, 0, 0, 0
    #define K_EXPONENTS(E) 0, 0, 0, 0, E, 0, 0
    #define mol_EXPONENTS(E) 0, 0, 0, 0, 0, E, 0
    #define cd_EXPONENTS(E) 0, 0, 0, 0, 0, 0, E

    template<dimensional_exponent E, typename T = double>
    using s = scalar<T, dimension, exponents<s_EXPONENTS(E)>, typename ratios<one, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using m = scalar<T, dimension, exponents<m_EXPONENTS(E)>, typename ratios<none, one, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using g = scalar<T, dimension, exponents<g_EXPONENTS(E)>, typename ratios<none, none, one, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using A = scalar<T, dimension, exponents<A_EXPONENTS(E)>, typename ratios<none, none, none, one, none, none, none>::apply_power_sign_t<A_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using K = scalar<T, dimension, exponents<K_EXPONENTS(E)>, typename ratios<none, none, none, none, one, none, none>::apply_power_sign_t<K_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using mol = scalar<T, dimension, exponents<mol_EXPONENTS(E)>, typename ratios<none, none, none, none, none, one, none>::apply_power_sign_t<mol_EXPONENTS(E)>>;
    template<dimensional_exponent E, typename T = double>
    using cd = scalar<T, dimension, exponents<cd_EXPONENTS(E)>, typename ratios<none, none, none, none, none, none, one>::apply_power_sign_t<cd_EXPONENTS(E)>>;

    namespace literals
    {
        inline auto operator "" _s(long double n) { return scalar<double, dimension, exponents<s_EXPONENTS(1)>, ratios<one, none, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _m(long double n) { return scalar<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, one, none, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _g(long double n) { return scalar<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, one, none, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _A(long double n) { return scalar<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, one, none, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _K(long double n) { return scalar<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, one, none, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _mol(long double n) { return scalar<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, one, none>>{ static_cast<double>(n) }; }
        inline auto operator "" _cd(long double n) { return scalar<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, one>>{ static_cast<double>(n) }; }
    }

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

    using neounit::to_string;
    using neounit::to_u8string;

    template <dimension D>
    struct dimension_as_string { static constexpr std::string_view string = ""; };
    template <> struct dimension_as_string<dimension::Time> { static constexpr std::string_view string = "s"; };
    template <> struct dimension_as_string<dimension::Length> { static constexpr std::string_view string = "m"; };
    template <> struct dimension_as_string<dimension::Mass> { static constexpr std::string_view string = "g"; };
    template <> struct dimension_as_string<dimension::ElectricCurrent> { static constexpr std::string_view string = "A"; };
    template <> struct dimension_as_string<dimension::AbsoluteTemperature> { static constexpr std::string_view string = "K"; };
    template <> struct dimension_as_string<dimension::AmountOfSubstance> { static constexpr std::string_view string = "mol"; };
    template <> struct dimension_as_string<dimension::LuminousIntensity> { static constexpr std::string_view string = "cd"; };

    template <dimension D>
    struct dimension_as_u8string { static constexpr std::u8string_view string = u8""; };
    template <> struct dimension_as_u8string<dimension::Time> { static constexpr std::u8string_view string = u8"s"; };
    template <> struct dimension_as_u8string<dimension::Length> { static constexpr std::u8string_view string = u8"m"; };
    template <> struct dimension_as_u8string<dimension::Mass> { static constexpr std::u8string_view string = u8"g"; };
    template <> struct dimension_as_u8string<dimension::ElectricCurrent> { static constexpr std::u8string_view string = u8"A"; };
    template <> struct dimension_as_u8string<dimension::AbsoluteTemperature> { static constexpr std::u8string_view string = u8"K"; };
    template <> struct dimension_as_u8string<dimension::AmountOfSubstance> { static constexpr std::u8string_view string = u8"mol"; };
    template <> struct dimension_as_u8string<dimension::LuminousIntensity> { static constexpr std::u8string_view string = u8"cd"; };

    template <dimension D, dimensional_exponent E, typename Ratio>
    inline std::string base_unit_to_string()
    {
        if constexpr (E == 0)
            return "";
        auto result = std::string{ ratio_short_prefix<apply_power_sign_t<Ratio, E>>::prefix } + std::string{ dimension_as_string<D>::string };
        if constexpr (E != 1)
            result += ("^" + std::to_string(E));
        return result;
    }

    template <dimension D, dimensional_exponent E, typename Ratio>
    inline std::u8string base_unit_to_u8string()
    {
        if constexpr (E == 0)
            return u8"";
        auto result = std::u8string{ ratio_short_u8prefix<apply_power_sign_t<Ratio, E>>::prefix } + std::u8string{ dimension_as_u8string<D>::string };
        if constexpr (E != 1)
            result += power_to_u8string<E>();
        return result;
    }

    namespace detail
    {
        template <std::size_t I>
        constexpr dimension as_dimension_v = static_cast<dimension>(I);
        template <dimension D>
        constexpr std::size_t as_integer_v = static_cast<std::size_t>(D);
        template <std::size_t I> struct unit_position_t {};
        template <> struct unit_position_t<as_integer_v<dimension::Time>> { static constexpr std::size_t position = 2u; };
        template <> struct unit_position_t<as_integer_v<dimension::Length>> { static constexpr std::size_t position = 0u; };
        template <> struct unit_position_t<as_integer_v<dimension::Mass>> { static constexpr std::size_t position = 1u; };
        template <> struct unit_position_t<as_integer_v<dimension::ElectricCurrent>> { static constexpr std::size_t position = 3u; };
        template <> struct unit_position_t<as_integer_v<dimension::AbsoluteTemperature>> { static constexpr std::size_t position = 4u; };
        template <> struct unit_position_t<as_integer_v<dimension::AmountOfSubstance>> { static constexpr std::size_t position = 5u; };
        template <> struct unit_position_t<as_integer_v<dimension::LuminousIntensity>> { static constexpr std::size_t position = 6u; };
        template <std::size_t I>
        constexpr std::size_t unit_position_v = unit_position_t<I>::position;

        template <dimensional_exponent... Exponent, typename... Ratio, std::size_t... Is>
        inline std::string base_units_to_string(unit<dimension, exponents<Exponent...>, ratios<Ratio...>> const&, std::index_sequence<Is...>)
        {
            thread_local std::array<std::string, 7> tPartialResult;
            ((tPartialResult[unit_position_v<Is>] = si::base_unit_to_string<as_dimension_v<Is>, Exponent, Ratio>()), ...);
            thread_local std::string result;
            result.clear();
            for (auto const& u : tPartialResult)
            {
                if (u.empty())
                    continue;
                if (!result.empty())
                    result += " ";
                result += u;
            }
            return result;
        }

        template <dimensional_exponent... Exponent, typename... Ratio, std::size_t... Is>
        inline std::u8string base_units_to_u8string(unit<dimension, exponents<Exponent...>, ratios<Ratio...>> const&, std::index_sequence<Is...>)
        {
            thread_local std::array<std::u8string, 7> tPartialResult;
            ((tPartialResult[unit_position_v<Is>] = si::base_unit_to_u8string<as_dimension_v<Is>, Exponent, Ratio>()) , ...);
            thread_local std::u8string result;
            result.clear();
            for (auto const& u : tPartialResult)
            {
                if (u.empty())
                    continue;
                if (!result.empty())
                    result += u8"⋅";
                result += u;
            }
            return result;
        }
    }

    template <dimensional_exponent... Exponent, typename... Ratio>
    inline std::string base_units_to_string(unit<dimension, exponents<Exponent...>, ratios<Ratio...>> const& aUnit)
    {
        return detail::base_units_to_string(aUnit, std::make_index_sequence<sizeof...(Exponent)>{});
    }

    template <dimensional_exponent... Exponent, typename... Ratio>
    inline std::u8string base_units_to_u8string(unit<dimension, exponents<Exponent...>, ratios<Ratio...>> const& aUnit)
    {
        return detail::base_units_to_u8string(aUnit, std::make_index_sequence<sizeof...(Exponent)>{});
    }

    #define define_si_prefix(ShortPrefix, Ratio)\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## s = scalar<T, dimension, exponents<s_EXPONENTS(E)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## m = scalar<T, dimension, exponents<m_EXPONENTS(E)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## g = scalar<T, dimension, exponents<g_EXPONENTS(E)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## A = scalar<T, dimension, exponents<A_EXPONENTS(E)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## K = scalar<T, dimension, exponents<K_EXPONENTS(E)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## mol = scalar<T, dimension, exponents<mol_EXPONENTS(E)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(E)>>;\
    template<dimensional_exponent E, typename T = double>\
    using ShortPrefix ## cd = scalar<T, dimension, exponents<cd_EXPONENTS(E)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(E)>>;\
    using ShortPrefix ## s_sq = scalar<double, dimension, exponents<s_EXPONENTS(2)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using ShortPrefix ## m_sq = scalar<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using ShortPrefix ## g_sq = scalar<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using ShortPrefix ## A_sq = scalar<double, dimension, exponents<A_EXPONENTS(2)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using ShortPrefix ## K_sq = scalar<double, dimension, exponents<K_EXPONENTS(2)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using ShortPrefix ## mol_sq = scalar<double, dimension, exponents<mol_EXPONENTS(2)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using ShortPrefix ## cd_sq = scalar<double, dimension, exponents<cd_EXPONENTS(2)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using inv_ ## ShortPrefix ## s = scalar<double, dimension, exponents<s_EXPONENTS(-1)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## m = scalar<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## g = scalar<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## A = scalar<double, dimension, exponents<A_EXPONENTS(-1)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## K = scalar<double, dimension, exponents<K_EXPONENTS(-1)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## mol = scalar<double, dimension, exponents<mol_EXPONENTS(-1)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## cd = scalar<double, dimension, exponents<cd_EXPONENTS(-1)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-1)>>;\
    using inv_ ## ShortPrefix ## s_sq = scalar<double, dimension, exponents<s_EXPONENTS(-2)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## m_sq = scalar<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## g_sq = scalar<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## A_sq = scalar<double, dimension, exponents<A_EXPONENTS(-2)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## K_sq = scalar<double, dimension, exponents<K_EXPONENTS(-2)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## mol_sq = scalar<double, dimension, exponents<mol_EXPONENTS(-2)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-2)>>;\
    using inv_ ## ShortPrefix ## cd_sq = scalar<double, dimension, exponents<cd_EXPONENTS(-2)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-2)>>;\
    using Ratio ## second = scalar<double, dimension, exponents<s_EXPONENTS(1)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using Ratio ## metre = scalar<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using Ratio ## gram = scalar<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using Ratio ## ampere = scalar<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using Ratio ## kelvin = scalar<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using Ratio ## mole = scalar<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using Ratio ## candela = scalar<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using Ratio ## second_sq = scalar<double, dimension, exponents<s_EXPONENTS(2)>, ratios<Ratio, none, none, none, none, none, none>>;\
    using Ratio ## metre_sq = scalar<double, dimension, exponents<m_EXPONENTS(2)>, ratios<none, Ratio, none, none, none, none, none>>;\
    using Ratio ## gram_sq = scalar<double, dimension, exponents<g_EXPONENTS(2)>, ratios<none, none, Ratio, none, none, none, none>>;\
    using Ratio ## ampere_sq = scalar<double, dimension, exponents<A_EXPONENTS(2)>, ratios<none, none, none, Ratio, none, none, none>>;\
    using Ratio ## kelvin_sq = scalar<double, dimension, exponents<K_EXPONENTS(2)>, ratios<none, none, none, none, Ratio, none, none>>;\
    using Ratio ## mole_sq = scalar<double, dimension, exponents<mol_EXPONENTS(2)>, ratios<none, none, none, none, none, Ratio, none>>;\
    using Ratio ## candela_sq = scalar<double, dimension, exponents<cd_EXPONENTS(2)>, ratios<none, none, none, none, none, none, Ratio>>;\
    using inv_ ## Ratio ## second = scalar<double, dimension, exponents<s_EXPONENTS(-1)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## metre = scalar<double, dimension, exponents<m_EXPONENTS(-1)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## gram = scalar<double, dimension, exponents<g_EXPONENTS(-1)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## ampere = scalar<double, dimension, exponents<A_EXPONENTS(-1)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## kelvin = scalar<double, dimension, exponents<K_EXPONENTS(-1)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## mole = scalar<double, dimension, exponents<mol_EXPONENTS(-1)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## candela = scalar<double, dimension, exponents<cd_EXPONENTS(-1)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-1)>>;\
    using inv_ ## Ratio ## second_sq = scalar<double, dimension, exponents<s_EXPONENTS(-2)>, ratios<Ratio, none, none, none, none, none, none>::apply_power_sign_t<s_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## metre_sq = scalar<double, dimension, exponents<m_EXPONENTS(-2)>, ratios<none, Ratio, none, none, none, none, none>::apply_power_sign_t<m_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## gram_sq = scalar<double, dimension, exponents<g_EXPONENTS(-2)>, ratios<none, none, Ratio, none, none, none, none>::apply_power_sign_t<g_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## ampere_sq = scalar<double, dimension, exponents<A_EXPONENTS(-2)>, ratios<none, none, none, Ratio, none, none, none>::apply_power_sign_t<A_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## kelvin_sq = scalar<double, dimension, exponents<K_EXPONENTS(-2)>, ratios<none, none, none, none, Ratio, none, none>::apply_power_sign_t<K_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## mole_sq = scalar<double, dimension, exponents<mol_EXPONENTS(-2)>, ratios<none, none, none, none, none, Ratio, none>::apply_power_sign_t<mol_EXPONENTS(-2)>>;\
    using inv_ ## Ratio ## candela_sq = scalar<double, dimension, exponents<cd_EXPONENTS(-2)>, ratios<none, none, none, none, none, none, Ratio>::apply_power_sign_t<cd_EXPONENTS(-2)>>;\
    namespace literals\
    {\
        inline auto operator "" _ ## ShortPrefix ## s(long double n) { return scalar<double, dimension, exponents<s_EXPONENTS(1)>, ratios<Ratio, none, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## m(long double n) { return scalar<double, dimension, exponents<m_EXPONENTS(1)>, ratios<none, Ratio, none, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## g(long double n) { return scalar<double, dimension, exponents<g_EXPONENTS(1)>, ratios<none, none, Ratio, none, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## A(long double n) { return scalar<double, dimension, exponents<A_EXPONENTS(1)>, ratios<none, none, none, Ratio, none, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## K(long double n) { return scalar<double, dimension, exponents<K_EXPONENTS(1)>, ratios<none, none, none, none, Ratio, none, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## mol(long double n) { return scalar<double, dimension, exponents<mol_EXPONENTS(1)>, ratios<none, none, none, none, none, Ratio, none>>{ static_cast<double>(n) }; }\
        inline auto operator "" _ ## ShortPrefix ## cd(long double n) { return scalar<double, dimension, exponents<cd_EXPONENTS(1)>, ratios<none, none, none, none, none, none, Ratio>>{ static_cast<double>(n) }; }\
    }\

    define_si_prefix(q, quecto)
    define_si_prefix(r, ronto)
    define_si_prefix(y, yocto)
    define_si_prefix(z, zepto)
    define_si_prefix(a, atto)
    define_si_prefix(f, femto)
    define_si_prefix(p, pico)
    define_si_prefix(n, nano)
    define_si_prefix(u, micro)
    define_si_prefix(m, milli)
    define_si_prefix(c, centi)
    define_si_prefix(d, deci)
    define_si_prefix(da, deca)
    define_si_prefix(h, hecto)
    define_si_prefix(k, kilo)
    define_si_prefix(M, mega)
    define_si_prefix(G, giga)
    define_si_prefix(T, tera)
    define_si_prefix(P, peta)
    define_si_prefix(E, exa)
    define_si_prefix(Z, zetta)
    define_si_prefix(Y, yotta)
    define_si_prefix(R, ronna)
    define_si_prefix(Q, quetta)
}