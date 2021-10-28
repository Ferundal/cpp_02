#include "Point.hpp"

Point::Point( void ) {
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

}

Fixed Point::GetX() const {
	return x;
}
Fixed Point::GetY() const {
	return y;
}
