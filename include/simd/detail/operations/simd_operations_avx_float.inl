#ifndef SIMD_OPERATIONS_AVX_FLOAT_INL
#define SIMD_OPERATIONS_AVX_FLOAT_INL

#include <simd/simd_common.hpp>
#include <simd/detail/operations/simd_operations_avx_float.hpp>

namespace simd
{
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::load_vector(
        const float *arr)
    {
        return _mm256_load_ps(arr);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::set_register_zero()
    {
        return _mm256_setzero_ps();
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::set_register(
        float num)
    {
        return _mm256_set1_ps(num);
    }

    inline void SIMDOperations<float, InstructionSet::AVX>::materialize_register(
        AvxReg &reg, float *dst)
    {
        _mm256_store_ps(dst, reg);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::convert_from_int(
        __m256i &intReg)
    {
        return _mm256_cvtepi32_ps(intReg);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::add(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_add_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::sub(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_sub_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::mul(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_mul_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::div(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_div_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_and(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_and_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_or(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_or_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_xor(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_xor_ps(vec1, vec2);
    }

    template<AvxCmpVariant Variant>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::cmp(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_cmp_ps(vec1, vec2, static_cast<int>(Variant));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::horizontal_add(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_hadd_ps(vec1, vec2);
    }

    template<int mask>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::blend(
        AvxReg &vec1, AvxReg &vec2)
    {
        return _mm256_blend_ps(vec1, vec2, mask);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_right_32bits(
        AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(2, 1, 0, 3));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_left_32bits(
        AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(0, 3, 2, 1));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_64bits(
        AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(1, 0, 3, 2));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::swap_halves(
        AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000001);
    }

    template<int pattern>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::permute_reg_inside_halves(
        AvxReg &vec)
    {
        return _mm256_permute_ps(vec, pattern);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::distribute_low_half(
        AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000000);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::distribute_high_half(
        AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00010001);
    }
} // namespace simd

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL