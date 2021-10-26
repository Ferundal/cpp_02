#include "Weapon.hpp"

Weapon::Weapon( std::string weapon_type ) {
	type = weapon_type;
}

Weapon::~Weapon( void ) {

}

const std::string Weapon::getType( void ) {
	return (type);
}

void Weapon::setType(std::string weapon_type) {
	type = weapon_type;
}