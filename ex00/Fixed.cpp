#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" <<std::endl;
	value = 0;
}
Fixed::Fixed( const Fixed& origin) {
	std::cout << "Copy constructor called" <<std::endl;
	value = origin.getRawBits();
}
Fixed& Fixed::operator =(const Fixed& origin) {
	std::cout << "Assignation operator called" <<std::endl;
	if (this == &origin)
		return (*this);
	value = origin.getRawBits();
	return (*this);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" <<std::endl;
	return value;
}
void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" <<std::endl;
	value = raw;
}