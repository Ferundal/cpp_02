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


/*
 * Assignment
 */

Fixed& Fixed::operator =(const Fixed& origin) {
	std::cout << "Assignation operator called" <<std::endl;
	if (this == &origin)
		return (*this);
	value = origin.value;
	return (*this);
}

/*
 * Arithmetic
 */

Fixed Fixed::operator +(const Fixed& origin) {
	std::cout << "Arithmetic plus operator called" <<std::endl;
	Fixed	ret_val;
	ret_val.value = value + origin.value;
	return (ret_val);
}

Fixed Fixed::operator -(const Fixed& origin) {
	std::cout << "Arithmetic minus operator called" <<std::endl;
	Fixed	ret_val;
	ret_val.value = value - origin.value;
	return (ret_val);
}

Fixed Fixed::operator *(const Fixed& origin) {
	std::cout << "Arithmetic multiplication operator called" <<std::endl;
	Fixed	ret_val;
	ret_val.value = value * origin.value / (1 << point_bits);
	return (ret_val);
}

Fixed Fixed::operator /(const Fixed& origin) {
	std::cout << "Arithmetic division operator called" <<std::endl;
	Fixed	ret_val;
	ret_val.value = value * (1 << point_bits) / origin.value;
	return (ret_val);
}

/*
 * Comparison
 */

bool Fixed::operator ==(const Fixed& origin) const{
	std::cout << "Comparison == operator called" <<std::endl;
	if (value - origin.value == 0)
		return (true);
	return (false);
}
bool Fixed::operator !=(const Fixed& origin) const{
	std::cout << "Comparison != operator called" <<std::endl;
	if (value - origin.value == 0)
		return (false);
	return (true);
}
bool Fixed::operator <=(const Fixed& origin) const{
	std::cout << "Comparison <= operator called" <<std::endl;
	if (value - origin.value <= 0)
		return (true);
	return (false);
}
bool Fixed::operator >=(const Fixed& origin) const{
	std::cout << "Comparison >= operator called" <<std::endl;
	if (value - origin.value >= 0)
		return (true);
	return (false);
}
bool Fixed::operator <(const Fixed& origin) const{
	std::cout << "Comparison < operator called" <<std::endl;
	if (value - origin.value < 0)
		return (true);
	return (false);
}

bool Fixed::operator >(const Fixed& origin) const{
	std::cout << "Comparison > operator called" <<std::endl;
	if (value - origin.value > 0)
		return (true);
	return (false);
}

/*
 * Incrementation
 */

Fixed &Fixed::operator ++() {
	value += 1 < point_bits;
	return (*this);
}

Fixed Fixed::operator ++(int) {
	Fixed ret_val;
	ret_val.value = value + (1 < point_bits);
	return (ret_val);
}

Fixed &Fixed::operator --() {
	value -= 1 < point_bits;
	return (*this);
}

Fixed Fixed::operator --(int) {
	Fixed ret_val;
	ret_val.value = value - (1 < point_bits);
	return (ret_val);
}


/*
 * Min/Max, const Min/Max
 */

Fixed &Fixed::min(Fixed &first, Fixed &second) {
	if (first > second)
		return (second);
	return (first);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second) {
	if (first > second)
		return (second);
	return (first);
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
	if (first < second)
		return (second);
	return (first);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second) {
	if (first < second)
		return (second);
	return (first);
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

std::ostream &operator <<(std::ostream &outstream, const Fixed &origin) {
	outstream << origin.toFloat();
	return (outstream);
}
