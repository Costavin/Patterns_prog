#include <string>
#include <iostream>

class System {
	public:
		virtual void notifyMediator(const std::string &value) =0;
		virtual void interact() =0;
		virtual void setName(const std::string &value) =0;
};

class Mediator {
	public:
		virtual void interact(System *sys) =0;
		virtual bool getState() =0;
};

class MediatorConcrete : public Mediator {
	public:
		MediatorConcrete() {
			state = false;
		}
		void interact(System* sys) override {
			if (state)
				sys->notifyMediator("The system is available");
			state = !state;
		}
		bool getState() override {
			return this->state;
		}
	private:
		bool state;
};

class SystemConcrete : public System {
	public:
		SystemConcrete(MediatorConcrete *mediator) : mediator(mediator) {

		}
		void setName(const std::string &value) override {
			this->name = value;
		}
		void interact() override {
			mediator->interact(this);
		}
		void notifyMediator(const std::string &mex) override {
			std::cout << "For system: " << name << "------- " << mex << "--------" << std::endl;
		}
	private:
		MediatorConcrete *mediator;
		std::string name;	
};

int main() {
	MediatorConcrete *mediator = new MediatorConcrete();
	System *systemA = new SystemConcrete(mediator);
	System *systemB = new SystemConcrete(mediator);

	systemA->setName("Alpha");
	systemB->setName("Beta");
	
	systemA->interact();
	systemB->interact();
	systemA->interact();
	systemB->interact();
	systemB->interact();
	systemA->interact();

	return 0;
}
