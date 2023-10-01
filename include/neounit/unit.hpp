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

    template <typename... Ratios>
    class ratios : public std::tuple<Ratios...>
    {
    public:
        using value_type = std::tuple<Ratios...>;
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
        self_type operator+() const
        {
            return +iValue;
        }
        self_type operator-() const
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
            return op_type{};
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
        unit<T, Dimension, Exponents, Ratios> const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        return static_cast<T>(aLhs) + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline unit<T, Dimension, Exponents, Ratios> operator-(
        unit<T, Dimension, Exponents, Ratios> const& aLhs, unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
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
    constexpr inline std::enable_if_t<!is_dimensionless_v<(LhsExponents + RhsExponents)...>, unit<T, Dimension, exponents<(LhsExponents + RhsExponents)...>, LhsRatios>> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        /// @todo transform LHS & RHS ratios
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents + RhsExponents)...>, T> operator*(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        /// @todo transform LHS & RHS ratios
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(LhsExponents - RhsExponents)...>, unit<T, Dimension, exponents<(LhsExponents - RhsExponents)...>, LhsRatios>> operator/(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        /// @todo transform LHS & RHS ratios
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename LhsRatios, typename RhsRatios>
    constexpr inline std::enable_if_t<is_dimensionless_v<(LhsExponents - RhsExponents)...>, T> operator/(
        unit<T, Dimension, exponents<LhsExponents...>, LhsRatios> const& aLhs, unit<T, Dimension, exponents<RhsExponents...>, RhsRatios> const& aRhs)
    {
        /// @todo transform LHS & RHS ratios
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