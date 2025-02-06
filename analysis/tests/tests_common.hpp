#ifndef TESTS_COMMON_HPP
#define TESTS_COMMON_HPP

#include <cstddef>

namespace analysis
{
namespace tests
{
    enum OperationDirection
    {
        // Performs operation on adjacents
        HORIZONTAL,
        // Performs operation on same indexes different vectors
        VERTICAL
    };

    float add(float op1, float op2);
    float sub(float op1, float op2);
    float mul(float op1, float op2);
    float div(float op1, float op2);
    float bitwise_and(float op1, float op2);
    float bitwise_or(float op1, float op2);
    float bitwise_xor(float op1, float op2);
    float cmp_lt(float op1, float op2);
    float cmp_gt(float op1, float op2);
    float cmp_eq(float op1, float op2);
    float cmp_le(float op1, float op2);
    float cmp_ge(float op1, float op2);
    float min(float op1, float op2);
    float max(float op1, float op2);
    float abs(float num);
    float round(float num);

    int add_i(int op1, int op2);
    int sub_i(int op1, int op2);
    int shift_left(int op, int nBits);
    int shift_right(int op, int nBits);
    
    template<int mask>
    float blend(float op1, float op2)
    {
        static unsigned index = 0;

        int decisionFlag = (1 << index) & mask;
        index++;

        if (decisionFlag == 0)
        {
            return op1;
        }
        else
        {
            return op2;
        }
    }

    void reference_prefix_sum(const float *src, size_t size, float *dst);
    void reference_sqrt_arr(const float *src, size_t size, float *dst);
    void reference_invsqrt_arr(const float *src, size_t size, float *dst);
    void reference_sin_arr(const float *src, size_t size, float *dst);
    void reference_cos_arr(const float *src, size_t size, float *dst);
    void reference_tan_arr(const float *src, size_t size, float *dst);
    void reference_cot_arr(const float *src, size_t size, float *dst);
} // namespace tests
} // namespace analysis

#endif // TESTS_COMMON_HPP