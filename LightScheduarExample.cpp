class RTOS {};
class Mod42Hardware{};
class TimeService {
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
class LightController {
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
class LightSchedular {
	LightController lightController;
	TimeService timeService;
		
	public:
		/* Schedular Service */
		void scheduleTurnOn(){
			this->lightController.on(0);
		}
		void removeSchedule() {
			this->lightController.off(0);
		}
		void wakeUp() {
			string time = this->timeService.getTime();
			this->scheduleTurnOn();
		}

		


};
