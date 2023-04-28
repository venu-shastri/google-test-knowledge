#include "gmock/gmock.h"
#include "gtest/gtest.h"

class I {
public:
	virtual void M1() = 0;
	virtual void M2(int) = 0;
	virtual int M3(int arg1, int arg2) = 0;
};
class A:I {
public:
	~A(){}
	 void M1(){}
	 void M2(int arg) {}
	 int M3(int arg1, int arg2) { return arg1 + arg2; }

};

class Client {
	I *dependency;
public:
	Client(I *service):dependency{service}{}
	void Invoke_M1() {
		this->dependency->M1();
	}
	void Invoke_M2(int x) {
		this->dependency->M2(x);
	}
	void Invoke_M3(int x,int y) {
		this->dependency->M3(x,y);
	}

};

class Mock_A:public I {
public:
	MOCK_METHOD(void, M1, (), (override));
	MOCK_METHOD(void, M2, (int), (override));
	MOCK_METHOD(int, M3, (int, int), (override));
};

using ::testing::AtLeast;
using ::testing::Return;

TEST(MOCKTEST, Invoke_M1_Test) {
	
	Mock_A mockObj;
	Client cutObj(&mockObj);
	EXPECT_CALL(mockObj, M1()).Times(AtLeast(1));
	EXPECT_CALL(mockObj, M2(10)).Times(AtLeast(1));
	//EXPECT_CALL(mockObj, M3(10,20)).WillOnce(Return(30));
	cutObj.Invoke_M1();
	cutObj.Invoke_M2(10);
	cutObj.Invoke_M3(10, 20);
}


