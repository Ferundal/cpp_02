#ifndef _HumanB_hpp_
#define _HumanB_hpp_

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon		*weapon;
public:
	HumanB(std::string new_name);
	HumanB(std::string new_name, Weapon *new_weapon);
	void SetWeapon(Weapon *weapon);
	~HumanB( void );
	void attack();
};

#endif