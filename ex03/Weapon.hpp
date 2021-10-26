#ifndef _Weapon_hpp_
#define _Weapon_hpp_

# include <string>

class Weapon {
private:
	std::string	type;
public:
	Weapon( std::string weapon_type );
	~Weapon( void );
	const std::string getType( void );
	void setType(std::string weapon_type);
};

#endif