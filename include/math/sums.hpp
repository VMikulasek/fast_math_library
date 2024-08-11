#ifndef SUMS_HPP

#include <cstddef>

namespace math
{
    /**
     * @brief Computes sum of arr accelerated with
     * biggest SIMD unit supported and available on
     * PC, in case of no SIMD unit available, computes
     * sequentially
     * 
     * @param arr Array to sum
     * @param size Size of array
     * @return float Sum of arr
     */
    float sum(const float *arr, size_t size);
} // namespace math

#include <math/detail/sums.inl>

#endif // SUMS_HPP