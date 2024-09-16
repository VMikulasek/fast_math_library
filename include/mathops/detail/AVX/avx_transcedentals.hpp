#ifndef AVX_TRANSCEDENTALS_HPP
#define AVX_TRANSCEDENTALS_HPP

#include <cstddef>

namespace mathops
{
namespace avx
{
    void fast_sqrt_arr(float *arr, size_t size);
} // namespace avx
} // namespace mathops

#include <mathops/detail/AVX/avx_transcedentals.inl>

#endif // AVX_TRANSCEDENTALS_HPP