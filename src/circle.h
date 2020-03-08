#pragma once
#include "point.h"
#include "line.h"
#include "shape.h"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>

class Circle : public Shape {
public:
	Point P;
	double r, left;
    Circle(Point P, double r) {
        this->P = P;
        this->r = r;
        this->left = P.x - r;
    }
	double getDistanceLP(Line l) {
		if (l.vertical) return abs(P.x - l.vertical_x);
		return abs(-l.k * P.x + P.y - l.b)/sqrt(l.k * l.k + 1);
	}
	bool isCross(Line l) {
		return getDistanceLP(l) <= r;
	}
	bool isCross(Circle c2) {
		double distance = P.distance(c2.P);
		return distance <= r + c2.r && distance >= abs(r - c2.r);
	}
	pointPair intersections(Circle* c) {
		if (!isCross(*c)) return pointPair(Point(), Point());
		Point P0((double)P.x, (double)P.y);
		Point P1((double)c->P.x, (double)c->P.y);
		double d, a, h;
		d = P0.distance(P1);
		a = ((double)r * r - (double)c->r * c->r + (double)d * d) / (2 * (double)d);
		h = sqrt((double)r * r - (double)a * a);
		Point P2 = P1.sub(P0).scale(a / d).add(P0);
		double x3, y3, x4, y4;
		x3 = (double)P2.x + (double)h * (P1.y - P0.y) / d;
		y3 = (double)P2.y - (double)h * (P1.x - P0.x) / d;
		x4 = (double)P2.x - (double)h * (P1.y - P0.y) / d;
		y4 = (double)P2.y + (double)h * (P1.x - P0.x) / d;
		return pointPair(Point(x3, y3), Point(x4, y4));
	}
	/*pointPair intersect(const Circle* C2) {
		// distance between the centers
		Point i1, i2;
		double d = Point(P.x - C2->P.x, P.y - C2->P.y).norm();

		// find number of solutions
		if (d > r + C2->r) // circles are too far apart, no solution(s)
		{
			return pointPair(Point(), Point());
		} else if (d == 0 && r == C2->r) // circles coincide
		{
			return pointPair(Point(), Point());
		}
		// one circle contains the other
		else if (d + min(r, C2->r) < max(r, C2->r)) {
			return pointPair(Point(), Point());
		} else {
			double a = (r * r - C2->r * C2->r + d * d) / (2.0 * d);
			double h = sqrt(r * r - a * a);

			// find p2
			Point p2(P.x + (a * (C2->P.x - P.x)) / d,
				P.y + (a * (C2->P.y - P.y)) / d);

			// find intersection points p3
			i1.setCoords(p2.x + (h * (C2->P.y - P.y) / d),
				p2.y - (h * (C2->P.x - P.x) / d)
			);
			i2.setCoords(p2.x - (h * (C2->P.y - P.y) / d),
				p2.y + (h * (C2->P.x - P.x) / d)
			);

			i1.valid = true;
			if (d != r + C2->r) i2.valid = true;
			return pointPair(i1, i2);
		}
	}*/
};

static pointPair getCrossPoints(Circle* cir, Line* l) {
	//(x - cx )^2 + (y - cy)^2 = r^2
	//y = kx +b
	if (!cir->isCross(*l)) return pointPair(Point(), Point());
	
	//求得直线方程
	double k = l->k, b = l->b;
	double cx = cir->P.x, cy = cir->P.y, r = cir->r;
	if (l->vertical) {
		double delta = r * r - (l->vertical_x - cx) * (l->vertical_x - cx);
		delta = sqrt(delta);
		double x1 = l->vertical_x;
		return pointPair(Point(x1, b + delta), Point(x1, b - delta));
	}
	//列方程  (1 + k^2)*x^2 - x*(2*cx -2*k*(b -cy) ) + cx*cx + ( b - cy)*(b - cy) - r*r = 0

	double x1, y1, x2, y2;
	double P = cx * cx + (b - cy) * (b - cy) - r * r;
	double a = (1 + k * k);
	double b1 = (2 * cx - 2 * k * (b - cy));
	//得到下面的简化方程
	// a*x^2 - b1*x + c = 0;
	double tmp = sqrt(b1 * b1 - 4 * a * P);
	x1 = (b1 + tmp) / (2 * a);
	y1 = k * x1 + b;
	x2 = (b1 - tmp) / (2 * a);
	y2 = k * x2 + b;
	return pointPair(Point(x1, y1), Point(x2, y2));
}