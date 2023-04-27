# Gtest 

Google Test is a xUnit C++ testing framework, All the xUnits have the same basic architecture and follow the same design pattern and generally contain five classes: TestCase, TestRunner, TestFixture, TestSuite, and TestResult



### Main classes of the xUnit test framework architecture



![image-20230426213959972](xUnit test framework architecture)

- The TestSuite acts as a container for TestCase(s)
- A unit test is structured into a TestCase
- The set of preconditions needed for a test can be shared by multiple test cases using TestFixture.
- The TestRunner runs tests, saves, and reports the tests results of TestCase assertions in TestResult.



### TestCase

---

> A unit test should be independent, isolated, and must not affect one another

> Each test case should be structured according to the Arrange-Act-Assert (AAA) pattern

**Arrange:**  Initializes objects, preconditions and sets the value of the data that is required for test.

**Act:**  Invokes the method under test with the arranged parameters.

**Arrange:** Verifies that the expected outcome of the method under test have occurred.

![image-20230426214825602](xUnit TestCase Architecture)

### GOOGLE TEST CHARACTERISTICS

---

- Gtest handles test discovery which means once unit tests are written they are automatically discovered and run by Google Test
- Gtest  comes with a built-in runner which enables running the tests as part of an executable created for those tests
- GTest enables running all of the tests or just a subset of them and performs other test run-related operations using the command line arguments
- Google Test provides a wide scope of assertions
- Google Test also has the ability to run the same test with different parameters
- Google Test has the ability to either value parameterized tests, or type parameterized tests
- Google Tests supports creating readable and customizable reports at the end of the test run either as a console output or as a JUnit compatible XML file



#### GOOGLE TEST ASSERTION:

---

- Assertions are a Boolean statements that encapsulates a specific logic to check whether a condition is true.  

- An assertion’s outcome can be a `success, a non-fatal failure, or a fatal failure`.
- Most Assertions are paired with EXPECT_ and ASSERT_ variants
- The EXPECT_ macro generates nonfatal failures and allow the current test case to continue its evaluation
-  ASSERT_ macros cause fatal failures and termination of test case
- These macros are diversified according to the types to be compared: integer, floating, Boolean, strings.

#### Fatal and Non-fatal Assertions

![image-20230426221023718](Fatal-NonFatal Assertions)

#### Fatal and non-fatal floating points Assertions.



![image-20230426221219568](fatal-nonfatal-floating point)

#### Fatal and non-fatal Exception Assertions.

![image-20230426221512050](Exception Assertions)

- Use the << operator or a series of similar operators to feed a custom failure message into the macro

  .

  ```C++
  ASSERT_EQ(x.size(), y.size()) << "Vectors x and y are of unequal length";
  
  for (int i = 0; i < x.size(); ++i) {
    EXPECT_EQ(x[i], y[i]) << "Vectors x and y differ at index " << i;
  }
  ```

  

### TEST FIXTURES AND PARAMETERIZED TESTS IN GTEST:

---

> A test fixture is a fixed state of a set of objects and preconditions used as a baseline for tests in order to refactor the common code out of the tests and reduce code duplication

##### Test Fixture structure and executing process.

![image-20230426222732463](Test Fixture structure)

> SetUp() method guaranteed to be run before each and every test case

> TearDown() is called afterwards it gives the opportunity to release any resources that may have reserved in the SetUp or during the test

>Since TestFixture  is a class, the class fields can be shared between the tests

>  When using test fixtures,  use TEST_F() macro and not TEST(),

#### Test Fixture in Google Test Framework.

![image-20230426223125252](TestFixture Example)
