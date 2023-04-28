#include "gmock/gmock.h"
#include "gtest/gtest.h"

//used in production Env
class ConcreteService {
public:
	void operation() {}

};
//used in test Env
class MockService {
public:
	MOCK_METHOD(void, operation, ());

};
template<typename service>
class Client {
	service* dependency;
public:
	Client(service* service) :dependency{ service } {}
	void invokeService() {
		this->dependency->operation();
	}
};
using ::testing::AtLeast;

TEST(Client, MockNonVirtualMethod) {
	MockService mockObject;
	Client<MockService> cutObj(&mockObject);
	EXPECT_CALL(mockObject, operation()).Times(AtLeast(1));
	cutObj.invokeService();

}


