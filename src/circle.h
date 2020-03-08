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
	double r;
    Circle(Point P, double r) {
        this->P = P;
        this->r = r;
    }
	double getDistanceLine(Line l) {
		if (l.vertical) return abs(P.x - l.vertical_x);
		return abs(-l.k * P.x + P.y - l.b)/sqrt(l.k * l.k + 1);
	}
	bool isCross(Line l) {
		return getDistanceLine(l) <= r;
	}
	bool isCross(Circle c2) {
		double distance = P.getDistance(c2.P);
		return distance <= r + c2.r && distance >= abs(r - c2.r);
	}
	pointPair intersections(Circle* c) {
		if (!isCross(*c)) return pointPair(Point(), Point());
		Point P0((double)P.x, (double)P.y);
		Point P1((double)c->P.x, (double)c->P.y);
		double d, a, h;
		d = P0.getDistance(P1);
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
};

static pointPair getCrossPoints(Circle* cir, Line* l) {
	if (!cir->isCross(*l)) {
		return pointPair(Point(), Point());
	}
	double k = l->k, b = l->b;
	double cx = cir->P.x, cy = cir->P.y, r = cir->r;
	if (l->vertical) {
		double delta = r * r - (l->vertical_x - cx) * (l->vertical_x - cx);
		delta = sqrt(delta);
		double x1 = l->vertical_x;
		return pointPair(Point(x1, b + delta), Point(x1, b - delta));
	}

	double P = cx * cx + (b - cy) * (b - cy) - r * r;
	double a = (1 + k * k);
	double b1 = (2 * cx - 2 * k * (b - cy));
	double c1 = sqrt(b1 * b1 - 4 * a * P);
	double x1, y1, x2, y2;
	x1 = ((double)b1 + c1) / (2 * a);
	y1 = k * x1 + b;
	x2 = (b1 - c1) / (2 * a);
	y2 = k * x2 + b;
	return pointPair(Point(x1, y1), Point(x2, y2));
}

