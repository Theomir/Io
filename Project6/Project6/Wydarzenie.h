#ifndef WYDARZENIE_H
#define WYDARZENIE_H
#include "terminy.h"
#include "Funkcje.h"
#include <iostream>
#include <string>
using namespace std;
class Wydarzenie
{
	string typ;
public:
	Wydarzenie(string t);
	virtual void wyswietl(int n_wydarzenie) const;
	virtual string to_csv(terminy data) const = 0;
	void wyznacz_i_pokaz_trase(string trasa);
	void input();
};
class Spotkanie : public Wydarzenie
{
	string nazwa;
	string miejsce;
	string nazwisko_osoby;
	string notatki;
public:
	Spotkanie();
	Spotkanie(string nazwa, string l, string np, string n);
	void wyswietl(int n_wydarzenie) const;
	string to_csv(terminy data) const;
	void input();
};
const string gwiazdki[] =
{
	"", "*", "**", "***", "****", "*****"
};
class termin : public Wydarzenie
{
	string nazwa;
	int piorytet;
	string notatki;
public:
	termin() : Wydarzenie("TERMIN")
	{
	}
	termin(string nazwa, int piorytet, string n);
	void wyswietl(int n_wydarzenie) const;
	string to_csv(terminy data) const;
	void input();
};
class notatki : public Wydarzenie
{
	string tekst;
public:
	notatki() : Wydarzenie("NOTATKI")
	{
	}
	notatki(string t);
	void wyswietl(int n_wydarzenie) const;
	string to_csv(terminy data) const;
	void input();
};
#endif