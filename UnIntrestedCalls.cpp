#include "gmock/gmock.h"
#include "gtest/gtest.h"

class IService {
public:
	virtual ~IService(){}
	virtual void operation() = 0;
};

class RealService:public IService {
public:
	void operation(){}

};
class Client {
	IService* dependency;
public:
	Client(IService* service):dependency{service}{}
	void invokeService() {
		this->dependency->operation();
	}
};
class MockService :public IService {
public:
	MOCK_METHOD(void, operation, (), (override));
};

TEST(Client, UnIntrestedCall_Naggy) {
	MockService mockObject;
	Client cutObj(&mockObject);
	cutObj.invokeService();

}
using ::testing::NiceMock;
TEST(Client, UnIntrestedCall_Nice) {
	NiceMock<MockService> mockObject;
	Client cutObj(&mockObject);
	cutObj.invokeService();

}

using ::testing::StrictMock;

TEST(Client, UnIntrestedCall_strict) {
	StrictMock<MockService> mockObject;
	Client cutObj(&mockObject);
	cutObj.invokeService();

}



