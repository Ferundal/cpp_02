#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" <<std::endl;
	value = 0;
}
Fixed::Fixed( const Fixed& origin) {
	std::cout << "Copy constructor called" <<std::endl;
	value = origin.value;
}

Fixed::Fixed( int origin) {
	std::cout << "Int constructor called" <<std::endl;
	origin = origin << point_bits;
	value = origin;
}

Fixed::Fixed( float origin) {
	value = roundf(origin * (1 << point_bits));
	std::cout << "Float constructor called" <<std::endl;
}

Fixed& Fixed::operator =(const Fixed& origin) {
	std::cout << "Assignation operator called" <<std::endl;
	if (this == &origin)
		return (*this);
	value = origin.value;
	return (*this);
}

std::ostream &operator <<(std::ostream &outstream, const Fixed &origin) {
	outstream << origin.toFloat();
	return (outstream);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" <<std::endl;
	return value;
}
void Fixed::setRawBits( int const raw ) {
	std::cout << "Assignation operator called" <<std::endl;
	value = raw;
}

float Fixed::toFloat( void ) const {
	return (static_cast<float>(value) / ( 1 << point_bits));
}

int  Fixed::toInt( void ) const {
	return (value >> point_bits);
}