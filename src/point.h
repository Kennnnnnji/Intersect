#pragma once
using namespace std;


struct Point {
	double x = 0, y = 0;
	bool valid = false;
	Point() {};
	Point(double x, double y) {
		valid = true;
        const long long plus = 10000000000;
        long long a2 = (long long)(x * plus + 0.5);
		//this->x = x;
		this->x = a2 / (double)plus;
        long long b2 = (long long)(y * plus + 0.5);
		//this->y = y;
		this->y = b2 / (double)plus;
	}
	void show() {
        printf("(%.20f, %.20f)\n", x, y);
		//std::cout << "(" << x << "," << y << ")" << std::endl;
	}
    Point sub(Point p2) {
        return Point((double)x - p2.x, (double)y - p2.y);
    }
    Point add(Point p2) {
        return Point((double)x + p2.x, (double)y + p2.y);
    }
    double getDistance(Point p2) {
        return sqrt(((double)x - p2.x) * ((double)x - p2
            .x) + ((double)y - p2.y) * ((double)y - p2.y));
    }
    Point scale(double s) {
        return Point(x * s, y * s);
    }
};

typedef pair<Point, Point> pointPair;