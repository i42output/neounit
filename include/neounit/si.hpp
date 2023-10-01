// neounit.hpp
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

    using second = unit<double, dimension, 1, 0, 0, 0, 0, 0, 0>;
    using metre = unit<double, dimension, 0, 1, 0, 0, 0, 0, 0>;
    using kilogram = unit<double, dimension, 0, 0, 1, 0, 0, 0, 0>;
    using ampere = unit<double, dimension, 0, 0, 0, 1, 0, 0, 0>;
    using kelvin = unit<double, dimension, 0, 0, 0, 0, 1, 0, 0>;
    using mole = unit<double, dimension, 0, 0, 0, 0, 0, 1, 0>;
    using candela = unit<double, dimension, 0, 0, 0, 0, 0, 0, 1>;

    using second_sq = unit<double, dimension, 2, 0, 0, 0, 0, 0, 0>;
    using metre_sq = unit<double, dimension, 0, 2, 0, 0, 0, 0, 0>;
    using kilogram_sq = unit<double, dimension, 0, 0, 2, 0, 0, 0, 0>;
    using ampere_sq = unit<double, dimension, 0, 0, 0, 2, 0, 0, 0>;
    using kelvin_sq = unit<double, dimension, 0, 0, 0, 0, 2, 0, 0>;
    using mole_sq = unit<double, dimension, 0, 0, 0, 0, 0, 2, 0>;
    using candela_sq = unit<double, dimension, 0, 0, 0, 0, 0, 0, 2>;

    using inv_second = unit<double, dimension, -1, 0, 0, 0, 0, 0, 0>;
    using inv_metre = unit<double, dimension, 0, -1, 0, 0, 0, 0, 0>;
    using inv_kilogram = unit<double, dimension, 0, 0, -1, 0, 0, 0, 0>;
    using inv_ampere = unit<double, dimension, 0, 0, 0, -1, 0, 0, 0>;
    using inv_kelvin = unit<double, dimension, 0, 0, 0, 0, -1, 0, 0>;
    using inv_mole = unit<double, dimension, 0, 0, 0, 0, 0, -1, 0>;
    using inv_candela = unit<double, dimension, 0, 0, 0, 0, 0, 0, -1>;
}