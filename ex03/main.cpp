#include "Weapon.hpp"

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	{
		Weapon humanAWeapon ("Axe");
		HumanA jack ("Jack", humanAWeapon);
		jack.attack();
		humanAWeapon.setType("Bow");
		jack.attack();
	}
	{
		HumanB billy ("Billy");
		billy.attack();
		Weapon humanBWeapon ("Polearm");
		billy.SetWeapon(&humanBWeapon);
		billy.attack();
		humanBWeapon.setType("Sword");
		billy.attack();
	}
}
