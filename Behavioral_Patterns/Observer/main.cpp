#include <vector>
#include <iostream>
#include <algorithm>

class Observer {
	public:
		virtual void update(float sensor1, float seasor2, float sensor3) = 0;
		virtual ~Observer() {}
};

class Subject {
	public:
		virtual void setObserver(Observer* observer) =0;
		virtual void removeObserver(Observer* observer) =0;
		virtual void notifyObservers() =0;
		virtual ~Subject() {}
};

class Sensor: public Subject {
	private:
		std::vector<Observer*> observers;
		float sensor1, sensor2, sensor3;
	public:
		void setObserver(Observer* observer) override {
			observers.push_back(observer);
		}
		void removeObserver(Observer* observer) override {
			observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
		}
		void notifyObservers() override {
			for (Observer* observer : observers) 
				observer->update(sensor1,sensor2,sensor3);
		}
		void setSensors(float sensor1,float sensor2,float sensor3) {
			this->sensor1 = sensor1;
			this->sensor2 = sensor2;
			this->sensor3 = sensor3;
			notifyObservers();
		}
};

class Display: public Observer {
	void update(float sensor1, float sensor2, float sensor3) override {
		std::cout << "Sensor1: " << sensor1 << " Sensor2: " << sensor2 << " Sensor3: " << sensor3 << std::endl;
	}
};

int main() {
	Sensor sensors;

	Display d1;
	Display d2;
	sensors.setObserver(&d1);
	sensors.setObserver(&d2);

	sensors.setSensors(3.9,7.2,8.9);
	sensors.setSensors(-1.2,7.9,12.9);

	return 0;
}
