#pragma once


class Point {
public:
	double x, y;
	bool valid = false;
	Point() {};
	Point(double x, double y) {
		valid = true;
		this->x = x;
		this->y = y;
	}

	void show() {
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};
