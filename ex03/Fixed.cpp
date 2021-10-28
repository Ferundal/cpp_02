#include "Fixed.hpp"

Fixed::Fixed( void ) {
	value = 0;
}

Fixed::Fixed( const Fixed& origin) {
	value = origin.value;
}

Fixed::Fixed( int origin) {
	origin = origin << point_bits;
	value = origin;
}

Fixed::Fixed( float origin) {
	value = roundf(origin * (1 << point_bits));
}


/*
 * Assignment
 */

Fixed& Fixed::operator =(const Fixed& origin) {
	if (this == &origin)
		return (*this);
	value = origin.value;
	return (*this);
}

/*
 * Arithmetic
 */

Fixed Fixed::operator +(const Fixed& origin) {
	Fixed	ret_val;
	ret_val.value = value + origin.value;
	return (ret_val);
}

Fixed Fixed::operator -(const Fixed& origin) {
	Fixed	ret_val;
	ret_val.value = value - origin.value;
	return (ret_val);
}

Fixed Fixed::operator *(const Fixed& origin) {
	Fixed	ret_val;
	ret_val.value = value * origin.value / (1 << point_bits);
	return (ret_val);
}

Fixed Fixed::operator /(const Fixed& origin) {
	Fixed	ret_val;
	ret_val.value = value * (1 << point_bits) / origin.value;
	return (ret_val);
}

/*
 * Comparison
 */

bool Fixed::operator ==(const Fixed& origin) const{
	if (value - origin.value == 0)
		return (true);
	return (false);
}
bool Fixed::operator !=(const Fixed& origin) const{
	if (value - origin.value == 0)
		return (false);
	return (true);
}
bool Fixed::operator <=(const Fixed& origin) const{
	if (value - origin.value <= 0)
		return (true);
	return (false);
}
bool Fixed::operator >=(const Fixed& origin) const{
	if (value - origin.value >= 0)
		return (true);
	return (false);
}
bool Fixed::operator <(const Fixed& origin) const{
	if (value - origin.value < 0)
		return (true);
	return (false);
}

bool Fixed::operator >(const Fixed& origin) const{
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
}

int Fixed::getRawBits( void ) const {
	return value;
}
void Fixed::setRawBits( int const raw ) {
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
