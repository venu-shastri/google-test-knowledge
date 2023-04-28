#include "gtest/gtest.h"
#include <string>
using namespace std;
template<typename T>
auto concat(T operand_one, T operand_two) {
	return operand_one + operand_two;
}

template<typename T>
class ConcatTestsFixture:public ::testing::Test {

};
TYPED_TEST_SUITE_P(ConcatTestsFixture);

TYPED_TEST_P(ConcatTestsFixture, doConcatOnInt) {
	ASSERT_EQ(concat<TypeParam>(10,20),30) << "concat(10,20) == 30!";
}

REGISTER_TYPED_TEST_SUITE_P(ConcatTestsFixture, doConcatOnInt);

using Types = testing::Types<int>;
INSTANTIATE_TYPED_TEST_SUITE_P(TestPrefix, ConcatTestsFixture, Types);