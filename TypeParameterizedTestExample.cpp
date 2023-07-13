#include "gtest/gtest.h"
using testing::Types;

class I{
public:
	virtual bool isPrime(int number) = 0;
};
class A:public I{
public :
	bool isPrime(int number) {
		return false;
	}

};
class B:public I{
public:
	bool isPrime(int number) {
		return false;
	}

};

template <typename T>
I* createObject();
template <>
I* createObject<A>() { return new A(); }
template <>
I* createObject<B>() { return new B(); }

//Fixture
template <typename T>
class CommonTextFixture:public testing::Test {
protected:
	I* ptrToObject;
	CommonTextFixture() :ptrToObject{ createObject<T>() } {}
};

typedef Types<A,B> Implementations;

TYPED_TEST_SUITE(CommonTextFixture, Implementations);

TYPED_TEST(CommonTextFixture, ReturnsFalseForNonPrimes) {
	EXPECT_FALSE(this->ptrToObject->isPrime(-5));
}


