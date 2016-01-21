#ifndef TERMINY_H
#define TERMINY_H
#include <iostream>
using namespace std;
const string miesiace[] =
{ "", "styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "sierpien", "wrzesien", "pazdziernik", "listopad", "grudzien" };//tablica miesiecy
const int dlugosc_miesiecy[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//tablica dl miesiecy
const int dlugosc_miesiecy_przyrostowo[] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };//tablica dlugosci przytostowej miesiecy
class terminy
{
	int dzien; //numer dnia
	int miesiac;//numer miesiaca
	int rok;//nuker roku
public:
	terminy()
	{ }//konstruktor
	terminy(int g, int m, int a) : dzien(g), miesiac(m), rok(a)
	{ }//konstruktor 2
	void input(string tekst = "| Wstaw termin");//wprowadzanie danych
	bool input_from_string(string str_data);//wprowadzanie ze stringa
	string to_string() const;//konwertorowanie do stringa
	string to_csv() const;//konwerterowanie do csv
	bool operator == (const terminy & d) const;//przeciazenie operatora ==
	bool operator < (const terminy & d) const;//przeciazenie operatora <
	terminy operator ++ (int); // przeciazenie operatora ++
	bool format_daty(); //format daty
	void dataBiezaca();//data aktualna z systemu
	friend ostream& operator<<(ostream&, terminy&); //przeciazenie operatora <<
};
#endif