#ifndef TRANSCEDENTALS_HPP
#define TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
    /**
     * @brief Computes square root of num using
     * C++ standard library
     */
    float sqrt(float num);

    /**
     * @brief Accelerated computation of square root
     * of num with lower accuracy
     */
    float fast_sqrt(float num);

    /**
     * @brief Accelerated computation of inverse square root
     * of num with lower accuracy
     * using the fast inverse square root algorithm
     */
    float fast_invsqrt(float num);

    /**
     * @brief Calculated fast square root for array,
     * if any supported SIMD unit available,
     * then accelerates the algorithm also
     * with paralelisation through biggest SIMD unit available
     * 
     * @param arr Array of floats to calculate square root on,
     * has to be aligned to 32 bytes
     * @param size Size of array
     */
    void fast_sqrt_arr(float *arr, size_t size);
}

#include <mathops/detail/transcedentals.inl>

#endif // TRANSCEDENTALS_HPP