#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		vertical = true;
		vertical_x = (double)x1;
	} else {
		k = ((double)y1 - (double)y2) / ((double)x1 - (double)x2);
		b = (double)y1 - (double)k * (double)x1;
	}
}

void Line::show() {
	using namespace std;
	cout << k << " " << b << endl;
}

Point Line::getCross(Line* l2) {
	// parallel
	if (vertical && l2->vertical || 
		(!vertical && !l2->vertical && this->k == l2->k)) {
		return Point();
	}
	// cross
	if (vertical) {
		return l2->setX(vertical_x);
	} else if (l2->vertical) {
		return setX(vertical_x);
	}
	double x = (b - l2->b) / (l2->k - k);
	Point p = Point(x, k * x + b);
	return p;
}

Point Line::setX(double x) {
	if (vertical) {
		std::cerr << "vertical in setX()" << std::endl;
	}
	return Point(x, k * x + b);
}
