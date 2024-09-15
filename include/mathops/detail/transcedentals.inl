#ifndef TRANSCEDENTALS_INL
#define TRANSCEDENTALS_INL

#include <cmath>

namespace mathops
{
    inline float sqrt(float num)
    {
        return std::sqrt(num);
    }

    inline float fast_sqrt(float num)
    {
        return 1 / fast_invsqrt(num);
    }

    inline float fast_invsqrt(float num)
    {
        float numHalf = 0.5f * num;
        int i = *(int*)&num;
        i = 0x5f375a86- (i>>1);
        num = *(float*)&i;
        num = num * (1.5f - numHalf * num * num);
        return num;
    }
}

#endif // TRANSCEDENTALS_INL