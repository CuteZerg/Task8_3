#include <iostream>
#include "Polynomial.h"
#include <windows.h> 


void individual1(int n) // Индивидуальное задание под номером 1 (построить и вывести многочлен Чебышева)
{
	vector<Polynomial> T;
	Monomial _2x(2, 1);
	T.push_back(Polynomial("1"));
	T.push_back(Polynomial("x"));
	for (int i = 2; i < n + 1;i++)
	{
		T.push_back(_2x * T[i - 1] - T[i - 2]);
	}

	int num;
	cout << "Введите номер многочлена Чебышева для вывода:\n";
	cin >> num;
	if ((num < 0) || (num > n))
	{
		cout << "Номер должен быть целым числом от 0 до n";
		return;
	}
	T[num].Show();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	individual1(10);

	return 0;
}