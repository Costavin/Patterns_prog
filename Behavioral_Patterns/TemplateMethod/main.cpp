#include <string>
#include <iostream>

class Template {
	public:
		virtual void operationA() =0;
		virtual void operationB() =0;
		virtual void operationC() =0;
		void assemble() {
			operationA();
			operationB();
			operationC();
		}
};

class Transaction_one : public Template {
	public:
		void operationA() override {
			std::cout << "mov rax,0x18;" << std::endl;
		}
		void operationB() override {
			std::cout << "mov rbx,0x18;" << std::endl;
		}
		void operationC() override {
			std::cout << "syscall;" << std::endl;
		}
};

class Transaction_two : public Template {
	public:
		void operationA() override {
			std::cout << "mov rbx,0x7fff5623;" << std::endl;	
		}
		void operationB() override {	
			std::cout << "mov rax,[rbx];" << std::endl;	
		}
		void operationC() override {
			std::cout << "syscall;" << std::endl;	
		}
};

int main() {
	Transaction_one to;
	Transaction_two tt;

	to.assemble();
	tt.assemble();
	to.assemble();

	return 0;
}

