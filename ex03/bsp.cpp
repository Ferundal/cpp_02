#include "Point.hpp"

static float dir_sin(Point dir) {
	return (dir.GetY().toFloat() / sqrt(pow(dir.GetY().toFloat(), 2) + pow(dir.GetX().toFloat(), 2)));
}

static float dir_cos(Point dir) {
	return (dir.GetX().toFloat() / sqrt(pow(dir.GetY().toFloat(), 2) + pow(dir.GetX().toFloat(), 2)));
}

static bool is_between(Point const apex, Point const dir_one_point, Point const dir_two_point, Point const check_point) {
	Point rel_dir_one_point (dir_one_point.GetX().toFloat() - apex.GetX().toFloat(), \
							dir_one_point.GetY().toFloat() - apex.GetY().toFloat());
	Point rel_dir_two_point (dir_two_point.GetX().toFloat() - apex.GetX().toFloat(), \
							dir_two_point.GetY().toFloat() - apex.GetY().toFloat());
	Point rel_check_point (check_point.GetX().toFloat() - apex.GetX().toFloat(), \
							check_point.GetY().toFloat() - apex.GetY().toFloat());
	float dir_one_sin = dir_sin(rel_dir_one_point);
	float dir_one_cos = dir_cos(rel_dir_one_point);
	float dir_two_sin = dir_sin(rel_dir_two_point);
	float dir_two_cos = dir_cos(rel_dir_two_point);
	float dir_check_sin = dir_sin(rel_check_point);
	float dir_check_cos = dir_cos(rel_check_point);
	if (((dir_check_sin > dir_one_sin && dir_check_sin < dir_two_sin) || \
		(dir_check_sin < dir_one_sin && dir_check_sin > dir_two_sin)) &&
		((dir_check_cos > dir_one_cos && dir_check_cos < dir_two_cos) || \
		(dir_check_cos < dir_one_cos && dir_check_cos > dir_two_cos)))
		return true;
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	if (is_between(a, b, c, point) && \
		is_between(b, c, a, point) && \
		is_between(c, a, b, point))
		return true;
	return false;
}