#pragma once
#include <vector>
#include "point.h"

class myset {
public:
	vector<Point> pointVec;
	bool double_equal(double a, double b) {
		const long long plus = 10000000000000;
		long long a2 = (long long)(a * plus + 0.5);
		long long b2 = (long long)(b * plus + 0.5);
		return a2 == b2;
	}
	bool contain(Point p) {
		for (auto it = pointVec.begin(); it != pointVec.end(); it++) {
			//if (it->x == p.x && it->y == p.y) {
			if (double_equal(it->x, p.x) && double_equal(it->y, p.y)) {
				return true;
			}
		}
		return false;
	}
	void insert(Point p) {
		if (!contain(p)) {
			pointVec.push_back(p);
		}
	}
	int size() {
		return pointVec.size();
	}
	vector<Point>::iterator begin() {
		return pointVec.begin();
	}
	vector<Point>::iterator end() {
		return pointVec.end();
	}
};