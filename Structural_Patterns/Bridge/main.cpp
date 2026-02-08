#include <iostream>

//Abstract interface
class Pizza {
	public:
		virtual void topping() const = 0;
		virtual void shape() const = 0;
};

//Implementation interface
class Margherita: public Pizza {
	public:
		void topping() const override {
			std::cout << "tomato, mozzarella, oregano, basil." << std::endl;
		}
		void shape() const override {
			std::cout << "round." << std::endl; 
		}
};

class Focaccia: public Pizza {
	public:
		void topping() const override {
			std::cout << "tomato, oregano." << std::endl;
		}
		void shape() const override {
			std::cout << "rectangular." << std::endl;
		}
};

//interface 
class Bakery {
	public:
		virtual void getPizza() const = 0;
};

//implementation interface
class ItalianBakery: public Bakery {
	public:
		//Converting constructor
		ItalianBakery(Pizza& piz) : pizza(piz) {}

		void getPizza() const override {
			std::cout << "We baking some pizza today\n" << std::endl;
			pizza.topping();
			pizza.shape();
		}

	private:
		Pizza& pizza;
};

int main() {
	Margherita m;
	Focaccia f;

	ItalianBakery ib1(m);
	ItalianBakery ib2(f);
	
	Bakery* bak1 = &ib1;
	Bakery* bak2 = &ib2;
	bak1->getPizza();
	bak2->getPizza();

	return 0;
}
