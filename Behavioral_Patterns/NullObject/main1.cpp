#include <iostream>

class Car {
	public:
		virtual void drive() const =0;
		virtual void stop() const =0;
};

class Mercedes: public Car {
	public:
		void drive() const override {
			std::cout << "mercedes is moving" << std::endl;
		}
		void stop() const override {
			std::cout << "mercedes is still" << std::endl;
		}
};

class Ferrari: public Car {
	public:
		void drive() const override {
			std::cout << "ferrari is moving" << std::endl;
		}
		void stop() const override {
			std::cout << "ferrari is still" << std::endl;
		}
};

class NullCar: public Car {
	public:
		void drive() const override {}
		void stop() const override {}
};

class Rental {
	private:
		Car& car;
	public:
		Rental(Car& car): car(car) {}
		void testCar() {
			car.drive();
			car.stop();
		}
};

int main() {
	Mercedes merc;
	Ferrari fer;
	NullCar nc;

	Rental r1(merc);
	Rental r2(fer);
	Rental r3(nc);

	r1.testCar();
	r2.testCar();
	r3.testCar();

	return 0;
}
