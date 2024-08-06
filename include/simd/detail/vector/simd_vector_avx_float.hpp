#ifndef SIMD_VECTOR_AVX_FLOAT_HPP
#define SIMD_VECTOR_AVX_FLOAT_HPP

#include <simd/simd_common.hpp>
#include <simd/detail/vector/simd_vector_base.hpp>

#include <vector>

namespace simd
{
    template<typename T, InstructionSet S>
    class SIMDOperations;

    template<>
    class SIMDVector<float, InstructionSet::AVX>
    {
        friend class SIMDOperations<float, InstructionSet::AVX>;

    private:
        using NumType = float;
        static const unsigned VECTOR_SIZE = 8;

        alignas(32) float vector[VECTOR_SIZE];
    public:

        /**
         * @brief Construct a new AVX (256 b) float SIMDVector with all zeros
         */
        SIMDVector();

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
        SIMDVector(NumType n1, NumType n2, NumType n3, NumType n4,
            NumType n5, NumType n6, NumType n7, NumType b8);

        /**
         * @brief Construct a new SIMDVector object from std::vector<float>
         *
         * @param vec Vector with exactly 8 floats
         *
         * @throws {NameOfException} if vector size isnt 8
         */
        SIMDVector(std::vector<NumType> &vec);

        /**
         * @brief Gets content of the vector
         *
         * @return const float[8] array
         */
        const float *get_content() const;
    };
}

#include <simd/detail/vector/simd_vector_avx_float.inl>

#endif // SIMD_VECTOR_AVX_FLOAT_HPP