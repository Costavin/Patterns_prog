#include <iostream>

class Lights {
	public:
		void TurnOn() {std::cout << "Lights on" <<std::endl;}
		void TurnOff() {std::cout << "Light off" <<std::endl;}
};

class TV {
	public:
		void PowerOn() {std::cout << "TV is powered on" << std::endl;}
		void PowerOff() {std::cout << "TV is powered off" << std::endl;}
};

class ElecAppliance {
	TV tv;
	Lights lights;
	public:
	void On() {
		tv.PowerOn();
		lights.TurnOn();
		std::cout << "TV and lights are on" << std::endl;
	}

	void Off() {
		tv.PowerOff();
		lights.TurnOff();
		std::cout << "TV and lights are off" << std::endl;
	}
};

int main() {
	ElecAppliance ea;
	ea.On();
	ea.Off();

	return 0;
}
