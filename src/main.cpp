#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "line.h"
#include "circle.h"
#include "shape.h"
#include "point.h"
using namespace std;
bool debug = false, testPerform = false;
struct myHash {
	size_t operator()(const Point& obj) const {
		return hash<double>()(obj.x + obj.y);
	}
};
bool double_equal(double a, double b) {
	/*const long long plus = 1000000000000;
	long long a2 = (long long)(a * plus + 0.5);
	long long b2 = (long long)(b * plus + 0.5);
	return a2 == b2;*/
	return a == b;
}
bool operator ==(const Point& obj, const Point& obj2) {
	return double_equal(obj.x, obj2.x) && double_equal(obj.y, obj2.y);
}

unordered_set<Point, myHash>* getCrossPoints(vector<Line*> lineVec, vector<Circle*> circleVec,
	bool debug, bool testPerform) {
	//unordered_set<Point, myHash> pointSet;
	unordered_set<Point, myHash>* pointSet = new unordered_set<Point, myHash>();
	for (vector<Line*>::iterator iter = lineVec.begin(); iter != lineVec.end(); iter++) {
		for (auto iter2 = iter + 1; iter2 != lineVec.end(); iter2++) {
			Point p = ((Line*)(*iter))->getCross((Line*)*iter2);
			if (p.valid) {
				if (debug) {
					cout << "l & l: ";
					p.show();
				}
				pointSet->insert(p);
			}
		}
	}
	for (vector<Line*>::iterator iter = lineVec.begin(); iter != lineVec.end(); iter++) {
		for (auto iter2 = circleVec.begin(); iter2 != circleVec.end(); iter2++) {
			pointPair pp = getCrossPoints((Circle*)(*iter2), (Line*)(*iter));
			if (pp.first.valid) {
				if (debug) {
					cout << "c & l: ";
					pp.first.show();
				}
				pointSet->insert(pp.first);
			}
			if (pp.second.valid) {
				if (debug) {
					cout << "c & l: ";
					pp.second.show();
				}
				pointSet->insert(pp.second);
			}
		}
	}
	for (auto iter = circleVec.begin(); iter != circleVec.end(); iter++) {
		for (auto iter2 = iter + 1; iter2 != circleVec.end(); iter2++) {
			pointPair pp = ((Circle*)(*iter))->intersections((Circle*)(*iter2));
			if (pp.first.valid) {
				if (debug) {
					cout << "c & c: ";
					pp.first.show();
				}
				pointSet->insert(pp.first);
			}
			if (pp.second.valid) {
				if (debug) {
					cout << "c & c: ";
					pp.second.show();
				}
				pointSet->insert(pp.second);
			}
		}
	}
	return pointSet;
}
int main(int argc, char** argv) {
	int n;
	char P;
	vector<Line*> lineVec;
	vector<Circle*> circleVec;
	ofstream outFile;
	if (!debug && !testPerform) {
		if (argc != 5) {
			cerr << "not enough args!" << endl;
			exit(-1);
		}
		string inFileName, outFileName;
		inFileName = argv[2];
		outFileName = argv[4];
		ifstream inFile(inFileName);
		outFile.open(outFileName);
		inFile >> n;
		while (n--) {
			int x1, y1, x2, y2;
			inFile >> P;
			if (P == 'L') {
				inFile >> x1 >> y1 >> x2 >> y2;
				Line* newLine = new Line(x1, y1, x2, y2);
				newLine->isLine = true;
				lineVec.push_back(newLine);
			} else {
				inFile >> x1 >> y1 >> x2;
				Circle* newCir = new Circle(Point(x1, y1), x2);
				circleVec.push_back(newCir);
			}
		}
	} else {
		cin >> n;
		while (n--) {
			int x1, y1, x2, y2;
			cin >> P;
			if (P == 'L') {
				cin >> x1 >> y1 >> x2 >> y2;
				Line* newLine = new Line(x1, y1, x2, y2);
				newLine->isLine = true;
				lineVec.push_back(newLine);
			} else {
				cin >> x1 >> y1 >> x2;
				Circle* newCir = new Circle(Point(x1, y1), x2);
				circleVec.push_back(newCir);
			}
		}
	}
	
	unordered_set<Point, myHash>* pointSet = getCrossPoints(lineVec, circleVec, debug, testPerform);
	//cout << pointSet->size() << endl;
	//system("pause");
	if (debug) {
		cout << pointSet->size() << endl;
		for (auto it = pointSet->begin(); it != pointSet->end(); it++) {
			((Point)(*it)).show();
		}
	} else {
		outFile << pointSet->size();
	}
	return 0;
}
