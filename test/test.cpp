#include "pch.h"
#include "CppUnitTest.h"
#include "..\src\circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:		
		TEST_METHOD(TestCircleCrossLine)
		{
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
	};
}
