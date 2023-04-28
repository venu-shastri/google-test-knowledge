## Parameterized Tests

- First, we need to create our parameterized test class. Let’s call it `NumberHelperParameterizedTestsFixture` and it has inherit to from `::testing::TestWithParam<T>`
- `T` is a template parameter and it is going to be the type of the parameter or parameters we want to pass into each iteration

```C++
class NumberHelperParameterizedTestsFixture :public ::testing::TestWithParam<int> {
protected:
    NumberHelper helper;
};
```

- Next, we need a test case with an assertion in it.

```C++
TEST_P(NumberHelperParameterizedTestsFixture, EvenNumberParameterizedTest) {
	int item = GetParam();
	ASSERT_TRUE(helper.isEven(item));
}
```

- Finally, you can use the `INSTANTIATE_TEST_SUITE_P` macro to instantiate the test suite with any set of parameters you want

```C++
INSTANTIATE_TEST_SUITE_P(NumberHelperParameterizedTestSuite,
                         NumberHelperParameterizedTestsFixture,
                         testing::Values(10,20,30));
```

- The first argument to `INSTANTIATE_TEST_SUITE_P` is a unique name for the instantiation of the test suite
- The next argument is the name of the test pattern
-  The last is the `Parameter Generator`

![image-20230428062352039](E:\google-test-knowledge\ValueParamterizedTests)

### Parameter Generator

---

![image-20230428062907034](E:\google-test-knowledge\ParameterGenerator)

### How to pass multiple parameters to the same test case?

---

Let’s say you have two inputs that you want to parameterize, or you want to pass both the input and the output! What can you do?



```C++
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
        NumberHelperParatemetrizedTests,
        NumberHelperMultipleParametersTests,
        ::testing::Values(
                std::make_tuple(7, false),
                std::make_tuple(10, true),
                std::make_tuple(100, true),
                std::make_tuple(101, false)));
```

