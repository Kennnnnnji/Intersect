#include "line.h"

Line::Line(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		vertical = true;
		vertical_x = x1;
	} else {
		k = ((double)y1 - y2) / ((double)x1 - x2);
		b = (double)y1 - k * x1;
	}
}

void Line::show() {
	using namespace std;
	cout << k << " " << b << endl;
}

Point* Line::getCross(Line* l2) {
	// parallel
	if (vertical && l2->vertical || 
		(!vertical && !l2->vertical && this->k == l2->k)) {
		return new Point();
	}
	// cross
	if (vertical) {
		return l2->setX(vertical_x);
	} else if (l2->vertical) {
		return setX(vertical_x);
	}
	Point* p = new Point();
	p->x = (b - l2->b) / (l2->k - k);
	p->y = k * p->x + b;
	p->valid = true;
	return p;
}

Point* Line::setX(double x) {
	if (vertical) return new Point(vertical_x, 0);
	return new Point(x, k * x + b);
}
