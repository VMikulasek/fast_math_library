#ifndef SIMD_COMMON_HPP
#define SIMD_COMMON_HPP

namespace simd
{
    /**
     * @brief Enum representing supported instruction sets
     */
    enum InstructionSet
    {
        SSE,
        AVX,
        AVX_512
    };
}

#endif // SIMD_COMMON_HPP