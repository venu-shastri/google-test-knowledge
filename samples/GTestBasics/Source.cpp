#include "gtest/gtest.h"

int add(int x, int y) { return x + y; }

TEST(AddTest, AssertTure) {
	EXPECT_EQ(add(10, 20), 30);
}
int main() {

	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}