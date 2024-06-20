#ifndef SIMD_VECTOR_HPP
#define SIMD_VECTOR_HPP

#include "simd_common.hpp"

#include <vector>

namespace simd
{
    template<typename T, InstructionSet S>
    class SIMDVector;

    template<>
    class SIMDVector<float, InstructionSet::AVX>
    {
    private:
        const static unsigned VECTOR_SIZE = 8;

        float vector[VECTOR_SIZE];

    public:
        /**
         * @brief Construct a new AVX (256 B) float SIMDVector
         * 
         * @param op1 float 1
         * @param op2 float 2
         * @param op3 float 3
         * @param op4 float 4
         * @param op5 float 5
         * @param op6 float 6
         * @param op7 float 7
         * @param op8 float 8
         */
        SIMDVector(float f1, float f2, float f3, float f4,
            float f5, float f6, float f7, float f8);

        /**
         * @brief Construct a new SIMDVector object from std::vector<float>
         * 
         * @param vec Vector with exactly 8 floats
         * 
         * @throws {NameOfException} if vector size isnt 8
         */
        SIMDVector(std::vector<float> vec);
    };
}

#include "../src/simd_vector.inl";

#endif // SIMD_VECTOR_HPP