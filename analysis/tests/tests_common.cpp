#include <tests_common.hpp>
#include <limits>
#include <functional>
#include <cmath>

#define F_TO_I_REINTERPRET(F) (*reinterpret_cast<int *>(&F))
#define I_TO_F_REINTERPRET(I) (*reinterpret_cast<float *>(&I))

namespace analysis
{
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

    float bitwise_op(float op1, float op2, std::function<int (int, int)> op)
    {
        int tmp = op(F_TO_I_REINTERPRET(op1), F_TO_I_REINTERPRET(op2));
        return I_TO_F_REINTERPRET(tmp);
    }

    int b_and(int op1, int op2)
    {
        return op1 & op2;
    }
    int b_or(int op1, int op2)
    {
        return op1 | op2;
    }
    int b_xor(int op1, int op2)
    {
        return op1 ^ op2;
    }

    float bitwise_and(float op1, float op2)
    {
        return bitwise_op(op1, op2, b_and);
    }
    float bitwise_or(float op1, float op2)
    {
        return bitwise_op(op1, op2, b_or);
    }
    float bitwise_xor(float op1, float op2)
    {
        return bitwise_op(op1, op2, b_xor);
    }

    float cmp(float op1, float op2, std::function<bool (float, float)> cmp)
    {
        // true: all bits 1, false: all 0
        unsigned tmp = cmp(op1, op2) ? std::numeric_limits<unsigned>::max() : 0;
        return I_TO_F_REINTERPRET(tmp);
    }

    bool lt(float op1, float op2)
    {
        return op1 < op2;
    }
    bool gt(float op1, float op2)
    {
        return op1 > op2;
    }
    bool eq(float op1, float op2)
    {
        return op1 == op2;
    }
    bool le(float op1, float op2)
    {
        return op1 <= op2;
    }
    bool ge(float op1, float op2)
    {
        return op1 >= op2;
    }

    float cmp_lt(float op1, float op2)
    {
        return cmp(op1, op2, lt);
    }
    float cmp_gt(float op1, float op2)
    {
        return cmp(op1, op2, gt);
    }
    float cmp_eq(float op1, float op2)
    {
        return cmp(op1, op2, eq);
    }
    float cmp_le(float op1, float op2)
    {
        return cmp(op1, op2, le);
    }
    float cmp_ge(float op1, float op2)
    {
        return cmp(op1, op2, ge);
    }

    int add_i(int op1, int op2)
    {
        return op1 + op2;
    }
    int sub_i(int op1, int op2)
    {
        return op1 - op2;
    }
    int shift_left(int op, int nBits)
    {
        return op << nBits;
    }
    int shift_right(int op, int nBits)
    {
        unsigned tmp = *reinterpret_cast<unsigned *>(&op);
        unsigned result = tmp >> nBits;
        return *reinterpret_cast<int *>(&result);
    }
} // namespace tests
} // namespace analysis