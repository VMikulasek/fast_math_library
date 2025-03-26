#ifndef VEC_SUMS_HPP
#define VEC_SUMS_HPP

#include <cstddef>
#include <simd/simd_common.hpp>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet S>
    T sum(const T *arr, size_t size);

    template<typename T, simd::InstructionSet S>
    void prefix_sum(const T *arr, size_t size, T *dstArr);
} // namespace vec
} // namespace math

#include <mathops/detail/VEC/vec_sums.inl>

#endif // VEC_SUMS_HPP