#ifndef TESTS_COMMON_HPP
#define TESTS_COMMON_HPP

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
}

#endif // TESTS_COMMON_HPP