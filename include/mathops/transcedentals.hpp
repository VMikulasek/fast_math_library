#ifndef TRANSCEDENTALS_HPP
#define TRANSCEDENTALS_HPP

namespace mathops
{
    /**
     * @brief Computes square root of num using C++ standard library
     */
    float sqrt(float num);

    /**
     * @brief Accelerated computation of square root of num with lower accuracy
     */
    float fast_sqrt(float num);

    /**
     * @brief Accelerated computation of inverse square root of num with lower accuracy
     * using the fast inverse square root algorithm
     */
    float fast_invsqrt(float num);
}

#endif // TRANSCEDENTALS_HPP