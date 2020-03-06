#include <iostream>
#include <vector>
#include <set>
#include "line.h"

using namespace std;

int main() {
	int n;
	char c;
	vector<Line *> lineVec;
	cin >> n;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> c >> x1 >> y1 >> x2 >> y2;
		Line* newLine = new Line(x1, y1, x2, y2);
		lineVec.push_back(newLine);
		//newLine->show();
	}
	set<Point*> pointSet;
	for (vector<Line*>::iterator iter = lineVec.begin(); iter != lineVec.end(); iter++) {
		for (auto iter2 = iter + 1; iter2 != lineVec.end(); iter2++) {
			Point* p = (*iter)->getCross(*iter2);
			if (p->valid) pointSet.insert(p);
		}
	}
	cout << pointSet.size();
	return 0;
}