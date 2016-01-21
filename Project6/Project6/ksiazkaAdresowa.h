#ifndef KSIAZKA_H
#define KSIAZKA_H
#include <list>
#include "Kontakt.h"
class ksiazka_adresowa
{
	list<Kontakt> lista_kontaktow;
public:
	ksiazka_adresowa() {   }//twoerzenie nowej ksiazki adresowej
	~ksiazka_adresowa() { lista_kontaktow.clear(); } // usuwanie ksiazki adrsowej
	void czytajPlik(string nazwapliku);//otwieranie pliku csv
	bool zapiszPlik(string nazwapliku);//zapisywanie do pliku csv
	void dodaj_kontakt();//dodawanie kontaktow
	void usun_kontakt();//usuwanie kontaktow
	void wypisz_adres();//wypisywanie adresu
} ;
#endif