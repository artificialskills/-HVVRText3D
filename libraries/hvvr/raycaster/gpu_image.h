#pragma once

/**
 * Copyright (c) 2017-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#include "cuda_decl.h"
#include "graphics_types.h"

namespace hvvr {

class GPUImage {
public:
    GPUImage() {}

    void update(uint32_t imageWidth,
                uint32_t imageHeight,
                uint32_t imageStride,
                PixelFormat imageFormat = PixelFormat::RGBA8_SRGB);
    void updateFromLinearGraphicsResource(cudaGraphicsResource_t resource,
                                          size_t size,
                                          PixelFormat imageFormat = PixelFormat::RGBA8_SRGB);

    void reset();

    bool valid() const {
        return (d_data != nullptr);
    }
    CUDA_HOST_DEVICE void* data() const {
        return d_data;
    }

    CUDA_HOST_DEVICE uint32_t width() const {
        return m_width;
    };
    CUDA_HOST_DEVICE uint32_t height() const {
        return m_height;
    };
    CUDA_HOST_DEVICE uint32_t stride() const {
        return m_stride;
    };

    uint32_t bytesPerPixel() const {
        return (m_format == PixelFormat::RGBA8_SRGB) ? 4 : 16;
    }
    size_t sizeInMemory() const {
        return size_t(bytesPerPixel()) * m_stride * m_height;
    }

protected:
    uint32_t m_width = 0, m_height = 0, m_stride = 0;
    PixelFormat m_format = PixelFormat::RGBA8_SRGB;
    void* d_data = nullptr;
    cudaGraphicsResource_t m_backingGraphicsResource = nullptr;
};

} // namespace hvvr
