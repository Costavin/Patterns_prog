#include <iostream>

class CommandInterface {
	public:
		virtual void performAct() =0;
};

class Receiver{
	private:
		bool light;
	public:
		Receiver() {light = false;}
		void click() {
			light = !light;
			if (light)
				std::cout << "Ligths on!" << std::endl;
			else
				std::cout << "Lights off!" << std::endl;
		}
};

class Command: public CommandInterface {
	Receiver& receiver;
	public:
		Command(Receiver& receiver) : receiver(receiver) {}
		void performAct() override {receiver.click();}
};

class Invoker {
	Command* command;
	public:
		void setCommand(Command* com) {command = com;}
		void exeCommand() {command->performAct();}
};

int main() {
	Receiver rec;
	Command com(rec);
	Invoker inv;

	inv.setCommand(&com);
	inv.exeCommand();
	inv.exeCommand();
	return 0;
}
