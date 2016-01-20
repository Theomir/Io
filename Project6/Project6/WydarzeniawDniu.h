#ifndef DZIEN_WYDARZENIA_H
#define DZIEN_WYDARZENIA_H
#include "Wydarzenie.h"
#include <list>
using namespace std;
class dzien_wydarzenie
{
	list < Wydarzenie * > lista_wydarzen;
public:
	dzien_wydarzenie()
	{
	};
	~dzien_wydarzenie();
	int nrWydarzenia() const;
	void dodajWydarzenie(Wydarzenie * nowe_wydarzenie);
	void wprowadz_wydarzenie();
	void wypiszWydarzenie();
	string zapiszWydarzenieWDniu(terminy data);
	void wypiszTerminy(string tytu³);
	void usun_wydarzenie_z_listy();
	int usun_wszystkie_wydarzenia();
};
#endif