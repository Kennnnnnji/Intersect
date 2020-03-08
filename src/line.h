#pragma once
#include <iostream>
#include "point.h"
#include "shape.h"

class Line : public Shape {
public:
	double k = 0, b = 0, vertical_x = 0;
	bool vertical = false;

	Line(int x1, int y1, int x2, int y2);
	void show();
	Point getCross(Line* l2);
	Point setX(double x);
};