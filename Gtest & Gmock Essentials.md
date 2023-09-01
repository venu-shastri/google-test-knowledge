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

**Assert:** Verifies that the expected outcome of the method under test have occurred.

![image-20230426214825602](xUnit TestCase Architecture)





## C++ Unit Testing Frameworks comparison.

![image-20230427214910346](test_frameworks_comparison)

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



### MOCKING FOR UNIT TESTS:

---

- In unit testing, a software tester should concentrate on the unit under test (e.g. function, component, class) without integrating its dependencies
- If the dependencies are external systems such as external services, databases, third-party software, data centers, which make the testing process more complex
- Testers may need to simulate interactions with physical target hardware that may not be available.
- When testing a unit that has external dependencies, the execution of the test may slow much effort and cost needed to set up for testing

#### Isolating Dependencies in Tests Using Fake Implementations

![image-20230427212143974](isolate_dependencies)



#### Test Double Hierarchy.

---



![image-20230427212453630](test_doubles)

> `mock` objects were considered to replace real implementation with a fake one that mimics the real dependency and returns the values that the tester tells it to and behaves the way need it to behave for the test to pass



## Handwritten Mock v/s using Mock fx

- The reason behind using a mocking framework is to reduce the amount of code needed, instead of writing those objects by hand, creating complex logic to satisfy as many tests as possible, it is preferable to use a third-party library to perform most of the heavy lifting for a tester 
- The job is usually tedious and error-prone. No wonder people go great distance to avoid it.
- The quality of those manually written mocks is a bit, uh, unpredictable

## GMock

- Google’s C++ Mocking Framework or GMock for short, is an open sourced, free and extendible library for creating fake objects

#### CREATING MOCK OBJECTS:

---

- In Google Mock, Creating a mock object requires `inheritance` from the class we want to mock, the `MOCK_METHOD()` macro is used,
- `MOCK_METHOD()` takes as argument respectively the return value of the method, the name of the method, argument list that the method receives. In case a constant method was mocked, a fourth parameter containing (const) is added
- The Real class must have a virtual destructor as is the case for all classes intend to inherit from.
- All faked methods must be virtual or pure virtual methods so that we’ll be able to override them and change their implementation according to the needs of the test

#### GOOGLE MOCK: SETTING TEST BEHAVIOR:

---

- Use `EXPECT_CALL` to set some behavior 

![image-20230427213756215](expect_call_maro)

#### Google Mock Actions

![image-20230427214024334](mock_actions)

#### GOOGLE MOCK: VERIFYING BEHAVIOR:

---

EXPECT_CALL enables setting behavior on fake object and defining what should happen when a method is called either invoke a different method, return a value, or throw an exception, it also tells google mock to verify that the method we expecting to be called did in fact occurred during a unit test run

![image-20230427214340165](expect_call_behavior)

- We can specify additional multi-argument matchers using `With`
- `Times` : explicitly specify how many times we expect a method to be called
- `InSequence` ensures a specific sequence order to satisfy a test and that the test should fail if the method will be called out of the defined order
- `After` tells google mocks that this call should be done after another call
- `RetiresOnSaturation` :  tells Google Mock to retire the call as it gets saturated

