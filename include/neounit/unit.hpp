// unit.hpp
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
#include <numeric>
#include <limits>
#include <ratio>
#include <unordered_map>
#include <string>

namespace neounit
{
    using integer = std::int32_t;
    using dimensional_exponent = integer;

    inline std::u8string to_u8string(std::string_view const& aString)
    {
        return { reinterpret_cast<char8_t const*>(aString.data()), reinterpret_cast<char8_t const*>(aString.data()) + aString.length() };
    }

    inline std::string to_string(std::u8string_view const& aString)
    {
        return { reinterpret_cast<char const*>(aString.data()), reinterpret_cast<char const*>(aString.data()) + aString.length() };
    }

    template <dimensional_exponent E>
    inline std::u8string power_to_u8string()
    {
        static std::unordered_map<char8_t, std::u8string> digits
        {
            { u8'0' , u8"⁰" },
            { u8'1' , u8"¹" },
            { u8'2' , u8"²" },
            { u8'3' , u8"³" },
            { u8'4' , u8"⁴" },
            { u8'5' , u8"⁵" },
            { u8'6' , u8"⁶" },
            { u8'7' , u8"⁷" },
            { u8'8' , u8"⁸" },
            { u8'9' , u8"⁹" },
            { u8'-' , u8"⁻" }
        };
        thread_local std::u8string partialResult;
        partialResult = to_u8string(std::to_string(E));
        thread_local std::u8string result;
        result.clear();
        for (auto const& digit : partialResult)
        {
            result += digits.at(digit);
        }
        return result;
    }

    template <dimensional_exponent... Exponents>
    struct exponents {};

    template<std::intmax_t Num, std::intmax_t Denom = 1, std::intmax_t Exp = 0>
    struct ratio : std::ratio<Num, Denom>
    {
        static constexpr std::intmax_t exp = Exp;
    };

    template<typename Lhs, typename Rhs>
    struct ratio_multiply_impl;
    template<std::intmax_t Num1, std::intmax_t Denom1, std::intmax_t Exp1, std::intmax_t Num2, std::intmax_t Denom2, std::intmax_t Exp2>
    struct ratio_multiply_impl<ratio<Num1, Denom1, Exp1>, ratio<Num2, Denom2, Exp2>>
    {
        using partial_type = std::ratio_multiply<std::ratio<Num1, Denom1>, std::ratio<Num2, Denom2>>;
        using result_type = ratio<partial_type::num, partial_type::den, Exp1 + Exp2>;
    };
    template<typename Lhs, typename Rhs>
    using ratio_multiply = typename ratio_multiply_impl<Lhs, Rhs>::result_type;

    template<typename Lhs, typename Rhs>
    struct ratio_divide_impl;
    template<std::intmax_t Num1, std::intmax_t Denom1, std::intmax_t Exp1, std::intmax_t Num2, std::intmax_t Denom2, std::intmax_t Exp2>
    struct ratio_divide_impl<ratio<Num1, Denom1, Exp1>, ratio<Num2, Denom2, Exp2>>
    {
        using partial_type = std::ratio_divide<std::ratio<Num1, Denom1>, std::ratio<Num2, Denom2>>;
        using result_type = ratio<partial_type::num, partial_type::den, Exp1 - Exp2>;
    };
    template<typename Lhs, typename Rhs>
    using ratio_divide = typename ratio_divide_impl<Lhs, Rhs>::result_type;

    using none = ratio<0>;
    using one = ratio<1>;
    using quecto = ratio<1, 1, -30>;
    using ronto = ratio<1, 1, -27>;
    using yocto = ratio<1, 1, -24>;
    using zepto = ratio<1, 1, -21>;
    using atto = ratio<1, 1, -18>;
    using femto = ratio<1, 1, -15>;
    using pico = ratio<1, 1, -12>;
    using nano = ratio<1, 1, -9>;
    using micro = ratio<1, 1, -6>;
    using milli = ratio<1, 1, -3>;
    using centi = ratio<1, 1, -2>;
    using deci = ratio<1, 1, -1>;
    using deca = ratio<1, 1, 1>;
    using hecto = ratio<1, 1, 2>;
    using kilo = ratio<1, 1, 3>;
    using mega = ratio<1, 1, 6>;
    using giga = ratio<1, 1, 9>;
    using tera = ratio<1, 1, 12>;
    using peta = ratio<1, 1, 15>;
    using exa = ratio<1, 1, 18>;
    using zetta = ratio<1, 1, 21>;
    using yotta = ratio<1, 1, 24>;
    using ronna = ratio<1, 1, 27>;
    using quetta = ratio<1, 1, 30>;

    template <typename R>
    struct ratio_short_prefix { static constexpr std::u8string_view prefix = u8""; };
    template <> struct ratio_short_prefix<quecto> { static constexpr std::u8string_view prefix = u8"q"; };
    template <> struct ratio_short_prefix<ronto> { static constexpr std::u8string_view prefix = u8"r"; };
    template <> struct ratio_short_prefix<yocto> { static constexpr std::u8string_view prefix = u8"y"; };
    template <> struct ratio_short_prefix<zepto> { static constexpr std::u8string_view prefix = u8"z"; };
    template <> struct ratio_short_prefix<atto> { static constexpr std::u8string_view prefix = u8"a"; };
    template <> struct ratio_short_prefix<femto> { static constexpr std::u8string_view prefix = u8"f"; };
    template <> struct ratio_short_prefix<pico> { static constexpr std::u8string_view prefix = u8"p"; };
    template <> struct ratio_short_prefix<nano> { static constexpr std::u8string_view prefix = u8"n"; };
    template <> struct ratio_short_prefix<micro> { static constexpr std::u8string_view prefix = u8"u"; };
    template <> struct ratio_short_prefix<milli> { static constexpr std::u8string_view prefix = u8"m"; };
    template <> struct ratio_short_prefix<centi> { static constexpr std::u8string_view prefix = u8"c"; };
    template <> struct ratio_short_prefix<deci> { static constexpr std::u8string_view prefix = u8"d"; };
    template <> struct ratio_short_prefix<deca> { static constexpr std::u8string_view prefix = u8"da"; };
    template <> struct ratio_short_prefix<hecto> { static constexpr std::u8string_view prefix = u8"h"; };
    template <> struct ratio_short_prefix<kilo> { static constexpr std::u8string_view prefix = u8"k"; };
    template <> struct ratio_short_prefix<mega> { static constexpr std::u8string_view prefix = u8"M"; };
    template <> struct ratio_short_prefix<giga> { static constexpr std::u8string_view prefix = u8"G"; };
    template <> struct ratio_short_prefix<tera> { static constexpr std::u8string_view prefix = u8"T"; };
    template <> struct ratio_short_prefix<peta> { static constexpr std::u8string_view prefix = u8"P"; };
    template <> struct ratio_short_prefix<exa> { static constexpr std::u8string_view prefix = u8"E"; };
    template <> struct ratio_short_prefix<zetta> { static constexpr std::u8string_view prefix = u8"Z"; };
    template <> struct ratio_short_prefix<yotta> { static constexpr std::u8string_view prefix = u8"Y"; };
    template <> struct ratio_short_prefix<ronna> { static constexpr std::u8string_view prefix = u8"R"; };
    template <> struct ratio_short_prefix<quetta> { static constexpr std::u8string_view prefix = u8"Q"; };

    template <typename Ratio>
    struct apply_inverse { using result_type = ratio<Ratio::num, Ratio::den, -Ratio::exp>; };
    template <>
    struct apply_inverse<none> { using result_type = none; };
    template <typename Ratio>
    using apply_inverse_t = typename apply_inverse<Ratio>::result_type;

    template <typename Ratio, dimensional_exponent E>
    struct apply_power;
    template <>
    struct apply_power<none, 0> { using result_type = none; };
    template <>
    struct apply_power<none, 1> { using result_type = none; };
    template <>
    struct apply_power<none, 2> { using result_type = none; };
    template <>
    struct apply_power<none, 3> { using result_type = none; };
    template <>
    struct apply_power<none, 4> { using result_type = none; };
    template <>
    struct apply_power<none, 5> { using result_type = none; };
    template <>
    struct apply_power<none, 6> { using result_type = none; };
    template <>
    struct apply_power<none, 7> { using result_type = none; };
    template <>
    struct apply_power<none, 8> { using result_type = none; };
    template <>
    struct apply_power<none, 9> { using result_type = none; };
    template <>
    struct apply_power<none, 10> { using result_type = none; };
    template <>
    struct apply_power<none, -1> { using result_type = none; };
    template <>
    struct apply_power<none, -2> { using result_type = none; };
    template <>
    struct apply_power<none, -3> { using result_type = none; };
    template <>
    struct apply_power<none, -4> { using result_type = none; };
    template <>
    struct apply_power<none, -5> { using result_type = none; };
    template <>
    struct apply_power<none, -6> { using result_type = none; };
    template <>
    struct apply_power<none, -7> { using result_type = none; };
    template <>
    struct apply_power<none, -8> { using result_type = none; };
    template <>
    struct apply_power<none, -9> { using result_type = none; };
    template <>
    struct apply_power<none, -10> { using result_type = none; };
    template <typename Ratio>
    struct apply_power<Ratio, 0> { using result_type = one; };
    template <typename Ratio>
    struct apply_power<Ratio, 1> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 0>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 2> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 1>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 3> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 2>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 4> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 3>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 5> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 4>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 6> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 5>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 7> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 6>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 8> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 7>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 9> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 8>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 10> { using result_type = typename ratio_multiply<Ratio, typename apply_power<Ratio, 9>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -1> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 1>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -2> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 2>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -3> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 3>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -4> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 4>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -5> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 5>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -6> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 6>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -7> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 7>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -8> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 8>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -9> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 9>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, -10> { using result_type = typename apply_inverse_t<typename apply_power<Ratio, 10>::result_type>; };
    template <typename Ratio, dimensional_exponent E>
    using apply_power_t = typename apply_power<Ratio, E>::result_type;

    inline constexpr dimensional_exponent sign(dimensional_exponent E)
    {
        if (E >= 0)
            return 1;
        else
            return -1;
    }

    template <dimensional_exponent E>
    struct calc_sign
    {
        static constexpr dimensional_exponent result = sign(E);
    };

    template <typename Ratio, dimensional_exponent E>
    using apply_power_sign_t = typename apply_power<Ratio, calc_sign<E>::result>::result_type;

    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2, 
        bool ConvertLeft = std::is_same_v<apply_power_sign_t<Ratio1, Exponent1>, Ratio2>,
        bool ConvertRight = std::is_same_v<apply_power_sign_t<Ratio2, Exponent2>, Ratio1>>
    struct to_same_unit {};
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    struct to_same_unit<Exponent1, Exponent2, Ratio1, Ratio2, true, false>
    {
        using result_type = apply_power_sign_t<Ratio1, Exponent1>;
    };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    struct to_same_unit<Exponent1, Exponent2, Ratio1, Ratio2, false, true>
    {
        using result_type = apply_power_sign_t<Ratio2, Exponent2>;
    };

    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    struct is_effectively_same_unit
    {
        static constexpr bool result =
            !std::is_same_v<Ratio1, Ratio2> && 
            !std::is_same_v<Ratio1, none> && 
            !std::is_same_v<Ratio2, none> &&
            (std::is_same_v<apply_power_sign_t<Ratio1, Exponent1>, Ratio2> ||
            std::is_same_v<apply_power_sign_t<Ratio2, Exponent2>, Ratio1>);
    };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    constexpr bool is_effectively_same_unit_v = is_effectively_same_unit<Exponent1, Exponent2, Ratio1, Ratio2>::result;

    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    struct combine
    {
        using result_type = std::enable_if_t<is_effectively_same_unit_v<Exponent1, Exponent2, Ratio1, Ratio2>, Ratio1>;
    };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio>
    struct combine<Exponent1, Exponent2, Ratio, Ratio> { using result_type = Ratio; };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio>
    struct combine<Exponent1, Exponent2, Ratio, none> { using result_type = Ratio; };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio>
    struct combine<Exponent1, Exponent2, none, Ratio> { using result_type = Ratio; };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2>
    struct combine<Exponent1, Exponent2, none, none> { using result_type = none; };
    template <dimensional_exponent Exponent1, dimensional_exponent Exponent2, typename Ratio1, typename Ratio2>
    using combine_t = typename combine<Exponent1, Exponent2, Ratio1, Ratio2>::result_type;

    template <typename... Ratios>
    struct ratios
    {
        using inverse_t = typename ratios<apply_inverse_t<Ratios>...>;
        template <dimensional_exponent... E>
        using apply_power_t = ratios<typename neounit::apply_power_t<Ratios, E>...>;
        template <dimensional_exponent... E>
        using apply_power_sign_t = ratios<typename neounit::apply_power_sign_t<Ratios, E>...>;
    };

    template <typename Dimension, typename Exponents, typename Ratios>
    struct unit
    {
        using dimension_type = Dimension;
        using exponents_type = Exponents;
        using ratios_type = Ratios;
    };

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    class scalar : public unit<Dimension, Exponents, Ratios>
    {
    public:
        using self_type = scalar<T, Dimension, Exponents, Ratios>;
        using unit_type = unit<Dimension, Exponents, Ratios>;
        using value_type = T;
        using dimension_type = typename unit_type::dimension_type;
        using exponents_type = typename unit_type::exponents_type;
        using ratios_type = typename unit_type::ratios_type;
    public:
        scalar() : iValue{}
        {
        }
        template <typename U = T>
        scalar(U aValue, std::enable_if_t<std::is_same_v<std::decay_t<U>, T>, int> = {}) : iValue{ aValue }
        {
        }
        scalar(self_type const& aValue) : iValue{ aValue }
        {
        }
    public:
        template <typename U = T>
        std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, self_type>& operator=(U aValue)
        {
            iValue = aValue;
            return *this;
        }
        self_type& operator=(self_type const& aValue)
        {
            iValue = aValue;
            return *this;
        }
    public:
        template <typename U = value_type>
        constexpr operator std::enable_if_t<std::is_same_v<std::decay_t<U>, value_type>, value_type>() const
        {
            return iValue;
        }
        constexpr self_type operator+() const
        {
            return +iValue;
        }
        constexpr self_type operator-() const
        {
            return -iValue;
        }
    public:
        friend auto constexpr operator==(self_type const& aLhs, self_type const& aRhs)
        {
            return aLhs.iValue == aRhs.iValue;
        }
        friend auto constexpr operator<=>(self_type const& aLhs, self_type const& aRhs)
        {
            return aLhs.iValue <=> aRhs.iValue;
        }
        friend auto constexpr operator==(self_type const& aLhs, value_type const& aRhs)
        {
            return aLhs.iValue == aRhs;
        }
        friend auto constexpr operator<=>(self_type const& aLhs, value_type const& aRhs)
        {
            return aLhs.iValue <=> aRhs;
        }
        friend auto constexpr operator==(value_type const& aLhs, self_type const& aRhs)
        {
            return aLhs == aRhs.iValue;
        }
        friend auto constexpr operator<=>(value_type const& aLhs, self_type const& aRhs)
        {
            return aLhs <=> aRhs.iValue;
        }
    private:
        value_type iValue;
    };

    namespace detail
    {
        template <typename T, std::intmax_t Power>
        inline constexpr T power_10()
        {
            if constexpr (Power < 0)
                return static_cast<T>(0.1) * power_10<T, Power + 1>();
            else if constexpr (Power > 0)
                return static_cast<T>(10) * power_10<T, Power - 1>();
            else
                return static_cast<T>(1.0);
        }

        template <typename T, dimensional_exponent LhsExponent, dimensional_exponent RhsExponent, typename LhsRatio, typename RhsRatio>
        inline constexpr T coefficient()
        {
            if constexpr (!std::is_same_v<LhsRatio, none> && !std::is_same_v<RhsRatio, none>)
            {
                using calc = ratio_divide<apply_power_t<RhsRatio, RhsExponent>, apply_power_t<LhsRatio, LhsExponent>>;
                auto const num = calc::num;
                auto const den = calc::den;
                if constexpr (LhsExponent >= 0 || RhsExponent >= 0)
                    return static_cast<T>(1.0) * num / den * power_10<T, calc::exp>();
                else
                    return static_cast<T>(1.0) / num * den * power_10<T, -calc::exp>();
            }
            return static_cast<T>(1.0);
        };

        template <typename T, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename... LhsRatios, typename... RhsRatios>
        inline constexpr T coefficient(exponents<LhsExponents...>, exponents<RhsExponents...>, ratios<LhsRatios...>, ratios<RhsRatios...>)
        {
            return (coefficient<T, LhsExponents, RhsExponents, LhsRatios, RhsRatios>() * ...);
        };
    }

    template <typename To, typename T, typename Dimension, std::same_as<typename To::exponents_type> Exponents, typename Ratios>
    constexpr inline To conversion_cast(scalar<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        using rhs_type = std::decay_t<decltype(aRhs)>;
        if constexpr (std::is_same_v<To, rhs_type>)
            return aRhs;
        auto result = static_cast<typename To::value_type>(static_cast<T>(aRhs));
        result = result * detail::coefficient<T>(typename To::exponents_type{}, Exponents{}, typename To::ratios_type{}, Ratios{});
        return result;
    }

    template <dimensional_exponent First, dimensional_exponent... Rest>
    constexpr bool is_dimensionless_v = ((0 == First) && ((First == Rest) && ...));

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator+(
        scalar<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) + aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator+(
        T const& aLhs, scalar<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator-(
        scalar<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) - aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator-(
        T const& aLhs, scalar<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs - static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename LhsExponents, typename LhsRatios, typename RhsExponents, typename RhsRatios>
    constexpr inline scalar<T, Dimension, LhsExponents, LhsRatios> operator+(
        scalar<T, Dimension, LhsExponents, LhsRatios> const& aLhs, scalar<T, Dimension, RhsExponents, RhsRatios> const& aRhs)
    {
        static_assert(std::is_same_v<LhsExponents, RhsExponents> && std::is_same_v<LhsRatios, RhsRatios>);
        return static_cast<T>(aLhs) + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename LhsExponents, typename LhsRatios, typename RhsExponents, typename RhsRatios>
    constexpr inline scalar<T, Dimension, LhsExponents, LhsRatios> operator-(
        scalar<T, Dimension, LhsExponents, LhsRatios> const& aLhs, scalar<T, Dimension, RhsExponents, RhsRatios> const& aRhs)
    {
        static_assert(std::is_same_v<LhsExponents, RhsExponents> && std::is_same_v<LhsRatios, RhsRatios>);
        return static_cast<T>(aLhs) - static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator*(
        scalar<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) * aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator*(
        T const& aLhs, scalar<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline scalar<T, Dimension, Exponents, Ratios> operator/(
        scalar<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) / aRhs;
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename... LhsRatios, typename... RhsRatios>
    constexpr inline std::enable_if_t<
        !is_dimensionless_v<(LhsExponents + RhsExponents)...>, 
        scalar<T, Dimension, exponents<(LhsExponents + RhsExponents)...>, ratios<typename combine_t<LhsExponents, RhsExponents, LhsRatios, RhsRatios>...>>> operator*(
        scalar<T, Dimension, exponents<LhsExponents...>, ratios<LhsRatios...>> const& aLhs, scalar<T, Dimension, exponents<RhsExponents...>, ratios<RhsRatios...>> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents + RhsExponents)...>, T> operator*(
        scalar<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, scalar<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(0 - RhsExponents)...>, scalar<T, Dimension, exponents<(0 - RhsExponents)...>, typename RhsRatios::inverse_t>> operator/(
        T const& aLhs, scalar<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(0 - RhsExponents)...>, T> operator/(
        T const& aLhs, scalar<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline auto operator/(
        scalar<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, scalar<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return aLhs * (static_cast<T>(1.0) / aRhs);
    }
}