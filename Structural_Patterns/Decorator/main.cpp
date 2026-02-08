#include <iostream>
#include <string>

using namespace std;

class Pizza {
	public:
		virtual string getName() const = 0;
		virtual double cost() const = 0;
};

class PizzaBianca: public Pizza {
	public:
		string getName() const override {return "Pizza bianca";}
		double cost() const override {return 3.90;}
};

class PizzaDecorator: public Pizza {
	protected:
		Pizza* pizza;
	public:
		PizzaDecorator(Pizza* pi) : pizza(pi) {}
		string getName() const override {return pizza->getName();}
		double cost() const override {return pizza->cost();}
};

class ProsciuttoDecorator: public PizzaDecorator{
	public:
		ProsciuttoDecorator(Pizza* pi) : PizzaDecorator(pi) {}
		string getName() const override {return pizza->getName() + " with prosciutto";}
		double cost() const override{return pizza->cost() + 2.80;}
};

int main() {
	Pizza* pi = new PizzaBianca();
	cout << "order: " << pi->getName() << ", cost: " << pi->cost() << endl;
	Pizza* prosciutto = new ProsciuttoDecorator(pi);
	cout << "order: " << prosciutto->getName() << ", cost: " << prosciutto->cost() << endl;
	delete pi;
	delete prosciutto;
	return 0;
}
