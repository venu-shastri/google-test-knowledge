#include <iostream>
#include <string>
#include "gtest/gtest.h"
using namespace std;

//interface  : Essential , public view of the Object
class IDisplyDevice {
public:
	virtual void print(string message) = 0;
};

class ConsoleDisplay :public IDisplyDevice{
	
public:
	void print(string message) {
		cout << message << endl;
		}
}; 

class DisplayController {
	IDisplyDevice* dependency;
public:
	DisplayController(IDisplyDevice* service) {
		this->dependency = service;
	}
	void Display() {
		this->dependency->print("device status is ON");
	}

};

//Hand Made Mock
class FakeDisplayDevice :public IDisplyDevice{
	bool isPrintCalled;
	int callCaridinatility;
	string argumentValue;
		
public:
	bool isPrintCalled;
	int callCaridinatility;
	string argumentValue;
	void print(string message) {
		this->isPrintCalled = true;
		this->callCaridinatility = +1;
		this->argumentValue = message;
	}
};

TEST(DisplayControllerTests, InteractionTesting) {
	//Dependency
	FakeDisplayDevice mockObj;
   //CUT
	DisplayController cutObj(&mockObj);
	cutObj.Display();
	//Expectation
	ASSERT_EQ(mockObj.isPrintCalled, true);
	ASSERT_EQ(mockObj.callCaridinatility, 1);
	string expectedMessage = "device status is ON";
	ASSERT_STREQ(mockObj.argumentValue,expectedMessage );
}

