#ifndef KONTAKT_H
#define KONTAKT_H
#include <string>
using namespace std;
class Kontakt
{
	string imie; //imie
	string nazwisko;//nazwisko
	string mail;//adres mailowy
	string adres_dom; //adres domowy
	string telefon_dom;//numer telefonu domowwego
	string adres_biuro;//adres biura
	string telefon_biuro;// numer telefonu do biura
	string telefon_kom;//numer telefonu komórowego
	string notatki ;//inne
public:
	Kontakt()
	{
	};
	Kontakt(string n, string c, string m, string ic, string tc, string iu, string tu, string tcel, string no);
	void input();//wprowadzanie
	void WyswietlKontakt(int n_id) const;//wyswietlanie kontaktow
	bool operator == (const Kontakt & n) const;//przeciazenie operatora ==
	bool operator < (const Kontakt & n) const;//przeciazenie operatora 
	string stworzWierszCSV() const; //dodawanie do CSV
};
#endif