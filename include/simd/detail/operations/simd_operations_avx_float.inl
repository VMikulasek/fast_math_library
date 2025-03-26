#ifndef SIMD_OPERATIONS_AVX_FLOAT_INL
#define SIMD_OPERATIONS_AVX_FLOAT_INL

#include <simd/simd_common.hpp>
#include <simd/detail/operations/simd_operations_avx_float.hpp>

namespace simd
{
    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::load_vector(
        const float *arr)
    {
        return _mm256_load_ps(arr);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::set_register_zero()
    {
        return _mm256_setzero_ps();
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::set_register(
        float num)
    {
        return _mm256_set1_ps(num);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::set_register_each(
        float num1, float num2, float num3, float num4, float num5, float num6, float num7, float num8)
    {
        return _mm256_set_ps(num8, num7, num6, num5, num4, num3, num2, num1);   
    }

    inline void SIMDOperations<float, InstructionSet::AVX>::materialize_register(
        const Reg &reg, float *dst)
    {
        _mm256_store_ps(dst, reg);
    }

    inline float SIMDOperations<float, InstructionSet::AVX>::materialize_register_at_index(
        const Reg &reg, unsigned index)
    {
        switch (index) {
            case 0: return _mm_cvtss_f32(_mm256_castps256_ps128(reg));
            case 1: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_castps256_ps128(reg), _mm256_castps256_ps128(reg), _MM_SHUFFLE(1, 1, 1, 1)));
            case 2: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_castps256_ps128(reg), _mm256_castps256_ps128(reg), _MM_SHUFFLE(2, 2, 2, 2)));
            case 3: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_castps256_ps128(reg), _mm256_castps256_ps128(reg), _MM_SHUFFLE(3, 3, 3, 3)));
            case 4: return _mm_cvtss_f32(_mm256_extractf128_ps(reg, 1));
            case 5: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_extractf128_ps(reg, 1), _mm256_extractf128_ps(reg, 1), _MM_SHUFFLE(1, 1, 1, 1)));
            case 6: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_extractf128_ps(reg, 1), _mm256_extractf128_ps(reg, 1), _MM_SHUFFLE(2, 2, 2, 2)));
            case 7: return _mm_cvtss_f32(_mm_shuffle_ps(_mm256_extractf128_ps(reg, 1), _mm256_extractf128_ps(reg, 1), _MM_SHUFFLE(3, 3, 3, 3)));
            default: return 0.0f;
        }
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::add(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_add_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::sub(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_sub_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::mul(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_mul_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::div(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_div_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::bitwise_and(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_and_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::bitwise_or(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_or_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::bitwise_xor(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_xor_ps(vec1, vec2);
    }

    template<AvxCmpVariant Variant>
    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::cmp(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_cmp_ps(vec1, vec2, static_cast<int>(Variant));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::horizontal_add(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_hadd_ps(vec1, vec2);
    }

    template<int mask>
    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::blend(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_blend_ps(vec1, vec2, mask);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_right_32bits(
        const Reg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(2, 1, 0, 3));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_left_32bits(
        const Reg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(0, 3, 2, 1));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::rotate_halves_64bits(
        const Reg &vec)
    {
        return _mm256_permute_ps(vec, _MM_SHUFFLE(1, 0, 3, 2));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::swap_halves(
        const Reg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000001);
    }

    template<int pattern>
    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::permute_reg_inside_halves(
        const Reg &vec)
    {
        return _mm256_permute_ps(vec, pattern);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::distribute_low_half(
        const Reg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00000000);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::distribute_high_half(
        const Reg &vec)
    {
        return _mm256_permute2f128_ps(vec, vec, 0b00010001);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::round(
        const Reg &vec)
    {
        return _mm256_round_ps(vec, (_MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC));
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::abs(
        const Reg &vec)
    {
        Reg mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7FFFFFFF));
        return bitwise_and(vec, mask);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::min(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_min_ps(vec1, vec2);
    }

    inline SIMDOperations<float, InstructionSet::AVX>::Reg SIMDOperations<float, InstructionSet::AVX>::max(
        const Reg &vec1, const Reg &vec2)
    {
        return _mm256_max_ps(vec1, vec2);
    }
} // namespace simd

#endif // SIMD_OPERATIONS_AVX_FLOAT_INL