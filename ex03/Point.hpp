#ifndef _Point_hpp_
#define _Point_hpp_

# include "Fixed.hpp"
# include <string>
# include <iostream>
# include <cmath>

class Point {
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point( void );
	Point( const Point& origin);
	Point( const float float_x, const float float_y);
	Point& operator =(const Point& origin);
	~Point (void);
};

std::ostream &operator <<(std::ostream &outstream, const Fixed &origin);
bool bsp( Point const a, Point const b, Point const c, Point const point);
#endif