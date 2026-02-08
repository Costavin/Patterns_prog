#include <iostream>

class Shape {
	public:
		virtual void draw() = 0;
		virtual ~Shape() {}
};

class Circle: public Shape {
	public:
		void draw() override {
			std::cout << "Circle" << std::endl;
		}
};

class Square: public Shape {
	public:
		void draw() override {
			std::cout << "Square." << std::endl;
		}
};

class ShapeFactory {
	public:
		virtual Shape* createShape() = 0;
		virtual ~ShapeFactory() {}
};


class CircleFactory: public ShapeFactory {
	public:
		Shape* createShape() override {
			return new Circle();
		}
};

class SquareFactory: public ShapeFactory {
	public:
		Shape* createShape() override {
			return new Square();
		}
};

ShapeFactory* getFactory(char type) {
	if (type == 'C')
		return new CircleFactory();
	else if (type == 'S')
		return new SquareFactory();
	else
		return nullptr;
};

int main() {
	char userChoice;
	std::cout << "Enter choice between: C for circle, S for square." << std::endl;
	std::cin >> userChoice;
	ShapeFactory* sf = getFactory(userChoice);
	if (sf) {
		Shape* s = sf->createShape();
		s->draw();
		delete s;
		delete sf;
	}
	return 0;
}
