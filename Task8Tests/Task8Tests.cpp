#include "CppUnitTest.h"
#include "../Task8/main.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const vector<Monomial>& q) {
				wstringstream s;
				Stringmanager sm;
				vector<Monomial> tmp;
				for (auto i = q.begin(); i != q.end(); i++)
				{
					tmp.push_back(*i);
				}
				s << sm.Polynom_to_string(Polynomial(tmp).Getpoly()).c_str();
				return s.str();
			}
		}
	}
}

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <> static std::wstring ToString(const pair<float, int>& q)
			{
				wstringstream s;
				s << "{" << q.first << ", " << q.second << "}" << " ";
				return s.str();
			}
		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Task8Tests
{
	TEST_CLASS(Monomtimesmonom)
	{
	public:

		TEST_METHOD(just_monoms)
		{
			Monomial m1(2, 3);
			Monomial m2(3, 4);
			
			Monomial t_actual = m1 * m2;
			Monomial t_exprected(6, 7);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}

		TEST_METHOD(one_zero)
		{
			Monomial m1;
			Monomial m2(3, 4);

			Monomial t_actual = m1 * m2;
			Monomial t_exprected(0, 4);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}

		TEST_METHOD(two_zeros)
		{
			Monomial m1;
			Monomial m2;

			Monomial t_actual = m1 * m2;
			Monomial t_exprected(0, 0);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}
	};

	TEST_CLASS(Monomtimesnumber)
	{
	public:
		TEST_METHOD(just_monom_and_number)
		{
			Monomial m(2, 3);
			float num = 3;

			Monomial t_actual = m * num;
			Monomial t_exprected(6, 3);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}

		TEST_METHOD(monom_and_zero)
		{
			Monomial m(2, 3);
			float num = 0;

			Monomial t_actual = m * num;
			Monomial t_exprected(0, 3);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}

		TEST_METHOD(number_and_zero)
		{
			Monomial m;
			float num = 5;

			Monomial t_actual = m * num;
			Monomial t_exprected(0, 0);
			Assert::IsTrue(t_actual.Getcoef() == t_exprected.Getcoef(), L"Assert 1");
			Assert::IsTrue(t_actual.Getdegree() == t_exprected.Getdegree(), L"Assert 2");
			Assert::AreEqual(t_actual.Getmonom(), t_exprected.Getmonom(), L"Assert 3");
		}
	};

	TEST_CLASS(Polynomtimesnumber)
	{
		TEST_METHOD(just_polymonom_and_number)
		{
			Polynomial p("3x^3 + 2x^2 - 10");
			float num = 3;

			Polynomial t_actual = p * num;
			Polynomial t_exprected("9x^3 + 6x^2 - 30");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_zero)
		{
			Polynomial p("3x^3 + 2x^2 - 10");
			float num = 0;

			Polynomial t_actual = p * num;
			Polynomial t_exprected("0");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(number_and_zero)
		{
			Polynomial p("0");
			float num = 5;

			Polynomial t_actual = p * num;
			Polynomial t_exprected("0");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(number_and_number)
		{
			Polynomial p("6");
			float num = 5;

			Polynomial t_actual = p * num;
			Polynomial t_exprected("30");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}
	};

	TEST_CLASS(Polynomtimesmonom)
	{
		TEST_METHOD(just_polymonom_and_monom)
		{
			Polynomial p("3x^3 + 2x^2 - 10");
			Monomial m(4, 5);

			Polynomial t_actual = p * m;
			Polynomial t_exprected("12x^8 + 8x^7 - 40x^5");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(zero_and_monom)
		{
			Polynomial p("0");
			Monomial m(4, 5);

			Polynomial t_actual = p * m;
			Polynomial t_exprected("0");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(zero_and_polynom)
		{
			Polynomial p("3x^3 + 2x^2 - 10");
			Monomial m(0, 0);

			Polynomial t_actual = p * m;
			Polynomial t_exprected("0");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(two_monoms)
		{
			Polynomial p("3x^3");
			Monomial m(4, 5);

			Polynomial t_actual = p * m;
			Polynomial t_exprected("12x^8");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}
	};

	TEST_CLASS(Polynomtimespolynom)
	{
		TEST_METHOD(just_polynoms)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x^2 - 4x + 2");

			Polynomial t_actual = p1 * p2;
			Polynomial t_exprected("6x^5 - 8x^4 - 2x^3 - 16x^2 + 40x - 20");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_number)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("1.5");

			Polynomial t_actual = p1 * p2;
			Polynomial t_exprected("4.5x^3 + 3x^2 - 15");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_zero)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("0");

			Polynomial t_actual = p1 * p2;
			Polynomial t_exprected("0");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_monom)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x");

			Polynomial t_actual = p1 * p2;
			Polynomial t_exprected("6x^4 + 4x^3 - 20x");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}
	};

	TEST_CLASS(Polynompluspolynom)
	{
		TEST_METHOD(just_polynoms)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x^2 - 4x + 2");

			Polynomial t_actual = p1 + p2;
			Polynomial t_exprected("3x^3 + 4x^2 - 4x - 8");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_monom)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x^4");

			Polynomial t_actual = p1 + p2;
			Polynomial t_exprected("2x^4 + 3x^3 + 2x^2 - 10");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_number)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("5");

			Polynomial t_actual = p1 + p2;
			Polynomial t_exprected("3x^3 + 2x^2 - 5");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(different_sizes)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("5x^2 - 10x");

			Polynomial t_actual = p1 + p2;
			Polynomial t_exprected("3x^3 + 7x^2 -10x - 10");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}
	};

	TEST_CLASS(Polynomminuspolynom)
	{
		TEST_METHOD(just_polynoms)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x^2 - 4x + 2");

			Polynomial t_actual = p1 - p2;
			Polynomial t_exprected("3x^3 + 4x - 12");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_monom)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("2x^4");

			Polynomial t_actual = p1 - p2;
			Polynomial t_exprected("-2x^4 + 3x^3 + 2x^2 - 10");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(polynom_and_number)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("5");

			Polynomial t_actual = p1 - p2;
			Polynomial t_exprected("3x^3 + 2x^2 - 15");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}

		TEST_METHOD(different_sizes)
		{
			Polynomial p1("3x^3 + 2x^2 - 10");
			Polynomial p2("5x^2 - 10x");

			Polynomial t_actual = p1 - p2;
			Polynomial t_exprected("3x^3 - 3x^2 + 10x - 10");
			Assert::AreEqual(t_actual.Getpoly().size(), t_exprected.Getpoly().size(), L"Assert 1");
			Assert::IsTrue(ToString(t_actual.Getpoly()) == ToString(t_exprected.Getpoly()), L"Assert 2");
		}
	};
}
