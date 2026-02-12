#include <iostream>
#include <string>
class Strategy {
	public:
		virtual void print() =0;
};

class StarStrategy: public Strategy {
	public:
		void print() override {
			std::string target(10,'*');
			std::cout << target << std::endl;
		}
};

class DotStrategy: public Strategy {
	public:
		void print() override {
			std::string target(10,'.');
			std::cout << target << std::endl;
		}
};

class CommaStrategy: public Strategy {
	public:
		void print() override {
			std::string target(10,',');
			std::cout << target << std::endl;
		}
};

class Context {
	private:
		Strategy* strat;
	public:
		//Context(Strategy *strategy) : strat(strategy) {}
		void setStrat(Strategy *strategy) {
			this->strat = strategy;
		}
		void exe() {
			strat->print();
		}
};

int main() {
	Context ct;
	CommaStrategy cs;
	DotStrategy ds;
	StarStrategy ss;
	ct.setStrat(&cs);
	ct.exe();
	ct.setStrat(&ds);
	ct.exe();
	ct.setStrat(&ss);
	ct.exe();
	return 0;
}


