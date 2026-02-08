#include <iostream>
#include <string>

//concrete
class Car {
	public:
		void setModel(const std::string& model) {
			this->model=model;
		}
		void setValue(const std::string& value) {
			this->value=value;
		}
		void printData() {
			std::cout << "Model: " << model << "\nPrice: " << value << std::endl;
		}
	private:
		std::string model;
		std::string value;
};

//abstract
class CarBuilder {
	public:
		virtual void buildModel() = 0;
		virtual void buildValue() = 0;
		virtual Car getCar() const = 0;
};

class Mercedes: public CarBuilder {
	public:
		void buildModel() override {
			car.setModel("Mercedes");
		}
		void buildValue() override {
			car.setValue("50.000$");
		}
		Car getCar() const override {
			return car;
		}
	private:
		Car car;
};

class Fiat: public CarBuilder {
	public:
		void buildModel() override {
			car.setModel("Fiat");
		}
		void buildValue() override {
			car.setValue("10.000$");
		}
		Car getCar() const override {
			return car;
		}
	private:
		Car car;
};

//Orchestrator - director
class industry {
	public:
		void makeCar(CarBuilder& cb) {
			cb.buildModel();
			cb.buildValue();
		}
};

int main() {
	industry ind;
	
	Fiat fiat_builder;
	ind.makeCar(fiat_builder);
	Car fiat = fiat_builder.getCar();
	fiat.printData();

	Mercedes merc_builder;
	ind.makeCar(merc_builder);
	Car merc = merc_builder.getCar();
	merc.printData();

	return 0;
}
