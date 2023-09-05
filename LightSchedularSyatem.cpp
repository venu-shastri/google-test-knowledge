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
	string getTime() { return ""; }
};
class LightController:public ILightController{
private:
	ILightHardware* hardwareObj;
public:
	void on(){}
	void off() {}
};

class LightSchedular{
private:
	ITimerService* _timerObj;
	ILightController* _controllerObj;
public:
	 void removeSchdule(){}
	 void wakeup(){}
	 void turnSchedularOn() {}

};

