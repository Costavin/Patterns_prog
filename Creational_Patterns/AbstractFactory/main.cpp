#include <iostream>

//Abstract interface class
class Mammal {
	public:
		virtual void sound() = 0;
		virtual void weight() = 0;
};

//Concrete class
class Dog : public Mammal {
	public:
		void sound() override {
			std::cout << "barf barf" << std::endl;
		}
		void weight() override {
			std::cout << "12kg" << std::endl;
		}
};

class Cat : public Mammal {
	public:
		void sound() override {
			std::cout << "miao" << std::endl;
		}
		void weight() override {
			std::cout << "6kg" << std::endl;
		}
};

class Whale : public Mammal {
	public:
		void sound() override {
			std::cout << "..." << std::endl;	
		}
		void weight() override {
			std::cout << ">>100kg" << std::endl;
		}
};

//Abstract factory interface
class Animal {
	public:
		virtual Mammal* createFirst() = 0;
		virtual Mammal* createSecond() = 0;
};

//Concrete factory
class SmallAnimal: public Animal {
	public:
		Mammal* createFirst() override {
			return new Dog();
		}
		Mammal* createSecond() override {
			return new Cat();
		}
};

class BigAnimal: public Animal {
	public:
		Mammal* createFirst() override {
			return new Whale();
		}
		Mammal* createSecond() override {
			return nullptr;
		}
};

int main() {

	Animal* sa = new SmallAnimal();
	Mammal* dog = sa->createFirst();
	Mammal* cat = sa->createSecond();

	Animal* ba = new BigAnimal();
	Mammal* whale = ba->createFirst();
	
	dog->sound();
	dog->weight();

	cat->sound();
	cat->weight();

	whale->sound();
	whale->weight();

	return 0;
}
