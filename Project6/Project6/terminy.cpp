#define _CRT_SECURE_NO_WARNINGS
#include "terminy.h"
#include <iostream>
#include <ctime>
#include <string>
#include "Funkcje.h"

using namespace std;

bool terminy::input_from_string(string str_data) //wprowadzenie dnia slownie
{
	int d1 = str_data.find('-');
	int d2 = str_data.find_last_of('-');
	if (str_data == "dzisiaj")
		dataBiezaca();
	else if (str_data == "jutro")
	{
		dataBiezaca();
		(*this)++;
	}
	else
	{
		dzien = atoi(str_data.substr(0, d1).c_str());
		miesiac = atoi(str_data.substr(d1 + 1, d2 - d1).c_str());
		rok = atoi(str_data.substr(d2 + 1, str_data.length()).c_str());
	}
	return format_daty();
}
void terminy::input(string tekst)  //wprowadzanie daty wydarzenia
{
	string bufor;
	do
	{
		cout << tekst << ": dzisiaj | jutro || dd-mm-rrrr: ";
		bufor = string_input();
	} while (!input_from_string(bufor));
}
string terminy::to_string() const
{
	return string(int_to_string(dzien) + " " + miesiace[miesiac] + " " + int_to_string(rok));
}
string terminy::to_csv() const
{
	return string(int_to_string(dzien) + "-" + int_to_string(miesiac) + "-" + int_to_string(rok));
}
bool terminy::operator < (const terminy & d) const
{
	return ((rok * 365 + dlugosc_miesiecy_przyrostowo[miesiac] + dzien)
		< (d.rok * 365 + dlugosc_miesiecy_przyrostowo[d.miesiac] + d.dzien));
}
bool terminy::operator == (const terminy & d) const
{
	return (dzien == d.dzien && miesiac == d.miesiac && rok == d.rok);
}
terminy terminy::operator ++(int)
{
	terminy data(dzien, miesiac, rok);
	dzien++;
	if (dzien > dlugosc_miesiecy[miesiac])
	{
		miesiac++; dzien = 1;
	}
	if (miesiac > 12)
	{
		rok++; miesiac = 1;
	}
	return data;
}
bool terminy::format_daty()  //obsluga niepelnej daty
{
	bool val;
	if (rok < 100) rok += 2000;
	val = (dzien > 0 && dzien <= dlugosc_miesiecy[miesiac] && miesiac > 0 && miesiac <= 12 && rok >= 1950 && rok <= 2400);
	if (!val) cout << "Data " << to_string() << " nie poprawna !\n";
	return val;
}
void terminy::dataBiezaca()
{
	time_t tmp;
	struct tm * tm_aktualny;
	time(&tmp);
	tm_aktualny = localtime(&tmp);
	dzien = tm_aktualny->tm_mday;
	miesiac = tm_aktualny->tm_mon + 1;
	rok = 1900 + tm_aktualny->tm_year;
	format_daty();
}
ostream &operator << (ostream &s, terminy &d)
{
	return s << d.dzien << ' ' << miesiace[d.miesiac] << ' ' << d.rok;
}