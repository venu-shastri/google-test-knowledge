#include "gtest/gtest.h"
class NumberHelper {
public:
	bool isEven(int num) {
		return num % 2 == 0;
	}
};

TEST(EVENTEST, TEST1) {
	NumberHelper _helper;
	ASSERT_TRUE(_helper.isEven(10));
}
TEST(EVENTEST, TEST2) {
	NumberHelper _helper;
	ASSERT_TRUE(_helper.isEven(20));
}
TEST(EVENTEST, TEST3) {
	NumberHelper _helper;
	ASSERT_TRUE(_helper.isEven(11));

}

// make the code DRYer is to create a fixture and get rid of the initialization of NumberHelper
class NumberHelperFixture:public testing::Test {
protected:NumberHelper _helper;
};
TEST_F(NumberHelperFixture, TEST1) {
	
	ASSERT_TRUE(_helper.isEven(10));
}
TEST_F(NumberHelperFixture, TEST2) {
	
	ASSERT_TRUE(_helper.isEven(20));
}
TEST_F(NumberHelperFixture, TEST3) {
	
	ASSERT_TRUE(_helper.isEven(11));

}

//using For loop
TEST(EvenIterationTest, PrimeNumbersOrEvenNUmbers) {
	NumberHelper helper;
	auto primeNumbers = std::vector<int>{ 1, 3, 7,9 };
	for (auto number : primeNumbers) {
		ASSERT_TRUE(helper.isEven(number));
	}
}

//Parameterized tests
class NumberHelperParameterizedTestsFixture :public ::testing::TestWithParam<int> {
protected:
	NumberHelper helper;
};
TEST_P(NumberHelperParameterizedTestsFixture, EvenNumberParameterizedTest) {
	int item = GetParam();
	ASSERT_TRUE(helper.isEven(item));
}

INSTANTIATE_TEST_SUITE_P(NumberHelperParameterizedTestSuite,
	NumberHelperParameterizedTestsFixture,
	testing::Values(10, 20, 33));


//Multiple Parameters
class NumberHelperMultipleParametersTests :public ::testing::TestWithParam<std::tuple<int, bool>> {
protected:
	NumberHelper helper;
};

TEST_P(NumberHelperMultipleParametersTests, ChecksIfNumberIsEven) {
	bool expected = std::get<1>(GetParam());
	int number = std::get<0>(GetParam());
	ASSERT_EQ(expected, helper.isEven(number));
}

INSTANTIATE_TEST_SUITE_P(
	MultipleParatemetrizedTests,
	NumberHelperMultipleParametersTests,
	::testing::Values(
		std::make_tuple(7, false),
		std::make_tuple(10, true),
		std::make_tuple(100, true),
		std::make_tuple(101, false)
		));