#include <iostream>
#include <string>

class State {
	public:
		virtual void act() = 0;
};

class AState : public State {
	public:
		void act() override {
			std::cout << "A" << std::endl;
		}
};

class BState : public State {
	public:
		void act() override {
			std::cout << "B" << std::endl;	
		}
};

class CState : public State {
	public:
		void act() override {
			std::cout << "C" << std::endl;	
		}
};

class Context {
	private:
		State *state;
	public:
		Context() : state(new AState()) {}
		void setState(State *newState) {
			state = newState;
		}
		void action() {
			state->act();
		}
};

int main() {
	Context c;
	c.action();
	c.setState(new CState());
	c.action();
	return 0;
}
