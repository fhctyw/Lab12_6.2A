#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_6.2\main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = nullptr, * last = nullptr;
			for (size_t i = 0; i < 10; i++)
				enqueue(first, last, i);
			remove(first, last, 0);
			remove(first, last, 0);
			Assert::AreEqual(8, count(first));

		}
	};
}
