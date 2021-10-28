#include <iostream>
#include "Point.hpp"

int main( void ) {
	Point triangle[3] = {
		Point (0.0f, 0.0f),
		Point (0.0f, 1.0f),
		Point (1.0f, 0.0f)
	};
	Point outside_point(1.0f, 1.0f);
	Point inside_point(0.2f, 0.2f);
	std::cout << bsp (triangle[0], triangle[1], triangle[2], outside_point) << std::endl;
	std::cout << bsp (triangle[0], triangle[1], triangle[2], inside_point) << std::endl;
}