#include <tests_common.hpp>

namespace tests
{
    float add(float op1, float op2)
    {
        return op1 + op2;
    }

    float sub(float op1, float op2)
    {
        return op1 - op2;
    }

    float mul(float op1, float op2)
    {
        return op1 * op2;
    }

    float div(float op1, float op2)
    {
        return op1 / op2;
    }

    float bitwise_and(float op1, float op2)
    {
        int tmp = *reinterpret_cast<int *>(&op1) & *reinterpret_cast<int *>(&op2);
        return *reinterpret_cast<float *>(&tmp);
    }

    float bitwise_or(float op1, float op2)
    {
        int tmp = *reinterpret_cast<int *>(&op1) | *reinterpret_cast<int *>(&op2);
        return *reinterpret_cast<float *>(&tmp);
    }

    float bitwise_xor(float op1, float op2)
    {
        int tmp = *reinterpret_cast<int *>(&op1) ^ *reinterpret_cast<int *>(&op2);
        return *reinterpret_cast<float *>(&tmp);
    }
}