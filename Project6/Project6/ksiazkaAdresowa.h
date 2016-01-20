#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <list>
#include "Kontakt.h"
class ksiazka_adresowa
{
	list<Kontakt> lista_kontaktow;
public:
	ksiazka_adresowa() {}
	~ksiazka_adresowa() { lista_kontaktow.clear(); }
	void czytajPlik(string nazwapliku);
	bool zapiszPlik(string nazwapliku);
	void dodaj_kontakt();
	void usun_kontakt();
	void wypisz_adres();
};
#endif