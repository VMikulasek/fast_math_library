#include <gtest/gtest.h>
#include <simd/simd_vector.hpp>
#include <simd/simd_operations.hpp>
#include <simd/simd_common.hpp>
#include <tests_common.hpp>
#include <functional>

namespace tests
{
    class SimdAvxFloatTest : public testing::Test
    {
    protected:

        using Vec = simd::SIMDVector<float, simd::AVX>;
        using Ops = simd::SIMDOperations<float, simd::AVX>;

        const unsigned VECTOR_LEN = 8;

        Ops::AvxReg reg1;
        Ops::AvxReg reg2;
        Ops::AvxReg resultReg;

        Vec vec1;
        Vec vec2;

        void SetRegisters()
        {
            reg1 = Ops::load_vector(vec1);
            reg2 = Ops::load_vector(vec2);
        }

        void CheckResult(std::function<float(float, float)> operation)
        {
            Vec resultVec = Ops::materialize_register(resultReg);
            const float *result = resultVec.get_content();

            const float *vec1Content = vec1.get_content();
            const float *vec2Content = vec2.get_content();

            for (unsigned i = 0; i < VECTOR_LEN; i++)
            {
                EXPECT_EQ(result[i], operation(vec1Content[i], vec2Content[i]));
            }
        }
    };

    TEST_F(SimdAvxFloatTest, LoadStore)
    {
        const unsigned avxFloatVectorSize = 8;
        const float testVal = 2;
        simd::SIMDVector<float, simd::AVX> vec(
            testVal, testVal, testVal, testVal,
            testVal, testVal, testVal, testVal
        );
        
        simd::SIMDOperations<float, simd::AVX>::AvxReg reg = simd::SIMDOperations<float, simd::AVX>::load_vector(vec);
        vec = simd::SIMDOperations<float, simd::AVX>::materialize_register(reg);
        const float *content = vec.get_content();

        for (unsigned i = 0; i < 8; i++)
        {
            EXPECT_EQ(content[i], 2);
        }
    }

    TEST_F(SimdAvxFloatTest, AddBasic)
    {
        vec1 = Vec(1, 1, 1, 1, 1, 1, 1, 1);
        vec2 = Vec(2, 2, 2, 2, 2, 2, 2, 3);
        SetRegisters();

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, AddDecimal)
    {
        vec1 = Vec(1.543, 1.2, 1.134, 1.3, 1.5, 1.13413, 1.1, 1.0);
        vec2 = Vec(2.1, 2.2, 2.3, 2.1341, 2.341, 2.34, 2.1324, 3.1431);
        SetRegisters();

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, AddNegative)
    {
        vec1 = Vec(1.2, 1.1, 1.2, 1.1, 1.2, 1.1, 1.2, 1.1);
        vec2 = Vec(-2.1, -2.2, -2.1, -2.2, -2.1, -2.2, -2.1, -3.2);
        SetRegisters();

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, AddZeros)
    {
        vec1 = Vec(0, 0, 0, 0, 0, 0, 0, 0);
        vec2 = Vec(0, 0, 0, 0, 0, 0, 0, 0);
        SetRegisters();

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }

    TEST_F(SimdAvxFloatTest, AddBigNums)
    {
        vec1 = Vec(134541516143341341534.1, 35736435, 674674763465, 145598647.3, 354.2, 12413451.1324, 134134112141.12, 123341.1341);
        vec2 = Vec(1341431, 1344313414, 13416463, 425245264512341341, 56335763424522452, 76859757.44, 467365573.245, 1341334124351265685.56535);
        SetRegisters();

        resultReg = Ops::add(reg1, reg2);

        CheckResult(add);
    }
}