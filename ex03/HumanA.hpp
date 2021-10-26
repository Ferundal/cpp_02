
#ifndef _HumanA_hpp_
#define _HumanA_hpp_

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA(std::string new_name, Weapon &new_weapon);
	~HumanA( void );
	void SetWeapon(Weapon &new_weapon);
	void attack();
};

#endif