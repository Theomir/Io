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
	virtual void wyswietl(int n_wydarzenie) const;//wyswietlanie
	virtual string to_csv(terminy data) const = 0;//zapisywanie do csv
	void wyznacz_i_pokaz_trase(string trasa);// wyznaczanie trasy
	void input(); //wprowadzanie danych
};
class Spotkanie : public Wydarzenie
{
	string nazwa;//nazwa spotkania
	string miejsce;//miejsce spotkania
	string nazwisko_osoby;//nazwisko osoby z ktora sie spotykamy
	string notatki;//notatki
public:
	Spotkanie();//konstruktor
	Spotkanie(string nazwa, string l, string np, string n);// konstrutor 2
	void wyswietl(int n_wydarzenie) const;// wyswietlanie
	string to_csv(terminy data) const;// zapisywanie do csv
	void input();//wprowadzanie
};
const string gwiazdki[] =
{
	"", "*", "**", "***", "****", "*****"
};//tablica piorytetow
class termin : public Wydarzenie
{
	string nazwa;//nazwa terminu
	int piorytet;//numer piorytetu
	string notatki;//notatki
public:
	termin() : Wydarzenie("TERMIN")
	{
	}//konstrutor
	termin(string nazwa, int piorytet, string n);//konstruktor 2
	void wyswietl(int n_wydarzenie) const;//wyswietlanie
	string to_csv(terminy data) const;//konwerterowanie do csv
	void input();//wprowadzanie
};
class notatki : public Wydarzenie
{
	string tekst;//notatka
public:
	notatki() : Wydarzenie("NOTATKI")
	{
	}//konstruktor
	notatki(string t);
	void wyswietl(int n_wydarzenie) const; //wyswietlanie
	string to_csv(terminy data) const;//zapisywanei do csv
	void input();//wprowadzanie
};
#endif