#ifndef SUMS_INL
#define SUMS_INL

#include <mathops/sums.hpp>
#include <mathops/detail/VEC/vec_sums.hpp>
#include <mathops/detail/SEQ/seq_sums.hpp>
#include <common/detail/memory_common.inl>
#include <simd/simd_common.hpp>

#include <type_traits>

namespace mathops
{
    template<typename T>
    inline T sum(const T *arr, size_t size)
    {
        static_assert(std::is_arithmetic_v<T>);

        if constexpr (std::is_same_v<T, T> && HAS_AVX)
        {
            return vec::sum<T, simd::InstructionSet::AVX>(arr, size);
        }
        else
        {
            return seq::sum(arr, size);
        }
    }

    template<typename T>
    inline T sum(const std::vector<T> &arr)
    {
        return sum(arr.data(), arr.size());
    }

    template<typename T>
    inline T *prefix_sum(const T *arr, size_t size)
    {
        static_assert(std::is_arithmetic_v<T>);

        ALLOC_DST;

        if constexpr (std::is_same_v<T, T> && HAS_AVX)
        {
            vec::prefix_sum<T, simd::InstructionSet::AVX>(arr, size, dst);
        }
        else
        {
            seq::prefix_sum(arr, size, dst);
        }

        return dst;
    }

    template<typename T>
    inline T *prefix_sum(const std::vector<T> &arr)
    {
        return prefix_sum(arr.data(), arr.size());
    }
} // namespace math

#endif // SUMS_INL