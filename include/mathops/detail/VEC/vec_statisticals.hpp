#ifndef VEC_STATISTICALS_HPP
#define VEC_STATISTICALS_HPP

#include <cstddef>
#include <simd/simd_common.hpp>

namespace mathops
{
namespace vec
{
    template<typename T, simd::InstructionSet S>
    T min(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T max(const T *arr, size_t size);

    template<typename T, simd::InstructionSet S>
    T arithmetic_mean(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T geometric_mean(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T weighted_mean(const T *values, const T *weights, size_t size);

    template<typename T, simd::InstructionSet S>
    T variance(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T variance(const T *arr, const T *probabilities, size_t size);
    template<typename T, simd::InstructionSet S>
    T sample_variance(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T std_deviation(const T *arr, size_t size);
    template<typename T, simd::InstructionSet S>
    T std_deviation(const T *arr, const T *probabilities, size_t size);
    template<typename T, simd::InstructionSet S>
    T sample_std_deviation(const T *arr, size_t size);
} // namespace vec
} // namespace mathops

#include <mathops/detail/VEC/vec_statisticals.inl>

#endif // VEC_STATISTICALS_HPP