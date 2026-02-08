#include <iostream>

//abstract class
class Weapon {
	public:
		virtual Weapon* newWeapon() const = 0;
		virtual void attack() const = 0;
		virtual ~Weapon() {}
};

//concrete classes
class Axe: public Weapon {
	public:
		Axe(int dam) : damage(dam) {}

		Weapon* newWeapon() const override {
			return new Axe(*this);
		}
		void attack() const override {
			std::cout << "This axe deals this damage: " << damage << std::endl;
		}
	private:
		int damage;
};

class Bow: public Weapon {
	public:
		Bow(int dam, int am) : damage(dam), amount(am) {}

		Weapon* newWeapon() const override {
			return new Bow(*this);
		}
		void attack() const override {
			std::cout << "This bow deals this damage: " << damage << " for each of the " << amount << " ammo" << std::endl;
		}
	private:
		int damage;
		int amount;
};

int main() {
	Axe ax(30);
	Bow bo(7,3);

	Weapon* weap1 = ax.newWeapon();
	Weapon* weap2 = bo.newWeapon();

	weap1->attack();
	weap2->attack();


	return 0;
}
