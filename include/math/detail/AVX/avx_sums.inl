#ifndef AVX_SUMS_INL

#include <math/detail/AVX/avx_sums.hpp>
#include <simd/simd_vector.hpp>
#include <simd/simd_operations.hpp>

#include <vector>

namespace math
{
namespace avx
{

#ifdef HAS_AVX

    inline float sum(const float *arr, size_t size)
    {
        std::vector<float>(arr, arr + simd::SIMDVector<float, AVX>::VECTOR_LEN);
    }

#endif

} // namespace avx
} // namespace math

#endif // AVX_SUMS_INL