#include <iostream>
#include <string>
#include <vector>

class Memento {
	private:
		std::string state;
	public:
		Memento(const std::string &stateSave) : state(stateSave) {}
		std::string getState() const {
			return state;
		}
};

class Originator {
	private:
		std::string state;
	public:
		void setState(const std::string &newState) {
			state = newState;
		}
		std::string getState() {
			return state;
		}
		Memento saveState() {
			return Memento(state);
		}
		void restoreState(const Memento &memento) {
			state = memento.getState();
		}
};

class Caretaker {
	private:
		std::vector<Memento> memos;
	public:
		void addMemento(const Memento &memento) {
			memos.push_back(memento);
		}
		Memento getMemento(int index) {
			if ((index >= 0) and (index < memos.size()))
				return memos[index];
			else
				throw std::out_of_range("index too big");
		}
};

int main() {
	Originator ori;
	Caretaker care;

	ori.setState("s0");
	care.addMemento(ori.saveState());

	ori.setState("s1");
	care.addMemento(ori.saveState());

	std::cout << "Current state: " << ori.getState() << std::endl;

	ori.restoreState(care.getMemento(0));
	
	std::cout << "Current state: " << ori.getState() << std::endl;
	
	ori.restoreState(care.getMemento(1));
	
	std::cout << "Current state: " << ori.getState() << std::endl;

	return 0;
}
