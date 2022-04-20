#pragma once
#include "Stringmanager.h" // Тут описана работа со строками для удобства коструктора многочлена строкой и для вывода многочлена

class Polynomial 
{
private:
	vector<Monomial> polynom;
	int max_degree; // Ненужное в данном проекте поле, написал на будущее

	void Stabilize_polynom(); // Сортирует многочлен по убыванию степени и приводит подобные
public:
	Polynomial();
	Polynomial(vector<Monomial> _poly);
	Polynomial(string s);
	virtual ~Polynomial() {}

	int Getdegree() { return max_degree; }
	vector<Monomial> Getpoly() { return polynom; }
	void Show();
	float Calculate(float x); // Также ненужный метод, считает значение многочлена в точке

	friend Polynomial operator * (const Polynomial& p, const float& num);
	friend Polynomial operator * (const float& num, const Polynomial& p);
	friend Polynomial operator * (const Monomial& m, const Polynomial& p);
	friend Polynomial operator * (const Polynomial& p, const Monomial& m);
	friend Polynomial operator * (const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator + (const Polynomial& p1, const Polynomial& p2); //Основная логика описана в Stabilize_polynom()
	friend Polynomial operator - (const Polynomial& p1, const Polynomial& p2);
};