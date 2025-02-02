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

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::set_register_each(
        float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8)
    {
        return _mm256_set_ps(num1, num2, num3, num4, num5, num6, num7, num8);   
    }

    inline void SIMDOperations<float, InstructionSet::AVX>::materialize_register(
        const AvxReg &reg, float *dst)
    {
        _mm256_store_ps(dst, reg);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::add(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_add_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::sub(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_sub_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::mul(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_mul_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::div(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_div_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_and(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_and_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_or(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_or_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::bitwise_xor(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_xor_ps(vec1, vec2);
    }

    template<AvxCmpVariant Variant>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::cmp(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_cmp_ps(vec1, vec2, static_cast<int>(Variant));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::horizontal_add(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_hadd_ps(vec1, vec2);
    }

    template<int mask>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::blend(
        const AvxReg &vec1, const AvxReg &vec2)
    {
        return _mm256_blend_ps(vec1, vec2, mask);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_right_32bits(
        const AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(2, 1, 0, 3));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_left_32bits(
        const AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(0, 3, 2, 1));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_64bits(
        const AvxReg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(1, 0, 3, 2));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::swap_halves(
        const AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000001);
    }

    template<int pattern>
    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::permute_reg_inside_halves(
        const AvxReg &vec)
    {
        return _mm256_permute_ps(vec, pattern);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::distribute_low_half(
        const AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000000);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::distribute_high_half(
        const AvxReg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00010001);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::round(
        const AvxReg &vec)
    {
        return _mm256_round_ps(vec, (_MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::AvxReg SIMDOperations<float, InstructionSet::AVX>::abs(
        const AvxReg &vec)
    {
        AvxReg mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7FFFFFFF));
        return bitwise_and(vec, mask);
    }
} // namespace simd

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL