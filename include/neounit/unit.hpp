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

    template <typename R1, typename R2, bool>
    struct safe_ratio_multiply_impl;

    template <typename R1, typename R2>
    struct safe_ratio_multiply_impl<R1, R2, true>
    {
        using type = std::ratio_multiply<R1, R2>;
    };

    template <typename R1, typename R2>
    struct safe_ratio_multiply_impl<R1, R2, false>
    {
        using type = one;
    };

    constexpr std::intmax_t log(std::intmax_t number, std::intmax_t acc = 0) 
    {
        return number <= 1 ? acc : log(number / 2, acc + 1);
    }

    constexpr bool is_safe_multiple(std::intmax_t N1, std::intmax_t D1, std::intmax_t N2, std::intmax_t D2)
    {
        auto limit = log(std::numeric_limits<std::intmax_t>::max()) + log(std::gcd(N1, D2)) + log(std::gcd(N2, D1));
        auto num = (log(N1) + log(N2)) < limit;
        auto den = (log(D2) + log(D1)) < limit;
        return num && den;
    }

    template <typename R1, typename R2>
    struct safe_ratio_multiply
    {
        using result_type = typename safe_ratio_multiply_impl<R1, R2, is_safe_multiple(R1::num, R1::den, R2::num, R2::den)>::type;
    };

    template <typename R1>
    struct safe_ratio_multiply<R1, none>
    {
        using result_type = R1;
    };

    template <typename R2>
    struct safe_ratio_multiply<none, R2>
    {
        using result_type = R2;
    };

    template <>
    struct safe_ratio_multiply<none, none>
    {
        using result_type = none;
    };

    template <typename R1, typename R2>
    using safe_ratio_multiply_t = typename safe_ratio_multiply<R1, R2>::result_type;

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
    struct apply_power<Ratio, 1> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 0>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 2> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 1>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 3> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 2>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 4> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 3>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 5> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 4>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 6> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 5>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 7> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 6>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 8> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 7>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 9> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 8>::result_type>; };
    template <typename Ratio>
    struct apply_power<Ratio, 10> { using result_type = typename safe_ratio_multiply_t<Ratio, typename apply_power<Ratio, 9>::result_type>; };
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

    template <typename... Ratios>
    class ratios : public std::tuple<Ratios...>
    {
    public:
        using value_type = std::tuple<Ratios...>;
        using inverse_t = typename ratios<apply_inverse_t<Ratios>...>;
        template <typename Rhs>
        struct compatible {};
        template <typename... Ratios2>
        struct compatible<ratios<Ratios2...>> { static constexpr bool result = ((std::is_same_v<Ratios, Ratios2> || std::is_same_v<Ratios, none> || std::is_same_v<Ratios2, none>) && ...); };
        template <typename Rhs>
        static constexpr bool compatible_v = compatible<Rhs>::result;
        template <dimensional_exponent... E>
        using apply_power_t = ratios<typename neounit::apply_power_t<Ratios, E>...>;
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

    template <typename To, typename T, typename Dimension, typename Exponents, typename Ratios>
    constexpr inline std::enable_if_t<std::is_same_v<typename To::exponents_type, Exponents>, To> conversion_cast(unit<T, Dimension, Exponents, Ratios> const& aRhs)
    {
        using rhs_type = std::decay_t<decltype(aRhs)>;
        if constexpr (std::is_same_v<To, rhs_type>)
            return aRhs;
        auto result = static_cast<typename To::value_type>(static_cast<T>(aRhs));
        auto transform = [&result](auto&& r1, auto&& r2, dimensional_exponent e)
        {
            if constexpr (!std::is_same_v<std::decay_t<decltype(r1)>, none> && !std::is_same_v<std::decay_t<decltype(r2)>, none>)
            {
                result = result * r1.num / r1.den;
                result = result * r2.den / r2.num;
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

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents, typename... LhsRatios, typename... RhsRatios>
    constexpr inline std::enable_if_t<!is_dimensionless_v<(LhsExponents + RhsExponents)...>, unit<T, Dimension, exponents<(LhsExponents + RhsExponents)...>, ratios<safe_ratio_multiply_t<LhsRatios, RhsRatios>...>>> operator*(
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