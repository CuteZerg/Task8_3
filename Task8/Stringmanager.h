#pragma once
#include <string>
#include "Monomial.h"

using namespace std;

class Stringmanager
{
public:
	Stringmanager() { }
	virtual ~Stringmanager() {}

	vector<Monomial> String_to_polynom(string str); // Переводит строку в полином (НЕ в объект, а в вектор мономов)
	string Polynom_to_string(vector<Monomial> poly); // Обратная операция
private:
	string Get_first_monom_string(string str); // Из многочлена в строке вытаскивает первый моном
	Monomial String_to_monom(string str); // Преобразует результат метода выше в объект монома
	string Delete_spaces(string str); // Вспомогательный метод, просто удаляет все пробелы в строке
};

