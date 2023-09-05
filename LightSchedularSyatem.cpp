#include <string>
using namespace std;
//interface used for abstraction
class ITimerService {
public:
	virtual string getTime() = 0;
};
class ILightController {
public: 
	//Expectation
	virtual void on() = 0;
	virtual void off() = 0;

};

class IOpertingSystemService {
public:
	virtual void updateTime() = 0;
};

class ILightHardware {
public:
	virtual void open() = 0;
	virtual void close() = 0;
};
class H3OHardware:ILightHardware{
public:
	 void open() {}
	 void close() {}
};

class RTOS :public IOpertingSystemService{
public:
	void updateTime(){}
};

//TimerService implements interface
class TimerService:public ITimerService
 {
 private:
	IOpertingSystemService* rtosObj;
public:
	string getTime() { rtosObj->updateTime(); return ""; }
	TimerService(IOpertingSystemService* rtosArg):rtosObj(rtosArg){}
};
class LightController:public ILightController{
private:
	ILightHardware* hardwareObj;
public:
	LightController(ILightHardware* hwArg): hardwareObj(hwArg){}
	void on(){}
	void off() {}
};

class LightSchedular{
private:
	ITimerService* _timerObj;
	ILightController* _controllerObj;
public:
	LightSchedular(ITimerService* timerArg,ILightController* controllerArg):
		_timerObj(timerArg), _controllerObj(controllerArg){}
	 void removeSchdule(){
		 this->_controllerObj->off();
	 }
	 void wakeup(){
		 this->_timerObj->getTime();
	 }
	 void turnSchedularOn() {
		 this->_controllerObj->on();
	 }


};

/*
class Vehicle{

};
class StartupMotor {};
class FuelPump{};
class Engine {
private :
	FuelPump fuelPumpObj;
	StartupMotor motorObj;
public:
	void crankEngine(){
	   //Delegate -interact 
	}
};
//parent-child (iheritance)
class Car :public Vehicle {
	Engine engObj;
public:
	void start() {
		engObj.crankEngine();
	}

};


class Engine {};
class IVehicle {
public:
	virtual void drive() = 0;
};
class Car:public IVehicle{
	Engine* enginePtr;
public:
	//Constructor Engine
	Car(Engine* engineArg): enginePtr(engineArg) {

	 }
	void drive() {

	}

};
class Person {
public:
	//Dependency Injection (Method Injection)
	void commute(IVehicle* vehiclePtr) {
		 //start using car
		vehiclePtr->drive();
	}

};

int main() {
	Engine engObj;
	Car carObj(&engObj);
	Person personObj;
	personObj.commute(&carObj);

}
*/
