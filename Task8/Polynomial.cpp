#include "Polynomial.h"
#include <algorithm>
#include <iostream>
#include <cmath>


bool comp(Monomial lhs, Monomial rhs)
{
	return lhs.Getmonom().second > rhs.Getmonom().second;
}

void Polynomial::Stabilize_polynom()
{
	if (polynom.size() == 1)
	{
		if (polynom[0].Getcoef() == 0)
			polynom[0].Setdegree(0);
		return;
	}

	sort(polynom.begin(), polynom.end(), comp);
	for (int i = 0; i < polynom.size() - 1; i++)
	{
		if (polynom[i].Getdegree() == polynom[i + 1].Getdegree())
		{
			polynom[i].Setcoef(polynom[i].Getcoef() + polynom[i + 1].Getcoef());
			polynom[i+1].Setcoef(0);
		}
	}
	for (int i = 0; i < polynom.size(); i++)
	{
		if (polynom[i].Getcoef() == 0)
		{
			polynom.erase(polynom.begin() + i);
			i--;
		}
	}
	if (polynom.size() == 0)
		polynom.push_back(Monomial(0, 0));
}

Polynomial::Polynomial()
{
	polynom = vector<Monomial>(1);
	polynom[0].Setcoef(0);
	polynom[0].Setdegree(0);
	max_degree = 0;
}

Polynomial::Polynomial(vector<Monomial> _poly)
{
	polynom = _poly;
	Stabilize_polynom();
	max_degree = polynom[0].Getdegree();
}

Polynomial::Polynomial(string s)
{
	Stringmanager sm;
	polynom = sm.String_to_polynom(s);
	Stabilize_polynom();
	max_degree = polynom[0].Getdegree();
}

void Polynomial::Show()
{
	Stringmanager sm;
	string str = sm.Polynom_to_string(polynom);
	cout << str;
}

float Polynomial::Calculate(float x)
{
	float result = 0;
	
	for (int i = 0; i < polynom.size(); i++)
	{
		Monomial monom = polynom[i];
		result += monom.Getcoef() * pow(x, monom.Getdegree());
	}
	return result;
}

Polynomial operator * (const Polynomial& p, const float& num)
{
	vector<Monomial> poly = p.polynom;

	for (int i = 0; i < poly.size(); i++)
		poly[i] = num* poly[i];

	return Polynomial(poly);
}

Polynomial operator*(const float& num, const Polynomial& p)
{
	vector<Monomial> poly = p.polynom;

	for (int i = 0; i < poly.size(); i++)
		poly[i] = num* poly[i];

	return Polynomial(poly);
}

Polynomial operator * (const Monomial& m, const Polynomial& p)
{
	vector<Monomial> poly = p.polynom;

	for (int i = 0; i < poly.size(); i++)
		poly[i] = m* poly[i];

	return Polynomial(poly);
}

Polynomial operator*(const Polynomial& p, const Monomial& m)
{
	vector<Monomial> poly = p.polynom;

	for (int i = 0; i < poly.size(); i++)
		poly[i] = m* poly[i];

	return Polynomial(poly);
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2)
{
	vector<Monomial> poly1 = p1.polynom;
	vector<Monomial> poly2 = p2.polynom;
	vector<Monomial> result;

	for (int i = 0; i < poly1.size(); i++)
	{
		for (int j = 0; j < poly2.size(); j++)
			result.push_back(poly1[i] * poly2[j]);
	}

	return Polynomial(result);
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
	vector<Monomial> poly1 = p1.polynom;
	vector<Monomial> poly2 = p2.polynom;
	vector<Monomial> result;

	for (int i = 0; i < poly1.size(); i++)
		result.push_back(poly1[i]);
	for (int i = 0; i < poly2.size(); i++)
		result.push_back(poly2[i]);
	
	return Polynomial(result);
}

Polynomial operator-(const Polynomial& p1, const Polynomial& p2)
{
	vector<Monomial> poly1 = p1.polynom;
	vector<Monomial> poly2 = p2.polynom;
	vector<Monomial> result;

	for (int i = 0; i < poly2.size(); i++)
		poly2[i].Setcoef(-1 * poly2[i].Getcoef());

	for (int i = 0; i < poly1.size(); i++)
		result.push_back(poly1[i]);
	for (int i = 0; i < poly2.size(); i++)
		result.push_back(poly2[i]);

	return Polynomial(result);
}
