#ifndef MATHOPS_TESTS_FIXTURE_HPP
#define MATHOPS_TESTS_FIXTURE_HPP

#include <mathops_shared_fields.hpp>
#include <common/memory_common.inl>

#include <gtest/gtest.h>

namespace analysis
{
namespace tests
{
    class MathopsTests : public testing::Test
    {
    private:
        bool _bigArrTest;

    protected:
        float *_bigArr;

        MathopsTests()
        {
            std::string testName = testing::UnitTest::GetInstance()->current_test_info()->name();
            _bigArrTest = testName.find("Big") != std::string::npos;

            if (_bigArrTest)
            {
                _bigArr = AllocBigArr();
            }
        }

        ~MathopsTests()
        {
            if (_bigArrTest)
            {
                _free_aligned_memory(_bigArr);
            }
        }
    };
} // namespace tests
} // namespace analysis

#endif // MATHOPS_TESTS_FIXTURE_HPP