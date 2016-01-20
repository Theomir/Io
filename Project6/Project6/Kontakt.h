#ifndef KONTAKT_H
#define KONTAKT_H
#include <string>
using namespace std;
class Kontakt
{
	string imie;
	string nazwisko;
	string mail;
	string adres_dom;
	string telefon_dom;
	string adres_biuro;
	string telefon_biuro;
	string telefon_kom;
	string notatki;
public:
	Kontakt()
	{
	};
	Kontakt(string n, string c, string m, string ic, string tc, string iu, string tu, string tcel, string no);
	void input();
	void WyswietlKontakt(int n_id) const;
	bool operator == (const Kontakt & n) const;
	bool operator < (const Kontakt & n) const;
	string stworzWierszCSV() const;
};
#endif