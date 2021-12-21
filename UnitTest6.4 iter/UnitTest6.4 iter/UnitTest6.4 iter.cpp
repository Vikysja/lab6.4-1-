#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64iter
{
	TEST_CLASS(UnitTest64iter)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 10;
			int a[n] = { 1, -2, 4, 5, -5, -10, 4, 5, 7, 0 };
			int maxIndex = 0;
			findMaxAbs(a, n, maxIndex);

			Assert::AreEqual(5, maxIndex);
		}
	};
}
