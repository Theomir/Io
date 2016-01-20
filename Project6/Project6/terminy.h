#ifndef TERMINY_H
#define TERMINY_H
#include <iostream>
using namespace std;
const string miesiace[] =
{ "", "styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien" };
const int dlugosc_miesiecy[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int dlugosc_miesiecy_przyrostowo[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
class terminy
{
	int dzien;
	int miesiac;
	int rok;
public:
	terminy()
	{ }
	terminy(int g, int m, int a) : dzien(g), miesiac(m), rok(a)
	{ }
	void input(string tekst = "| Wstaw termin");
	bool input_from_string(string str_data);
	string to_string() const;
	string to_csv() const;
	bool operator == (const terminy & d) const;
	bool operator < (const terminy & d) const;
	terminy operator ++ (int);
	bool format_daty();
	void dataBiezaca();
	friend ostream& operator<<(ostream&, terminy&);
};
#endif