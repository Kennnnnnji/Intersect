#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include "line.h"
using namespace std;

template<> struct hash<Point> {
	size_t operator()(const Point& obj) const {
		return hash<double>()(obj.x + obj.y);
	}
};
bool operator ==(const Point& obj, const Point& obj2) {
	if (obj.x == obj2.x && obj.y == obj2.y)
		return true;
	else
		return false;
}
int main(int argc, char** argv) {
	int n;
	char c;
	vector<Line *> lineVec;
	if (argc != 5) {
		cerr << "not enough args!" << endl;
		exit(-1);
	}
	string inFileName, outFileName;
	inFileName = argv[2];
	outFileName = argv[4];
	ifstream inFile(inFileName);
	ofstream outFile(outFileName);
	inFile >> n;
	while (n--) {
		int x1, y1, x2, y2;
		for (int i = 0; i < 5; i++) {
			inFile >> c >> x1 >> y1 >> x2 >> y2;
			Line* newLine = new Line(x1, y1, x2, y2);
			lineVec.push_back(newLine);
		}
	}
	unordered_set<Point> pointSet;
	for (vector<Line*>::iterator iter = lineVec.begin(); iter != lineVec.end(); iter++) {
		for (auto iter2 = iter + 1; iter2 != lineVec.end(); iter2++) {
			Point* p = (*iter)->getCross(*iter2);
			if (p->valid) {
				pointSet.insert(*p);
			}
		}
	}
	outFile << pointSet.size();
	return 0;
}