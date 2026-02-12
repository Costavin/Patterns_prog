#include <string>
#include <iostream>

class MagicStone;
class Wand;

class Visitor {
	public:
		virtual void visit(Wand &wand) =0;
		virtual void visit(MagicStone &mstone) =0;
};


class Object {
	public:
		virtual void accept(Visitor &visitor) =0;
		virtual std::string getName() =0;
};

class MagicStone: public Object {
	public:
		MagicStone() {
			name = "Philosopher's stone";
		}
		void accept(Visitor &visitor) override {
			visitor.visit(*this);
		}
		std::string getName() override {
			return name;
		}
	private:
		std::string name;
};

class Wand: public Object {
	public:
		Wand() {
			name = "Wando";
		}
		void accept(Visitor &visitor) override {
			visitor.visit(*this);
		}
		std::string getName() override {
			return name;
		}
	private:
		std::string name;
};

class Wizard: public Visitor {
	public:
		void visit(Wand &wand) override {
			std::cout << "A wizard interacts with the " << wand.getName() << " and it start's to light up" << std::endl;
		}
		void visit(MagicStone &mstone) override {
			std::cout << "A wizard interacts with the " << mstone.getName() << " and it seems that usually it's the wand that chooses the wizard, and not the other way around" << std::endl;
		}
};

class Muggle: public Visitor {
	public:
		void visit(Wand &wand) override {
			std::cout << "A muggle interacts with the " << wand.getName() << " and nothing happens" << std::endl;
		}
		void visit(MagicStone &mstone) override {
			std::cout << "A muggle interacts with the " << mstone.getName() << " and still nothing happens" << std::endl;
		}
};


int main() {
	Muggle mug;
	Wizard wiz;
	MagicStone ms;
	Wand wa;
	wa.accept(mug);
	wa.accept(wiz);
	ms.accept(mug);
	ms.accept(wiz);
	return 0;
}
