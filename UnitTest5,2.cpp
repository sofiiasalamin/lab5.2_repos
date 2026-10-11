#include "pch.h"
#include "CppUnitTest.h"
#include "../5,2/5,2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:

		TEST_METHOD(A_SecondTerm)
		{
			// a2 = -x^2/2 при x = 0.5 -> -0.125
			double r = A(0.5, 2, -0.5);
			Assert::AreEqual(-0.125, r, 1e-12);
		}

		TEST_METHOD(S_MatchesLogPositiveX)
		{
			int n = 0;
			double s = S(0.5, 1e-6, n, 0);
			Assert::AreEqual(log(1 - 0.5), s, 1e-5);
		}

		TEST_METHOD(S_MatchesLogNegativeX)
		{
			int n = 0;
			double s = S(-0.5, 1e-6, n, 0);
			Assert::AreEqual(log(1 + 0.5), s, 1e-5);
		}

		TEST_METHOD(S_ZeroX_OneTerm)
		{
			int n = 0;
			double s = S(0.0, 1e-6, n, 0);
			Assert::AreEqual(0.0, s, 1e-12);
			Assert::AreEqual(1, n);
		}
	};
}