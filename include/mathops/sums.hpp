#ifndef SUMS_HPP
#define SUMS_HPP

#include <cstddef>

namespace mathops
{
    /**
     * @brief Computes sum of arr accelerated with
     * biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially
     * 
     * @param arr Array to sum, aligned to 32 bytes,
     * otherwise segmentation fault may be generated
     * @param size Size of array
     * @return float Sum of arr
     */
    float sum(const float *arr, size_t size);
    
    /**
     * @brief Computes prefix sum of arr accelerated
     * with biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially 
     * 
     * @param arr Array to perform prefix sum on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     * @param dstArr Array to store result to, must be
     * at least the size of arr, has to be aligned to
     * 32 bytes
     */
    void prefix_sum(const float *arr, size_t size, float *dstArr);
} // namespace math

#include <mathops/detail/sums.inl>

#endif // SUMS_HPP