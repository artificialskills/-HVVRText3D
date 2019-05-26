#pragma once

/**
 * Copyright (c) 2017-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "util.h"

namespace hvvr {

constexpr float Pi  = 3.141592653589f;
constexpr float Tau = 6.283185307180f;
constexpr float RadiansPerDegree = Pi / 180.0f;
constexpr float DegreesPerRadian = 180.0f / Pi;

struct InfinityType {
    __forceinline operator float() const {
        static const unsigned bits = 0x7f800000u;
        return alias_cast<float>(bits);
    }
} static const Infinity;

} // namespace hvvr
