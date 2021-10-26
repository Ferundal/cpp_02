#include "HumanB.hpp"

HumanB::HumanB(std::string new_name, Weapon *new_weapon) {
	name = new_name;
	weapon = new_weapon;
}

HumanB::HumanB(std::string new_name) {
	name = new_name;
	weapon = NULL;
}

HumanB::~HumanB( void ) {

}
void HumanB::SetWeapon(Weapon *new_weapon) {
	weapon = new_weapon;
}

void HumanB::attack() {
	if (weapon == NULL)
		std::cout << name << " attacks without any weapon! Impressive!"<< std::endl;
	else
		std::cout << name << " attacks with his " << weapon->getType() << std::endl;
}