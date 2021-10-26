#include "Point.hpp"

Point::Point( void ) {
	std::cout << "Point default constructor called" <<std::endl;
}

Point::Point( const Point& origin) : x(origin.x), y(origin.y) {

}

Point::Point( const float float_x, const float float_y) : x(float_x), y(float_y) {

}

Point& Point::operator =(const Point& origin) {
	(void)origin;
	return (*this);
}

Point::~Point () {
	std::cout << "Point destructor called" <<std::endl;
}
