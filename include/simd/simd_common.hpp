#ifndef SIMD_COMMON_HPP
#define SIMD_COMMON_HPP

#define AVX_FLOAT_VECTOR_SIZE 8
#define AVX_ALIGNMENT 32

namespace simd
{
    /**
     * @brief Enum representing supported instruction sets
     */
    enum InstructionSet
    {
        SSE,
        AVX,
        AVX2,
        AVX_512
    };
}

#endif // SIMD_COMMON_HPP