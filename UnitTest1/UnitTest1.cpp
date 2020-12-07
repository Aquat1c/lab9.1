#include "pch.h"
#include "CppUnitTest.h"
#include "../9.1.1/9.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91A
{
	TEST_CLASS(UnitTest91A)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int N = 1;
			Student* s = new Student[N];
			s[0].prizv = "join";
			s[0].kurs = 1;
			s[0].specialty = ²Ò;
			s[0].physics = 5;
			s[0].math = 5;
			s[0].informatics = 5;

			double lf = lessfour(s, N);
			Assert::AreEqual(lf, 0.0);
		}
	};
}
