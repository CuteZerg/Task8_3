#pragma once
#include "Stringmanager.h" // ��� ������� ������ �� �������� ��� �������� ����������� ���������� ������� � ��� ������ ����������

class Polynomial 
{
private:
	vector<Monomial> polynom;
	int max_degree; // �������� � ������ ������� ����, ������� �� �������

	void Stabilize_polynom(); // ��������� ��������� �� �������� ������� � �������� ��������
public:
	Polynomial();
	Polynomial(vector<Monomial> _poly);
	Polynomial(string s);
	virtual ~Polynomial() {}

	int Getdegree() { return max_degree; }
	vector<Monomial> Getpoly() { return polynom; }
	void Show();
	float Calculate(float x); // ����� �������� �����, ������� �������� ���������� � �����

	friend Polynomial operator * (const Polynomial& p, const float& num);
	friend Polynomial operator * (const float& num, const Polynomial& p);
	friend Polynomial operator * (const Monomial& m, const Polynomial& p);
	friend Polynomial operator * (const Polynomial& p, const Monomial& m);
	friend Polynomial operator * (const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator + (const Polynomial& p1, const Polynomial& p2); //�������� ������ ������� � Stabilize_polynom()
	friend Polynomial operator - (const Polynomial& p1, const Polynomial& p2);
};