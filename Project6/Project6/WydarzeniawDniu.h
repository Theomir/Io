#ifndef DZIEN_WYDARZENIA_H
#define DZIEN_WYDARZENIA_H
#include "Wydarzenie.h"
#include <list>
using namespace std;
class dzien_wydarzenie
{
	list < Wydarzenie * > lista_wydarzen; //tworzenie listy wydarzen
public:
	dzien_wydarzenie()
	{
	};//konstruktor
	~dzien_wydarzenie();//destruktor
	int nrWydarzenia() const;// numer wydarzenia
	void dodajWydarzenie(Wydarzenie * nowe_wydarzenie);// dodawanie wydarzen
	void wprowadz_wydarzenie();//wprowadzenie
	void wypiszWydarzenie();//wypisywanie
	string zapiszWydarzenieWDniu(terminy data); //zapisywanie wydarzenia do danego dnia
	void wypiszTerminy(string tytu³); //wypisywanie terminu
	void usun_wydarzenie_z_listy(); //usuwanie wydarzenia
	int usun_wszystkie_wydarzenia();//usuwanie wszystkich wydarzen
};
#endif