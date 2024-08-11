#ifndef SEQ_SUMS_INL
#define SEQ_SUMS_INL

#include <math/detail/SEQ/seq_sums.hpp>

namespace math
{
namespace seq
{
    inline float sum(const float *arr, size_t size)
    {
        float sum = 0;

        for (size_t i = 0; i < size; i++)
        {
            sum += arr[i];
        }

        return sum;
    }
} // namespace seq
} // namespace math

#endif // SEQ_SUMS_INL