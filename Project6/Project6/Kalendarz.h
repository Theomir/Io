#ifndef KALENDARZ_H
#define KALENDARZ_H
#include <iostream>
#include <map>
#include "Funkcje.h"
#include "terminy.h"
#include "Wydarzenie.h"
#include "WydarzeniawDniu.h"
#include <fstream>
using namespace std;
class Kalendarz
{
	map < terminy, dzien_wydarzenie > kalendarz_wydarzen;
public:
	Kalendarz()
	{
	};
	~Kalendarz()
	{
		kalendarz_wydarzen.clear();
	}
	void czytajPlik(string nazwapliku);
	bool zapiszPlik(string nazwapliku);
	void dodaj_wydarzenie();
	void dodaj_wydarzenie(terminy nowy);
	void usun_wydarzenie();
	void usun_wygasniete();
	void wyswietl_wydarzenia_dnia();
	void wyswietl_wydarzenia_dnia(terminy data, bool nowy_ekran = true);
	void wypiszTerminy();
	int wypiszTerminy(terminy d);
};
#endif