#ifndef AVX_SUMS_INL
#define AVX_SUMS_INL

#include <math/detail/AVX/avx_sums.hpp>
#include <simd/simd_vector.hpp>
#include <simd/simd_operations.hpp>

#include <vector>
#include <algorithm>

namespace math
{
namespace avx
{

#ifdef HAS_AVX

    using FloatReg = simd::SIMDOperations<float, simd::AVX>::AvxReg;
    using FloatVec = simd::SIMDVector<float, simd::AVX>;
    using FloatOps = simd::SIMDOperations<float, simd::AVX>;

    static const size_t VECTOR_SIZE = FloatVec::VECTOR_SIZE;

    // private
    inline FloatVec cut_vec_from_arr(const float *&arr, size_t &size)
    {
        size_t actualVectorSize = std::min(size, VECTOR_SIZE);
        std::vector<float> vec(arr, arr + actualVectorSize);
        size -= actualVectorSize;
        arr += actualVectorSize;

        return FloatVec(vec);
    }

    inline float sum(const float *arr, size_t size)
    {
        if (size == 0)
        {
            return 0;
        }
        else if (size == 1)
        {
            return arr[0];
        }

        size_t partitions = size;
        
        FloatVec simdVec = cut_vec_from_arr(arr, size);
        FloatReg tmpResultReg = FloatOps::load_vector(simdVec);

        while (partitions > 2)
        {
            if (size >= VECTOR_SIZE)
            {
                partitions -= VECTOR_SIZE;
            }
            else if (size > 0)
            {
                partitions -= (VECTOR_SIZE + size) / 2;
            }
            else
            {
                partitions -= partitions / 2;
            }

            FloatVec secondOpSimdVec;
            if (size > 0)
            {
                secondOpSimdVec = cut_vec_from_arr(arr, size);
            }
            else 
            {
                secondOpSimdVec = FloatVec(0, 0, 0, 0, 0, 0, 0, 0);
            }

            FloatReg secondOpReg = FloatOps::load_vector(secondOpSimdVec);

            tmpResultReg = FloatOps::horizontal_add(tmpResultReg, secondOpReg);
        }

        simdVec = FloatOps::materialize_register(tmpResultReg);
        auto resultArr = simdVec.get_content();
        return resultArr[0] + resultArr[4];
    }

#endif

} // namespace avx
} // namespace math

#endif // AVX_SUMS_INL