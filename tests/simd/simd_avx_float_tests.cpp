#if HAS_AVX

#include <gtest/gtest.h>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>
#include <tests_common.hpp>
#include <functional>

namespace tests
{
    class SimdAvxFloatTest : public testing::Test
    {
    protected:
        using Ops = simd::SIMDOperations<float, simd::AVX>;

        Ops::AvxReg reg1;
        Ops::AvxReg reg2;
        Ops::AvxReg resultReg;

        alignas(AVX_ALIGNMENT) const float basicVec1[AVX_FLOAT_VECTOR_SIZE]{ 1, 1, 1, 1, 1, 1, 1, 1 };
        alignas(AVX_ALIGNMENT) const float basicVec2[AVX_FLOAT_VECTOR_SIZE]{ 2, 2, 2, 2, 2, 2, 2, 3 };
        alignas(AVX_ALIGNMENT) const float decimalVec1[AVX_FLOAT_VECTOR_SIZE] { 1.543, 1.2, 1.134, 1.3, 1.5, 1.13413, 1.1, 1.0 };
        alignas(AVX_ALIGNMENT) const float decimalVec2[AVX_FLOAT_VECTOR_SIZE] { 2.1, 2.2, 2.3, 2.1341, 2.341, 2.34, 2.1324, 3.1431 };
        alignas(AVX_ALIGNMENT) const float negativeVec1[AVX_FLOAT_VECTOR_SIZE] { 1.2, 1.1, 1.2, -1.1, 1.2, -1.1, 1.2, 1.1 };
        alignas(AVX_ALIGNMENT) const float negativeVec2[AVX_FLOAT_VECTOR_SIZE] { -2.1, -2.2, -2.1, -2.2, -2.1, -2.2, -2.1, -3.2 };
        alignas(AVX_ALIGNMENT) const float zerosVec[AVX_FLOAT_VECTOR_SIZE] { 0, 0, 0, 0, 0, 0, 0, 0 };
        alignas(AVX_ALIGNMENT) const float bigNumsVec1[AVX_FLOAT_VECTOR_SIZE] { 134541516143341341534.1, 35736435.0, 674674763465.0, 145598647.3, 354.2, 12413451.1324, 134134112141.12, 123341.1341 };
        alignas(AVX_ALIGNMENT) const float bigNumsVec2[AVX_FLOAT_VECTOR_SIZE] { 1341431.0, 1344313414.0, 13416463.0, 425245264512341341.0, 56335763424522452.0, 76859757.44, 467365573.245, 1341334124351265685.56535 };

        const float *usedVec1;
        const float *usedVec2;

        const int indexHalvesRotatedRight32[8] = { 3, 0, 1, 2, 7, 4, 5, 6 };
        const int indexHalvesRotatedLeft32[8] = { 1, 2, 3, 0, 5, 6, 7, 4 };
        const int indexHalvesRotated64[8] = { 2, 3, 0, 1, 6, 7, 4, 5 };
        const int indexHalvesSwapped[8] = { 4, 5, 6, 7, 0, 1, 2, 3 };
        const int indexLowHalfDistributed[8] = { 0, 1, 2, 3, 0, 1, 2, 3 };
        const int indexHighHalfDistributed[8] = { 4, 5, 6, 7, 4, 5, 6, 7 };

        const int indexPermuteInsideHalvesBasic[8] = { 3, 2, 1, 0, 7, 6, 5, 4 };

        static const int permuteInsideHalvesBasicPattern = 0b00011011;

        void SetRegisters(const float *vec1, const float *vec2)
        {
            reg1 = Ops::load_vector(vec1);
            reg2 = Ops::load_vector(vec2);

            usedVec1 = vec1;
            usedVec2 = vec2;
        }

        float GetExpected(unsigned i, const float *vec1, const float *vec2,
            OperationDirection direction, std::function<float(float,float)> operation)
        {
            if (direction == VERTICAL)
            {
                return operation(vec1[i], vec2[i]);
            }
            else
            {
                i *= 2;
                const float *workingVec;

                if (i < AVX_FLOAT_VECTOR_SIZE / 2)
                {
                    workingVec = vec1;
                }
                else if (i < AVX_FLOAT_VECTOR_SIZE)
                {
                    i -= AVX_FLOAT_VECTOR_SIZE / 2;
                    workingVec = vec2;
                }
                else if (i < AVX_FLOAT_VECTOR_SIZE + AVX_FLOAT_VECTOR_SIZE / 2)
                {
                    i -= AVX_FLOAT_VECTOR_SIZE / 2;
                    workingVec = vec1;
                }
                else
                {
                    i -= AVX_FLOAT_VECTOR_SIZE;
                    workingVec = vec2;
                }

                return operation(workingVec[i], workingVec[i + 1]);
            }
        }

        void CheckResult(std::function<float(float, float)> operation, OperationDirection direction = VERTICAL)
        {
            alignas(AVX_ALIGNMENT) float result[AVX_FLOAT_VECTOR_SIZE];
            Ops::materialize_register(resultReg, result);

            for (unsigned i = 0; i < AVX_FLOAT_VECTOR_SIZE; i++)
            {
                float expected = GetExpected(i, usedVec1, usedVec2, direction, operation);

                // cast to int to compare bitwise, to dodge NaN non equality
                int expectedI = *reinterpret_cast<int *>(&expected);
                int resultI = *reinterpret_cast<int *>(&(result[i]));

                EXPECT_EQ(resultI, expectedI);
            }
        }

        void CheckOneOperandOperationResult(const int *indexes)
        {
            alignas(AVX_ALIGNMENT) float result[AVX_FLOAT_VECTOR_SIZE];
            Ops::materialize_register(resultReg, result);

            for (unsigned i = 0; i < AVX_FLOAT_VECTOR_SIZE; i++)
            {
                float expected = usedVec1[indexes[i]];

                int expectedI = *reinterpret_cast<int *>(&expected);
                int resultI = *reinterpret_cast<int *>(&(result[i]));

                EXPECT_EQ(resultI, expectedI);
            }
        }
    };

    TEST_F(SimdAvxFloatTest, LoadStore)
    {
        alignas(AVX_ALIGNMENT) const float vec[AVX_FLOAT_VECTOR_SIZE]{ 2, 2, 2, 2, 2, 2, 2, 2 };
        
        Ops::AvxReg reg = Ops::load_vector(vec);
        alignas(AVX_ALIGNMENT) float result[AVX_FLOAT_VECTOR_SIZE];
        Ops::materialize_register(reg, result);

        for (unsigned i = 0; i < AVX_FLOAT_VECTOR_SIZE; i++)
        {
            EXPECT_FLOAT_EQ(result[i], 2);
        }
    }

    TEST_F(SimdAvxFloatTest, LoadZeros)
    {
        Ops::AvxReg reg = Ops::load_zero_vector();

        alignas(AVX_ALIGNMENT) float result[AVX_FLOAT_VECTOR_SIZE];
        Ops::materialize_register(reg, result);

        for (unsigned i = 0; i < AVX_FLOAT_VECTOR_SIZE; i++)
        {
            EXPECT_FLOAT_EQ(result[i], 0);
        }
    }

    TEST_F(SimdAvxFloatTest, AddBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
    TEST_F(SimdAvxFloatTest, AddBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, SubBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }
    TEST_F(SimdAvxFloatTest, SubBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::sub(reg1, reg2);

        CheckResult(sub);
    }

    TEST_F(SimdAvxFloatTest, MulBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulDecimalZeros)
    {
        SetRegisters(decimalVec1, zerosVec);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }
    TEST_F(SimdAvxFloatTest, MulBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::mul(reg1, reg2);

        CheckResult(mul);
    }

    TEST_F(SimdAvxFloatTest, DivBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivDecimalZeros)
    {
        SetRegisters(decimalVec1, zerosVec);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }
    TEST_F(SimdAvxFloatTest, DivBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::div(reg1, reg2);

        CheckResult(div);
    }

    TEST_F(SimdAvxFloatTest, And1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, AndZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }
    TEST_F(SimdAvxFloatTest, And4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_and(reg1, reg2);

        CheckResult(bitwise_and);
    }

    TEST_F(SimdAvxFloatTest, Or1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, OrZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }
    TEST_F(SimdAvxFloatTest, Or4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_or(reg1, reg2);

        CheckResult(bitwise_or);
    }

    TEST_F(SimdAvxFloatTest, Xor1)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor2)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor3)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, XorZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }
    TEST_F(SimdAvxFloatTest, Xor4)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::bitwise_xor(reg1, reg2);

        CheckResult(bitwise_xor);
    }

    TEST_F(SimdAvxFloatTest, LTAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }
    TEST_F(SimdAvxFloatTest, LTMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LT>(reg1, reg2);

        CheckResult(cmp_lt);
    }

    TEST_F(SimdAvxFloatTest, GTAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }
    TEST_F(SimdAvxFloatTest, GTMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GT>(reg1, reg2);

        CheckResult(cmp_gt);
    }

    TEST_F(SimdAvxFloatTest, EQAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }
    TEST_F(SimdAvxFloatTest, EQMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::EQ>(reg1, reg2);

        CheckResult(cmp_eq);
    }

    TEST_F(SimdAvxFloatTest, LEAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }
    TEST_F(SimdAvxFloatTest, LEMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::LE>(reg1, reg2);

        CheckResult(cmp_le);
    }

    TEST_F(SimdAvxFloatTest, GEAllLess)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEAllGreater)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEAllEq)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }
    TEST_F(SimdAvxFloatTest, GEMixed)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::cmp<simd::AvxCmpVariant::GE>(reg1, reg2);

        CheckResult(cmp_ge);
    }

    TEST_F(SimdAvxFloatTest, HaddBasic)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::horizontal_add(reg1, reg2);

        CheckResult(add, HORIZONTAL);
    }
    TEST_F(SimdAvxFloatTest, HaddDecimal)
    {
        SetRegisters(decimalVec1, decimalVec2);

        resultReg = Ops::horizontal_add(reg1, reg2);

        CheckResult(add, HORIZONTAL);
    }
    TEST_F(SimdAvxFloatTest, HaddNegative)
    {
        SetRegisters(negativeVec1, negativeVec2);

        resultReg = Ops::horizontal_add(reg1, reg2);

        CheckResult(add, HORIZONTAL);
    }
    TEST_F(SimdAvxFloatTest, HaddZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::horizontal_add(reg1, reg2);

        CheckResult(add, HORIZONTAL);
    }
    TEST_F(SimdAvxFloatTest, HaddBigNums)
    {
        SetRegisters(bigNumsVec1, bigNumsVec2);

        resultReg = Ops::horizontal_add(reg1, reg2);

        CheckResult(add, HORIZONTAL);
    }

    TEST_F(SimdAvxFloatTest, BlendZigZag)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b01010101;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }
    TEST_F(SimdAvxFloatTest, BlendAllZero)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b00000000;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }
    TEST_F(SimdAvxFloatTest, BlendAllOne)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b11111111;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }
    TEST_F(SimdAvxFloatTest, BlendHalved1)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b00001111;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }
    TEST_F(SimdAvxFloatTest, BlendHalved2)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b11110000;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }
    TEST_F(SimdAvxFloatTest, BlendNonSpecific)
    {
        SetRegisters(basicVec1, basicVec2);
        const int mask = 0b00101011;

        resultReg = Ops::blend<mask>(reg1, reg2);

        CheckResult(blend<mask>);
    }

    TEST_F(SimdAvxFloatTest, RotateRight32Homogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::rotate_halves_right_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedRight32);
    }
    TEST_F(SimdAvxFloatTest, RotateRight32HomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::rotate_halves_right_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedRight32);
    }
    TEST_F(SimdAvxFloatTest, RotateRight32Heterogeneous1)
    {
        SetRegisters(decimalVec1, decimalVec1);

        resultReg = Ops::rotate_halves_right_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedRight32);
    }
    TEST_F(SimdAvxFloatTest, RotateRight32Heterogeneous2)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::rotate_halves_right_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedRight32);
    }
    TEST_F(SimdAvxFloatTest, RotateRight32Heterogeneous3)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::rotate_halves_right_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedRight32);
    }

    TEST_F(SimdAvxFloatTest, RotateLeft32Homogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::rotate_halves_left_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedLeft32);
    }
    TEST_F(SimdAvxFloatTest, RotateLeft32HomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::rotate_halves_left_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedLeft32);
    }
    TEST_F(SimdAvxFloatTest, RotateLeft32Heterogeneous1)
    {
        SetRegisters(decimalVec1, decimalVec1);

        resultReg = Ops::rotate_halves_left_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedLeft32);
    }
    TEST_F(SimdAvxFloatTest, RotateLeft32Heterogeneous2)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::rotate_halves_left_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedLeft32);
    }
    TEST_F(SimdAvxFloatTest, RotateLeft32Heterogeneous3)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::rotate_halves_left_32bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotatedLeft32);
    }

    TEST_F(SimdAvxFloatTest, Rotate64Homogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::rotate_halves_64bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotated64);
    }
    TEST_F(SimdAvxFloatTest, Rotate64HomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::rotate_halves_64bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotated64);
    }
    TEST_F(SimdAvxFloatTest, Rotate64Heterogeneous1)
    {
        SetRegisters(decimalVec1, decimalVec1);

        resultReg = Ops::rotate_halves_64bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotated64);
    }
    TEST_F(SimdAvxFloatTest, Rotate64Heterogeneous2)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::rotate_halves_64bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotated64);
    }
    TEST_F(SimdAvxFloatTest, Rotate64Heterogeneous3)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::rotate_halves_64bits(reg1);

        CheckOneOperandOperationResult(indexHalvesRotated64);
    }

    TEST_F(SimdAvxFloatTest, SwapHalvesHomogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::swap_halves(reg1);

        CheckOneOperandOperationResult(indexHalvesSwapped);
    }
    TEST_F(SimdAvxFloatTest, SwapHalvesHomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::swap_halves(reg1);

        CheckOneOperandOperationResult(indexHalvesSwapped);
    }
    TEST_F(SimdAvxFloatTest, SwapHalvesHeterogeneous1)
    {
        SetRegisters(decimalVec1, decimalVec1);

        resultReg = Ops::swap_halves(reg1);

        CheckOneOperandOperationResult(indexHalvesSwapped);
    }
    TEST_F(SimdAvxFloatTest, SwapHalvesHeterogeneous2)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::swap_halves(reg1);

        CheckOneOperandOperationResult(indexHalvesSwapped);
    }
    TEST_F(SimdAvxFloatTest, SwapHalvesHeterogeneous3)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::swap_halves(reg1);

        CheckOneOperandOperationResult(indexHalvesSwapped);
    }

    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesBasicHomogeneous)
    {
        SetRegisters(basicVec1, basicVec2);

        resultReg = Ops::permute_reg_inside_halves<permuteInsideHalvesBasicPattern>(reg1);

        CheckOneOperandOperationResult(indexPermuteInsideHalvesBasic);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesBasicHomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::permute_reg_inside_halves<permuteInsideHalvesBasicPattern>(reg1);

        CheckOneOperandOperationResult(indexPermuteInsideHalvesBasic);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesBasicHeterogeneous1)
    {
        SetRegisters(decimalVec1, decimalVec1);

        resultReg = Ops::permute_reg_inside_halves<permuteInsideHalvesBasicPattern>(reg1);

        CheckOneOperandOperationResult(indexPermuteInsideHalvesBasic);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesBasicHeterogeneous2)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::permute_reg_inside_halves<permuteInsideHalvesBasicPattern>(reg1);

        CheckOneOperandOperationResult(indexPermuteInsideHalvesBasic);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesBasicHeterogeneous3)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::permute_reg_inside_halves<permuteInsideHalvesBasicPattern>(reg1);

        CheckOneOperandOperationResult(indexPermuteInsideHalvesBasic);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesSameIndex)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::permute_reg_inside_halves<0b10101010>(reg1);

        const int indexHalves[8] = { 2, 2, 2, 2, 6, 6, 6, 6 };
        CheckOneOperandOperationResult(indexHalves);
    }
    TEST_F(SimdAvxFloatTest, PermuteInsideHalvesZigZag)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::permute_reg_inside_halves<0b00110011>(reg1);

        const int indexHalves[8] = { 3, 0, 3, 0, 7, 4, 7, 4 };
        CheckOneOperandOperationResult(indexHalves);
    }

    TEST_F(SimdAvxFloatTest, DistributeLowHalfHomogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::distribute_low_half(reg1);

        CheckOneOperandOperationResult(indexLowHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeLowHalfHomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::distribute_low_half(reg1);

        CheckOneOperandOperationResult(indexLowHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeLowHalfHeterogeneous1)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::distribute_low_half(reg1);

        CheckOneOperandOperationResult(indexLowHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeLowHalfHeterogeneous2)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::distribute_low_half(reg1);

        CheckOneOperandOperationResult(indexLowHalfDistributed);
    }

    TEST_F(SimdAvxFloatTest, DistributeHighHalfHomogeneous)
    {
        SetRegisters(basicVec1, basicVec1);

        resultReg = Ops::distribute_high_half(reg1);

        CheckOneOperandOperationResult(indexHighHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeHighHalfHomogeneousZeros)
    {
        SetRegisters(zerosVec, zerosVec);

        resultReg = Ops::distribute_high_half(reg1);

        CheckOneOperandOperationResult(indexHighHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeHighHalfHeterogeneous1)
    {
        SetRegisters(negativeVec1, negativeVec1);

        resultReg = Ops::distribute_high_half(reg1);

        CheckOneOperandOperationResult(indexHighHalfDistributed);
    }
    TEST_F(SimdAvxFloatTest, DistributeHighHalfHeterogeneous2)
    {
        SetRegisters(bigNumsVec1, bigNumsVec1);

        resultReg = Ops::distribute_high_half(reg1);

        CheckOneOperandOperationResult(indexHighHalfDistributed);
    }
} // namespace tests

#endif // HAS_AVX