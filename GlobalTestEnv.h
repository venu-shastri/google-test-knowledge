#pragma once
#include "gtest/gtest.h"
using namespace testing;
class GlobalTestEnvironment : public Environment {
public:
	~GlobalTestEnvironment()  {}

	// Override this to define how to set up the environment.
	void SetUp()  {}

	// Override this to define how to tear down the environment.
	void TearDown()  {}
};
