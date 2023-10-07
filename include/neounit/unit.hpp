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
#include <tuple>
#include <numeric>
#include <limits>
#include <ratio>

namespace neounit
{
    using integer = std::int32_t;
    using dimensional_exponent = integer;

    namespace detail
    {
        template <class T, dimensional_exponent>
        using hook = T;
    }

    template <dimensional_exponent... Exponents>
    class exponents : public std::tuple<detail::hook<dimensional_exponent, Exponents>...>
    {
    public:
        using value_type = std::tuple<detail::hook<dimensional_exponent, Exponents>...>;
    public:
        exponents() : value_type{ Exponents... } 
        {
        }
    public:
        value_type const& operator*() const
        {
            return *this;
        }
    };

    using none = std::ratio<0>;
    using one = std::ratio<1>;

    template <typename Ratio>
    struct apply_inverse { using result_type = std::ratio<Ratio::den, Ratio::num>; };
    template <>
    struct apply_inverse<none> { using result_type = none; };
    template <typename Ratio>
    using apply_inverse_t = typename apply_inverse<Ratio>::result_type;

    template <typename Ratio, dimensional_exponent E>
    struct apply_power {};
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
    struct apply_power<Ratio, 1> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 0>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 2> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 1>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 3> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 2>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 4> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 3>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 5> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 4>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 6> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 5>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 7> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 6>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 8> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 7>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 9> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 8>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 10> { using result_type = typename std::ratio_multiply<Ratio, typename apply_power<Ratio, 9>::result_type>; };
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
    class ratios : public std::tuple<Ratios...>
    {
    public:
        using value_type = std::tuple<Ratios...>;
        using inverse_t = typename ratios<apply_inverse_t<Ratios>...>;
        template <dimensional_exponent... E>
        using apply_power_t = ratios<typename neounit::apply_power_t<Ratios, E>...>;
        template <dimensional_exponent... E>
        using apply_power_sign_t = ratios<typename neounit::apply_power_sign_t<Ratios, E>...>;
        template <dimensional_exponent... E>
        using dont_apply_power_sign_t = ratios<Ratios...>;
    public:
        ratios() : value_type{ Ratios{}... }
        {
        }
    public:
        value_type const& operator*() const
        {
            return *this;
        }
    };

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    class unit
    {
    public:
        using self_type = unit<T, Dimension, Exponents, Ratios>;
        using value_type = T;
        using dimension_type = Dimension;
        using exponents_type = Exponents;
        using ratios_type = Ratios;
    public:
        unit() : iValue{}
        {
        }
        template <typename U = T>
        unit(U aValue, std::enable_if_t<std::is_same_v<std::decay_t<U>, T>, int> = {}) : iValue{ aValue }
        {
        }
        unit(self_type const& aValue) : iValue{ aValue }
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
        template <typename T, dimensional_exponent LhsExponent, dimensional_exponent RhsExponent, typename LhsRatio, typename RhsRatio>
        inline constexpr T coefficient()
        {
            if constexpr (!std::is_same_v<LhsRatio, none> && !std::is_same_v<RhsRatio, none>)
            {
                using calc = std::ratio_divide<apply_power_t<RhsRatio, RhsExponent>, apply_power_t<LhsRatio, LhsExponent>>;
                auto const num = calc::num;
                auto const den = calc::den;
                if constexpr (LhsExponent >= 0 || RhsExponent >= 0)
                    return static_cast<T>(1.0) * num / den;
                else
                    return static_cast<T>(1.0) / num * den;
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
    constexpr inline To conversion_cast(unit<T, Dimension, Exponents, Ratios> const& aRhs)
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
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator+(
        unit<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) + aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator+(
        T const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator-(
        unit<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) - aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator-(
        T const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs - static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename LhsExponents, typename LhsRatios, typename RhsExponents, typename RhsRatios>
    constexpr inline unit<T, Dimension, LhsExponents, LhsRatios> operator+(
        unit<T, Dimension, LhsExponents, LhsRatios> const& aLhs, unit<T, Dimension, RhsExponents, RhsRatios> const& aRhs)
    {
        static_assert(std::is_same_v<LhsExponents, RhsExponents> && std::is_same_v<LhsRatios, RhsRatios>);
        return static_cast<T>(aLhs) + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename LhsExponents, typename LhsRatios, typename RhsExponents, typename RhsRatios>
    constexpr inline unit<T, Dimension, LhsExponents, LhsRatios> operator-(
        unit<T, Dimension, LhsExponents, LhsRatios> const& aLhs, unit<T, Dimension, RhsExponents, RhsRatios> const& aRhs)
    {
        static_assert(std::is_same_v<LhsExponents, RhsExponents> && std::is_same_v<LhsRatios, RhsRatios>);
        return static_cast<T>(aLhs) - static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator*(
        unit<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) * aRhs;
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator*(
        T const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator/(
        unit<T, Dimension, Exponents, Ratios> const& aLhs, T const& aRhs)
    {
        return static_cast<T>(aLhs) / aRhs;
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename... LhsRatios, typename... RhsRatios>
    constexpr inline std::enable_if_t<
        !is_dimensionless_v<(LhsExponents + RhsExponents)...>, 
        unit<T, Dimension, exponents<(LhsExponents + RhsExponents)...>, ratios<typename combine_t<LhsExponents, RhsExponents, LhsRatios, RhsRatios>...>>> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, ratios<LhsRatios...>> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, ratios<RhsRatios...>> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents + RhsExponents)...>, T> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(0 - RhsExponents)...>, unit<T, Dimension, exponents<(0 - RhsExponents)...>, typename RhsRatios::inverse_t>> operator/(
        T const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(0 - RhsExponents)...>, T> operator/(
        T const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline auto operator/(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        return aLhs * (static_cast<T>(1.0) / aRhs);
    }
}