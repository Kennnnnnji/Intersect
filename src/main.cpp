#include <iostream>
#include <vector>
#include "line.h"

using namespace std;

int main() {
	int n;
	char c;
	vector<Line *> lineSet;
	cin >> n;
	while (n--) {
		int x1, y1, x2, y2;
		cin >> c >> x1 >> y1 >> x2 >> y2;
		Line* newLine = new Line(x1, y1, x2, y2);
		lineSet.push_back(newLine);
		newLine->show();
	}
	(*lineSet.begin())->getCross(lineSet.back())->show();
	system("pause");
}