#if defined(HAS_AVX) && defined(HAS_AVX2)

#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>
#include <tests_common.hpp>

#include <gtest/gtest.h>
#include <functional> // std::function
#include <climits>

namespace analysis
{
namespace tests
{
    class SimdAvx2IntTests : public testing::Test
    {
    protected:
        using Ops = simd::SIMDOperations<int, simd::InstructionSet::AVX2>;

        Ops::Reg reg1;
        Ops::Reg reg2;
        Ops::Reg resultReg;

        __m256 floatReg;

        alignas(AVX_ALIGNMENT) const int basicVec1[AVX_INT_VECTOR_SIZE]{ 1, 1, 1, 1, 1, 1, 1, 1 };
        alignas(AVX_ALIGNMENT) const int basicVec2[AVX_INT_VECTOR_SIZE]{ 2, 2, 2, 2, 2, 2, 2, 3 };
        alignas(AVX_ALIGNMENT) const int negativeVec1[AVX_INT_VECTOR_SIZE]{ -1, -3, -6, -7, -134, 1767, 451, 0 };
        alignas(AVX_ALIGNMENT) const int negativeVec2[AVX_INT_VECTOR_SIZE]{ 41, 13, 3, -100, -12, -652, -65, -1 };
        alignas(AVX_ALIGNMENT) const int zerosVec[AVX_INT_VECTOR_SIZE]{ 0, 0, 0, 0, 0, 0, 0 };
        alignas(AVX_ALIGNMENT) const int bigNumVec1[AVX_INT_VECTOR_SIZE]{ -2147483648, 2147483647, 341431412, 5465281, 13153455, 9999999, 47100 };
        alignas(AVX_ALIGNMENT) const int bigNumVec2[AVX_INT_VECTOR_SIZE]{ -1, 1, 130451, 1305051, -11034958, 41281010, 405011 };

        alignas(AVX_ALIGNMENT) const float basicFloatVec[AVX_FLOAT_VECTOR_SIZE]{ 0, 1, -1, 134.134, -451.54, 13415301.4, -624551.7, 0.5 };

        const int *usedVec1;
        const int *usedVec2;

        const float *usedFloatVec;

        void SetRegisters(const int *vec1, const int *vec2)
        {
            reg1 = Ops::load_vector(vec1);
            reg2 = Ops::load_vector(vec2);

            usedVec1 = vec1;
            usedVec2 = vec2;
        }
        void SetRegisters(const int *vec)
        {
            reg1 = Ops::load_vector(vec);

            usedVec1 = vec;
        }
        void SetRegisters(const float *vec)
        {
            floatReg = _mm256_load_ps(vec);

            usedFloatVec = basicFloatVec;
        }

        void CheckResult(const std::function<int(int, int)> &operation)
        {
            alignas(AVX_ALIGNMENT) int result[AVX_INT_VECTOR_SIZE];
            Ops::materialize_register(resultReg, result);

            for (unsigned i = 0; i < AVX_INT_VECTOR_SIZE; i++)
            {
                int expected = operation(usedVec1[i], usedVec2[i]);

                EXPECT_EQ(result[i], expected);
            }
        }
        void CheckResult(int expected, Ops::Reg reg)
        {
            alignas(AVX_ALIGNMENT) int result[AVX_INT_VECTOR_SIZE];
            Ops::materialize_register(reg, result);

            for (unsigned i = 0; i < AVX_INT_VECTOR_SIZE; i++)
            {
                EXPECT_EQ(result[i], expected);
            }
        }
        void CheckResult(const std::function<int(int,int)> &operation, int num)
        {
            alignas(AVX_ALIGNMENT) int result[AVX_INT_VECTOR_SIZE];
            Ops::materialize_register(resultReg, result);

            for (unsigned i = 0; i < AVX_INT_VECTOR_SIZE; i++)
            {
                int expected = operation(usedVec1[i], num);

                EXPECT_EQ(result[i], expected);
            }
        }

        void TestShiftL(const int *vec)
        {
            SetRegisters(vec);

            for (int i = 0; i < sizeof(int) * CHAR_BIT; i++)
            {
                resultReg = Ops::shift_left(reg1, i);
                CheckResult(shift_left, i);
            }
        }

        void TestShiftR(const int *vec)
        {
            SetRegisters(vec);

            for (int i = 0; i < sizeof(int) * CHAR_BIT; i++)
            {
                resultReg = Ops::shift_right(reg1, i);
                CheckResult(shift_right, i);
            }
        }
    };

    TEST_F(SimdAvx2IntTests, LoadStore)
    {
        Ops::Reg reg = Ops::load_vector(basicVec1);
        alignas(AVX_ALIGNMENT) int result[AVX_INT_VECTOR_SIZE];
        Ops::materialize_register(reg, result);

        for (unsigned i = 0; i < AVX_INT_VECTOR_SIZE; i++)
        {
            EXPECT_EQ(result[i], basicVec1[i]);
        }
    }

    TEST_F(SimdAvx2IntTests, SetZeros)
    {
        Ops::Reg reg = Ops::set_register_zero();

        CheckResult(0, reg);
    }

    TEST_F(SimdAvx2IntTests, SetRegister)
    {
        int testNum = 1;

        for (unsigned i = 0; i < 50; i++, testNum += 1, testNum *= -2)
        {
            Ops::Reg reg = Ops::set_register(testNum);

            CheckResult(testNum, reg);
        }
    }

    TEST_F(SimdAvx2IntTests, AddBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add_i);
    }
    TEST_F(SimdAvx2IntTests, AddNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add_i);
    }
    TEST_F(SimdAvx2IntTests, AddZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add_i);
    }
    TEST_F(SimdAvx2IntTests, AddBigNum)
    {
        SetRegisters(bigNumVec1, bigNumVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add_i);
    }

    TEST_F(SimdAvx2IntTests, SubBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub_i);
    }
    TEST_F(SimdAvx2IntTests, SubNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub_i);
    }
    TEST_F(SimdAvx2IntTests, SubZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub_i);
    }
    TEST_F(SimdAvx2IntTests, SubBigNum)
    {
        SetRegisters(bigNumVec1, bigNumVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub_i);
    }

    TEST_F(SimdAvx2IntTests, ShiftLBasic)
    {
        TestShiftL(basicVec1);
    }
    TEST_F(SimdAvx2IntTests, ShiftLNegative)
    {
        TestShiftL(negativeVec1);
    }
    TEST_F(SimdAvx2IntTests, ShiftLZeros)
    {
        TestShiftL(zerosVec);
    }
    TEST_F(SimdAvx2IntTests, ShiftLBigNum)
    {
        TestShiftL(bigNumVec1);
    }
    
    TEST_F(SimdAvx2IntTests, ShiftRBasic)
    {
        TestShiftR(basicVec1);
    }
    TEST_F(SimdAvx2IntTests, ShiftRNegative)
    {
        TestShiftR(negativeVec1);
    }
    TEST_F(SimdAvx2IntTests, ShiftRZeros)
    {
        TestShiftR(zerosVec);
    }
    TEST_F(SimdAvx2IntTests, ShiftRBigNum)
    {
        TestShiftR(bigNumVec1);
    }
} // namespace tests
} // namespace analysis

#endif // HAS_AVX && HAS_AVX2