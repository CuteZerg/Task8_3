#include "Monomial.h"

Monomial::Monomial()
{
	monom = pair<float, int>(0, 0);
	coef = 0;
	degree = 0;
}

Monomial::Monomial(float _coef, int _degree)
{
	monom = pair<float, int>(_coef, _degree);
	coef = _coef;
	degree = _degree;
}

void Monomial::Setcoef(float val)
{
	coef = val;
	monom = pair<float, int>(coef, degree);
}

void Monomial::Setdegree(int val)
{
	degree = val;
	monom = pair<float, int>(coef, degree);
}

Monomial operator*(const Monomial& m1, const Monomial& m2)
{
	return Monomial(m1.coef * m2.coef, m1.degree + m2.degree);
}

Monomial operator * (const float& num, const Monomial& m)
{
	return Monomial(num * m.coef, m.degree);
}

Monomial operator * (const Monomial& m, const float& num)
{
	return Monomial(num * m.coef, m.degree);
}
