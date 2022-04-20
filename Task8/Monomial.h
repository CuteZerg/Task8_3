#pragma once
#include <vector>

using namespace std;

class Monomial
{
private:
	float coef;
	int degree;
public:
	Monomial();
	Monomial(float _coef, int _degree);
	virtual ~Monomial() {}

	float Getcoef() { return coef; }
	int Getdegree() { return degree; }
	pair<float, int> Getmonom() { return monom; }
	void Setcoef(float val);
	void Setdegree(int val);

	friend Monomial operator*(const Monomial& m1, const Monomial& m2);
	friend Monomial operator*(const float& num, const Monomial& m);
	friend Monomial operator*(const Monomial& m, const float& num);

	pair<float, int> monom; //Пришлось сделать поле публичным, чтобы можно было реализовать метод ToString в юнит-тестах
};

