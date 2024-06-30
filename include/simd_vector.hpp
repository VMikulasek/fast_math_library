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

        alignas(32) float vector[VECTOR_SIZE];

    public:
        /**
         * @brief Construct a new AVX (256 b) float SIMDVector
         * 
         * @param n1 float 1
         * @param n2 float 2
         * @param n3 float 3
         * @param n4 float 4
         * @param n5 float 5
         * @param n6 float 6
         * @param n7 float 7
         * @param n8 float 8
         */
        SIMDVector(float n1, float n2, float n3, float n4,
            float n5, float n6, float n7, float b8);

        /**
         * @brief Construct a new SIMDVector object from std::vector<float>
         *
         * @param vec Vector with exactly 8 floats
         *
         * @throws {NameOfException} if vector size isnt 8
         */
        SIMDVector(std::vector<float> vec);

        /**
         * @brief Gets content of the vector
         *
         * @return const float[8] array
         */
        const float *get_content();
    };
}

#include "../src/simd_vector.inl"

#endif // SIMD_VECTOR_HPP