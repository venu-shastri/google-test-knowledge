#include "gmock/gmock.h"
#include "gtest/gtest.h"
void freefunction() {

}

class Client {
public:
	void operation() {
		freefunction();
	}

};

class AdapterInterface {
public:
	
		virtual void freeFunctionAdaptee() = 0;
};

class FreeFunctionAdapter : public AdapterInterface {
public:

	void freeFunctionAdaptee() {
		freefunction();
	}
};

TEST(MockFreeFunction, UsingAdapter) {

	
}


