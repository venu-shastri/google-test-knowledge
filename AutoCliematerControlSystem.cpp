class ITempSensor {
public: virtual int getCurrentTemp() = 0;
};
class IOcuSensor {
public: virtual int getCurrentTemp() = 0;
};
class RFDTempSensor:public ITempSensor{
public:
	int getCurrentTemp() { }

};
class OCTSensor:public IOcuSensor{
public:int getCurrentTemp() { }
	};

//interface - abstarction
class ITemperatueRegulator {
public:virtual int  regulateTemp() = 0;
};
//class TemperatueRegulator implements an interface ITemperatueRegulator
// Realization 
//Contarct b/w two objects
class TemperatueRegulator:public ITemperatueRegulator{
private:
	ITempSensor *tempSensor;
	IOcuSensor *ocuuSensor;
public:
	TemperatueRegulator(ITempSensor *tempSensorPtr,IOcuSensor *octSensorPtr):
		tempSensor{ tempSensorPtr }, ocuuSensor{ octSensorPtr }{

	}
	int  regulateTemp() {
		this->tempSensor->getCurrentTemp();
		this->ocuuSensor->getCurrentTemp();
	}
};


class AutoClimateControl{
private:
	//has-a (dependency)
	ITemperatueRegulator *tempRegulator;
public : 
	//Constructor Dependency Injection
	AutoClimateControl(ITemperatueRegulator* ptrToRegulator) : tempRegulator{ ptrToRegulator } {
		//object InVariant Rules
	}
	void on() {
		this->tempRegulator->regulateTemp();
	}
	void off() {}

};









