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
    };

    template <typename T, typename Dimension, dimensional_exponent... Exponents>
    class unit
    {
    public:
        using self_type = unit<T, Dimension, Exponents...>;
        using value_type = T;
        using dimension_type = Dimension;
        using exponents_type = exponents<Exponents...>;
    public:
        unit(value_type aValue) : iValue{ aValue }
        {
        }
    public:
        operator value_type() const
        {
            return iValue;
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
        exponents_type const iExponents;
    };

    template <dimensional_exponent First, dimensional_exponent... Rest>
    constexpr bool is_dimensionless_v = ((0 == First) && ((First == Rest) && ...));

    template <typename T, typename Dimension, dimensional_exponent... Exponents>
    inline unit<T, Dimension, Exponents...> operator+(
        unit<T, Dimension, Exponents...> const& aLhs, unit<T, Dimension, Exponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) + static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... Exponents>
    inline unit<T, Dimension, Exponents...> operator-(
        unit<T, Dimension, Exponents...> const& aLhs, unit<T, Dimension, Exponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) - static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<!is_dimensionless_v<(LhsExponents + RhsExponents)...>, unit<T, Dimension, (LhsExponents + RhsExponents)...>> operator*(
        unit<T, Dimension, LhsExponents...> const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<is_dimensionless_v<(LhsExponents + RhsExponents)...>, T> operator*(
        unit<T, Dimension, LhsExponents...> const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) * static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<!is_dimensionless_v<(LhsExponents - RhsExponents)...>, unit<T, Dimension, (LhsExponents - RhsExponents)...>> operator/(
        unit<T, Dimension, LhsExponents...> const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... LhsExponents, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<is_dimensionless_v<(LhsExponents - RhsExponents)...>, T> operator/(
        unit<T, Dimension, LhsExponents...> const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<!is_dimensionless_v<(0 - RhsExponents)...>, unit<T, Dimension, (0 - RhsExponents)...>> operator/(
        T const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }

    template <typename T, typename Dimension, dimensional_exponent... RhsExponents>
    inline std::enable_if_t<is_dimensionless_v<(0 - RhsExponents)...>, T> operator/(
        T const& aLhs, unit<T, Dimension, RhsExponents...> const& aRhs)
    {
        return static_cast<T>(aLhs) / static_cast<T>(aRhs);
    }
}