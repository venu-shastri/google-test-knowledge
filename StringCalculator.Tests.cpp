#include "gtest/gtest.h"
#include "StringCalculator.h"

struct TestDataModel {
	
	string input;
	int expectedResult;
};

TestDataModel createDataModel(string input, int expectedResult) {
	TestDataModel dataModel;
	dataModel.input = input;
	dataModel.expectedResult = expectedResult;
	return dataModel;
}
//Test Fiixture
class StringCalculatorAddTestSuite:public testing::Test {
protected:
	StringCalculator objUnderTest;
	void SetUp(){ }
	void TearDown(){}

	static void SetUpTestSuite(){ }
	static void TearDownTestSuite() {}
};

class StringCalculatorAddParameterTestSuite :public StringCalculatorAddTestSuite, public ::testing::WithParamInterface<TestDataModel> {
protected:

};
TEST_F(StringCalculatorAddTestSuite,GivenEmptyInputZeroIsExpected) {
	//Arrange
	string input = "";
	int expectedResult = 0;
	
	//Act
	int actualResult=objUnderTest.Add(input);

	//Verify
	ASSERT_EQ(actualResult, expectedResult); //Value Based Unit Testing 
}
TEST_F(StringCalculatorAddTestSuite, GivenInputZeroThenZeroIsExpected) {
	//Arrange
	string input = "0";
	int expectedResult = 0;
	
	//Act
	int actualResult = objUnderTest.Add(input);

	//Verify
	ASSERT_EQ(actualResult, expectedResult); //Value Based Unit Testing 
}
TEST_F(StringCalculatorAddTestSuite,GivenNegetiveValueExceptionExpected){
EXPECT_THROW(objUnderTest.Add("1,2,-2"),std::invalid_argument);

}

TEST_P(StringCalculatorAddParameterTestSuite,TestAllPossibleInputs) {
	string input = GetParam().input;
	int expectedResult = GetParam().expectedResult;
	int actualResult=objUnderTest.Add(input);
	EXPECT_EQ(actualResult, expectedResult);

}


INSTANTIATE_TEST_SUITE_P(AddTestWithParam, StringCalculatorAddParameterTestSuite,
	testing::Values(
		createDataModel("", 0),
		createDataModel("0", 0),
		createDataModel("1", 1),
		createDataModel("1,2", 3)));
