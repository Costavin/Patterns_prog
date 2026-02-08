#include <iostream>

class Singleton {
	private:
		//Declaration
		static Singleton* instance;


		Singleton() {
			std::cout << "Singleton instance got spwaned\n" << std::endl;
		}

		Singleton(const Singleton&) = delete;
		Singleton& operator=(const Singleton&) = delete;
	public:
		static Singleton* getInstance() {
			if (instance == nullptr)
				instance = new Singleton();
			return instance;
		}

		void helloW() {
			std::cout << "Hello World!\n" << std::endl;
		}
};

//Definition and init
Singleton* Singleton::instance = nullptr;

int main() {
	//Singleton* Singleton::instance = nullptr;
	//std::cout << "start prog\n" << std::endl;
	Singleton* s1 = Singleton::getInstance();
	s1->helloW();

	Singleton* s2 = Singleton::getInstance();
	s2->helloW();

	std::cout << (s1==s2) << std::endl;

	return 0;
}
