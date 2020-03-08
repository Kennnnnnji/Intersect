#include "pch.h"
#include "CppUnitTest.h"
#include <unordered_set>
#include "..\src\circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace test
{
	TEST_CLASS(test)
	{
	public:		
		TEST_METHOD(TestCircleCrossLine) {
			Circle* c = new Circle(Point(1, 1), 1);
			Line* l = new Line(0, 0, 2, 1);
			bool cross = c->isCross(*l);
			Assert::AreEqual(cross, true);
		}
		TEST_METHOD(TestLineCrossLine) {
			Line* l = new Line(0, 0, 2, 1);
			Line* l2 = new Line(0, 1, 2, 0);
			Point cross = l->getCross(l2);
			Assert::AreEqual(cross.x, 1.);
			Assert::AreEqual(cross.y, 0.5);
		}
		TEST_METHOD(TestCircleCrossCircle) {
			Circle* c1 = new Circle(Point(0, 0), 1);
			Circle* c2 = new Circle(Point(2, 0), 1);
			auto pts = c1->intersections(c2);
			Assert::AreEqual(pts.first.x, 1.);
			Assert::AreEqual(pts.first.y, 0.);
		}
		TEST_METHOD(TestCircleCrossCircle2) {
			Circle* c1 = new Circle(Point(0, 0), 1);
			Circle* c2 = new Circle(Point(1, 1), 1);
			auto pts = c1->intersections(c2);
			Assert::AreEqual(pts.first.x, 1.);
			Assert::AreEqual(pts.first.y, 0.);
			Assert::AreEqual(pts.second.x, 0.);
			Assert::AreEqual(pts.second.y, 1.);
		}
		TEST_METHOD(TestMargin) {
			vector<Line*> lineVec;
			vector<Circle*> circleVec;
			lineVec.push_back(new Line(1, 1, 99999, 0));
			lineVec.push_back(new Line(1, 1, 99998, 0));
			lineVec.push_back(new Line(0, 0, 0, 1));
			//unordered_set<Point, myHash>* rest = getCrossPoints(lineVec, circleVec, false, false);
			//Assert::AreEqual((int)rest->size(), 3);
		}
		TEST_METHOD(TestMargin2) {
			vector<Line*> lineVec;
			vector<Circle*> circleVec;
			lineVec.push_back(new Line(-1, 4, 4, -1));
			circleVec.push_back(new Circle(Point(1, 0), 2));
			circleVec.push_back(new Circle(Point(2, 2), 1));
			//unordered_set<Point, myHash>* rest = getCrossPoints(lineVec, circleVec, false, false);
			//Assert::AreEqual((int)rest->size(), 3);
		}
		TEST_METHOD(TestMargin3) {
			vector<Line*> lineVec;
			vector<Circle*> circleVec;
			lineVec.push_back(new Line(-1, 4, 4, -1));
			circleVec.push_back(new Circle(Point(1, 0), 2));
			circleVec.push_back(new Circle(Point(2, 2), 1));
			//unordered_set<Point, myHash>* rest = getCrossPoints(lineVec, circleVec, false, false);
			//Assert::AreEqual((int)rest->size(), 3);
		}
		TEST_METHOD(TestCircleVerticalLine) {
			Line *newLine = new Line(3, 1, 3, 0);
			Circle* newC = new Circle(Point(1, 0), 2);
			auto pts = getCrossPoints(newC, newLine);
			Assert::AreEqual(pts.first.x, 3.);
			Assert::AreEqual(pts.first.y, 0.);
			Assert::AreEqual(pts.second.x, 3.);
			Assert::AreEqual(pts.second.y, 0.);
		}
		TEST_METHOD(TestPointAdd) {
			Point p1(1.0, 2.0), p2(2.0, 1.0);
			Point p3 = p1.add(p2);
			Assert::AreEqual(p3.x, 3.0);
			Assert::AreEqual(p3.y, 3.0);
		}
		TEST_METHOD(TestDistance) {
			Point p1(1.0, 2.0), p2(4.0, 6.0);
			double distance = p2.getDistance(p1);
			Assert::AreEqual(distance, 5.0);
		}
	};
}
