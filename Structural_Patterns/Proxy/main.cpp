#include <iostream>

class Server {
	public:
		virtual void Available() {}
};

class ServerLinux : public Server {
	public:
		void Available() override {
			if (reachable)
				std::cout << "The server is reachable" << std::endl;
			else
				std::cout << "The server is unreachable" << std::endl;
			reachable = !reachable; //changes state each times it gets observed
		}

		ServerLinux(bool reachable) : reachable(reachable) {
			if (reachable)
				std::cout << "At the moment the server is reachable" << std::endl;
			else
				std::cout << "At the moment the server is not reachable" << std::endl;
		}
	private:
		bool reachable;
};

class Proxy : public Server {
	private:
		bool start_communication;
		ServerLinux* sl;
	public:
		Proxy(bool reachable) : reachable(reachable),sl(nullptr) {}
	
		void Available() override {
			if (sl == nullptr) {
				sl = new ServerLinux(start_communication);
			}
			sl->Available();
		}
};

int main() {
	
	Proxy p = new Proxy(true);
	
	p.Available(); //first interaction goes through proxy, as it initialized the server
	p.Available(); //following interactions retrieve the state directly from the server

	return 0;
}
