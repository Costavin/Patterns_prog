#include <iostream>
#include <unordered_map>

//flyweight class
class Character {
	char global_state;
	public:
		Character(char state) : global_state(state) {}
		void show(int local_state) {
			std::cout << "Character is at: " << global_state << " " << local_state << std::endl;
		}
};

class CharacterFactory {
	std::unordered_map<char, Character*> global_chars;
	public:
		Character* getChar(char key) {
			if (global_chars.find(key) == global_chars.end()) {
				global_chars[key] = new Character(key);
			}
			return global_chars[key];
		}
};

int main() {
	CharacterFactory chFa;
	int pos = 0;

	chFa.getChar('E')->show(++pos);
	return 0;
}
