#include <string>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using namespace std;
class RTOS {};
class Mod42Hardware{};
class ILightController {
public:
	virtual void on(int id) = 0;
	virtual void off(int id) = 0;
};
class ITimeService {
public:
	virtual string getTime() = 0;
	virtual void setPeriodicAlaram() = 0;
};
//Low Level Module
class TimeService :public ITimeService{
	RTOS rtosRef;
public:

	//TimeService
	string getTime() { //Get Time from RTOS
		return "";
	}
	void setPeriodicAlaram() {
		//Talk to RTOS
	}
};
//Low Level Module
class LightController:public ILightController {
private:
	Mod42Hardware hwRef;
public:
	//Light Controller
	void on(int id) {
		//Hardware interaction code
	}
	void off(int id) {
		//Hardware Interaction Code
	}
};
//HihhLevel Module
class LightSchedular {
	//Abstraction
	ILightController* lightController;
	//Abstraction
	ITimeService* timeService;
		
	public:
		//Constructor Dependency Injection
		LightSchedular(ILightController* controllerAddress, ITimeService* timerAddress)
			:lightController{ controllerAddress },
			timeService{ timerAddress } {
		
		}
		/* Schedular Service */
		void scheduleTurnOn(){
			this->lightController->on(0);
		}
		void removeSchedule() {
			this->lightController->off(0);
		}
		void wakeUp() {
			string time = this->timeService->getTime();
			this->scheduleTurnOn();
		}

		


};


class MockTimeService :public ITimeService {
public:
	MOCK_METHOD(string, getTime, ());
	MOCK_METHOD(void, setPeriodicAlaram, ());
	
};
class MockLightController :public ILightController {
public:
	MOCK_METHOD(void, on, (int));
	MOCK_METHOD(void, off, (int));
};

TEST(LightSchedularTestSuite, scheduleTurnOnTest) {
	//Arrange
	MockTimeService timerServiceMock;
	MockLightController lightControllerMock;
	LightSchedular codeUnderTest(&lightControllerMock, &timerServiceMock);

	//SET Expectation

	//Act
	codeUnderTest.scheduleTurnOn();
	
}
TEST(LightSchedularTestSuite, removeScheduleTest) {
	//Arrange
	MockTimeService timerServiceMock;
	MockLightController lightControllerMock;
	LightSchedular codeUnderTest(&lightControllerMock, &timerServiceMock);

	//SET Expectation

	//Act
	codeUnderTest.removeSchedule();

}

TEST(LightSchedularTestSuite, wakeupTest) {
	//Arrange
	MockTimeService timerServiceMock;
	MockLightController lightControllerMock;
	LightSchedular codeUnderTest(&lightControllerMock, &timerServiceMock);

	//SET Expectation

	//Act
	codeUnderTest.wakeUp();

}
