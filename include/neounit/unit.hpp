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

    template <typename Ratio1, typename Ratio2>
    struct ratio_combine_if {};
    template <>
    struct ratio_combine_if<none, none> { using result_type = none; };
    template <typename Ratio>
    struct ratio_combine_if<Ratio, Ratio> { using result_type = Ratio; };
    template <typename Ratio>
    struct ratio_combine_if<Ratio, none> { using result_type = Ratio; };
    template <typename Ratio>
    struct ratio_combine_if<none, Ratio> { using result_type = Ratio; };
    template <typename Ratio1, typename Ratio2>
    using ratio_combine_if_t = typename ratio_combine_if<Ratio1, Ratio2>::result_type;

    template <typename... Ratios>
    class ratios : public std::tuple<Ratios...>
    {
    public:
        using value_type = std::tuple<Ratios...>;
        template <typename Rhs>
        struct combine_ratios {};
        template <typename... Ratios2>
        struct combine_ratios<ratios<Ratios2...>> { using result_type = ratios<ratio_combine_if_t<Ratios, Ratios2>...>; };
        template <typename Rhs>
        using combine_t = typename combine_ratios<Rhs>::result_type;
        template <typename Rhs>
        struct compatible {};
        template <typename... Ratios2>
        struct compatible<ratios<Ratios2...>> { static constexpr bool result = ((std::is_same_v<Ratios, Ratios2> || std::is_same_v<Ratios, none> || std::is_same_v<Ratios2, none>) && ...); };
        template <typename Rhs>
        static constexpr bool compatible_v = compatible<Rhs>::result;
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
        unit(value_type aValue) : iValue{ aValue }
        {
        }
        unit(self_type const& aValue) : iValue{ aValue }
        {
        }
    public:
        constexpr operator value_type() const
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
        auto constexpr operator<=>(self_type const& aRhs) const
        {
            return iValue <=> aRhs.iValue;
        }
        auto constexpr operator<=>(value_type const& aRhs) const
        {
            return iValue <=> aRhs;
        }
    private:
        value_type iValue;
    };

    template <typename To, typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline std::enable_if_t<std::is_same_v<typename To::exponents_type, Exponents>, To> conversion_cast(unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        using rhs_type = std::decay_t<decltype(aRhs)>;
        if constexpr (std::is_same_v<To, rhs_type>)
            return aRhs;
        typename To::value_type result = aRhs;
        auto transform = [&result](auto&& r1, auto&& r2, dimensional_exponent e)
        {
            if constexpr (!std::is_same_v<std::decay_t<decltype(r1)>, none> && !std::is_same_v<std::decay_t<decltype(r2)>, none>)
            {
                using op_type = std::ratio_divide<std::decay_t<decltype(r1)>, std::decay_t<decltype(r2)>>;
                while (e < 0)
                {
                    result /= op_type::num;
                    result *= op_type::den;
                    ++e;
                }
                while (e > 0)
                {
                    result *= op_type::num;
                    result /= op_type::den;
                    --e;
                }
            }
            return 0;
        };
        std::apply(
            [&](auto&& ...r1)
            {
                return std::apply(
                    [&](auto&& ...r2)
                    {
                        return std::apply(
                            [&](auto&& ...e)
                            {
                                (void)std::make_tuple(transform(r1, r2, e)...);
                            },
                            *(typename rhs_type::exponents_type{}));
                    },
                    typename To::ratios_type::value_type{});
            },
            typename rhs_type::ratios_type::value_type{});
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

    template <typename T, typename Dimension, typename Exponents1, typename Ratios1, typename Exponents2, typename Ratios2>
    constexpr inline unit<T, Dimension, Exponents1, Ratios1> operator+(
        unit<T, Dimension, Exponents1, Ratios1> const& aLhs, unit<T, Dimension, Exponents2, Ratios2> const& aRhs)
    {
        static_assert(std::is_same_v<Exponents1, Exponents2> && std::is_same_v<Ratios1, Ratios2>);
        return static_cast<T>(aLhs) + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents1, typename Ratios1, typename Exponents2, typename Ratios2>
    constexpr inline unit<T, Dimension, Exponents1, Ratios1> operator-(
        unit<T, Dimension, Exponents1, Ratios1> const& aLhs, unit<T, Dimension, Exponents2, Ratios2> const& aRhs)
    {
        static_assert(std::is_same_v<Exponents1, Exponents2> && std::is_same_v<Ratios1, Ratios2>);
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

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator/(
        T const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return aLhs / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(LhsExponents + RhsExponents)...>, unit<T, Dimension, exponents<(LhsExponents + RhsExponents)...>, typename LhsRatios::template combine_t<RhsRatios>>> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        static_assert(LhsRatios::template compatible_v<RhsRatios>);
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents + RhsExponents)...>, T> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        static_assert(LhsRatios::template compatible_v<RhsRatios>);
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(LhsExponents - RhsExponents)...>, unit<T, Dimension, exponents<(LhsExponents - RhsExponents)...>, typename LhsRatios::template combine_t<RhsRatios>>> operator/(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        static_assert(LhsRatios::template compatible_v<RhsRatios>);
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents - RhsExponents)...>, T> operator/(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        static_assert(LhsRatios::template compatible_v<RhsRatios>);
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(0 - RhsExponents)...>, unit<T, Dimension, exponents<(0 - RhsExponents)...>, RhsRatios>> operator/(
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
}