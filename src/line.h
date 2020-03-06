#pragma once
#include <iostream>

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
	bool equal(Point pp) {
		return (this->x == pp.x && this->y == pp.y);
	}
	void show() {
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};

class Line {
public:
	double k = 0, b = 0, vertical_x = 0;
	bool vertical = false;

	Line(int x1, int y1, int x2, int y2);
	void show();
	Point* getCross(Line* l2);
	Point* setX(double x);
};