#include "Stringmanager.h"
#include <sstream>
#include <iomanip>

string Stringmanager::Delete_spaces(string str)
{
    int i = str.find(" ");
    while (i != string::npos)
    {
        str.erase(i, 1);
        i = str.find(" ");
    }
   
    return str;
}

string Stringmanager::Get_first_monom_string(string str)
{
    Monomial monom;
    
    string str_tmp;
    for (int i = 0; i < str.size(); i++)
    {
        if ( ((str[i] == '+') || (str[i] == '-')) && (i != 0) )
            break;
        str_tmp.push_back(str[i]);
    }
    
    return str_tmp;
}

Monomial Stringmanager::String_to_monom(string str)
{
    Monomial monom;
    int sign = 1;

    if (str == "x")
        return Monomial(1, 1);

    if (str[0] == '+')
    {
        sign = 1;
        str.erase(str.begin());
    }
    else if (str[0] == '-')
    {
        sign = -1;
        str.erase(str.begin());
    }

    float coef;
    int degree;
    if (str.find("^") != string::npos)
    {
        coef = sign * stof(str.substr(0, str.size() - str.find("x")));
        degree = stoi(str.substr(str.find("^") + 1));
    }
    else if (str.find("x") != string::npos)
    {
        str.erase(str.size() - 1);
        coef = sign * stof(str);
        degree = 1;
    }
    else 
    {
        coef = sign * stof(str);
        degree = 0;
    }
    monom.Setcoef(coef);
    monom.Setdegree(degree);

    return monom;
}

vector<Monomial> Stringmanager::String_to_polynom(string str)
{
    str = Delete_spaces(str);
    if (str == "")
    {
        vector<Monomial> tmp;
        tmp.push_back(Monomial(0, 0));
        return tmp;
    }
        
    
    vector<Monomial> poly;
    Monomial monom;
    string str_monom;
    while (!str.empty())
    {
        str_monom = Get_first_monom_string(str);
        str.erase(0, str_monom.size());
        monom = String_to_monom(str_monom);
        poly.push_back(monom);
    }

    return poly;
}

string Stringmanager::Polynom_to_string(vector<Monomial> poly)
{
    stringstream ss;
    ss << fixed << setprecision(3);
    
    for (int i = 0; i < poly.size(); i++)
    {
        if ((poly[i].Getcoef() > 0) && (i != 0))
            ss  << "+";

        ss << poly[i].Getcoef();

        if (poly[i].Getdegree() > 1)
            ss  << "x^";
        else if (poly[i].Getdegree() == 1)
        {
            ss << "x";
            continue;
        }
        else
            continue;

        ss << poly[i].Getdegree();
    }
    return ss.str();
}
