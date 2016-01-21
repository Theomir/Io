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
	void czytajPlik(string nazwapliku); //otwieranie pliku
	bool zapiszPlik(string nazwapliku); //zpaisywanie pliku
	void dodaj_wydarzenie(); //dodawanie wydarzen
	void dodaj_wydarzenie(terminy nowy); //dodawanie wydarzen z elementem
	void usun_wydarzenie(); //usuwanie wydarzenia
	void usun_wygasniete(); //usuwanie wygasnietych wydarzen
	void wyswietl_wydarzenia_dnia(); //wyswietlanie wydarzenia na dzis
	void wyswietl_wydarzenia_dnia(terminy data, bool nowy_ekran = true); //wyswietlanie wydarzen dla konkretnej daty
	void wypiszTerminy(); //wypisywanie terminow
	int wypiszTerminy(terminy d);
};
#endif