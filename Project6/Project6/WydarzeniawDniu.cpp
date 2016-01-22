#include "WydarzeniawDniu.h"
#include <typeinfo>
/// \details dzien_wydarzenie

dzien_wydarzenie::~dzien_wydarzenie()
{
	usun_wszystkie_wydarzenia();
}
/// \details lista wydarzen
/// \return lista
int dzien_wydarzenie::nrWydarzenia() const
{
	return lista_wydarzen.size();
}
/// \details wprowadzenie wydarzenia do listy wydarzen
void dzien_wydarzenie::dodajWydarzenie(Wydarzenie * nowe_wydarzenie) //wprowadzenie wydarzenia do listy wydarzen
{
	lista_wydarzen.push_back((Wydarzenie *)nowe_wydarzenie);
}
/// \details okreslenie typu wydarzenia
void dzien_wydarzenie::wprowadz_wydarzenie() //okreslenie typu wydarzenia
{
	int typ_ev;
	typ_ev = int_input("| Wpisz typ wydarzenia: [1=Spotkanie, 2=Termin, 3=Notatki ]: ", 1, 3);
	if (typ_ev == 1)
	{
		Spotkanie * nowe_wydarzenie = new Spotkanie();
		nowe_wydarzenie->input();
		dodajWydarzenie(nowe_wydarzenie);
	}
	else if (typ_ev == 2)
	{
		termin * nowe_wydarzenie = new termin();
		nowe_wydarzenie->input();
		dodajWydarzenie(nowe_wydarzenie);
	}
	else
	{
		notatki * nowe_wydarzenie = new notatki();
		nowe_wydarzenie->input();
		dodajWydarzenie(nowe_wydarzenie);
	}
}
/// \details wpisanie wydarzen
void dzien_wydarzenie::wypiszWydarzenie()
{
	int i = 1;
	if (lista_wydarzen.size() == 0)
		cout << "|\t[ Brak wydarzen do wyswietlenia]\n|\n";
	else
	{
		list < Wydarzenie * >::iterator it;
		for (it = lista_wydarzen.begin(); it != lista_wydarzen.end(); it++)
			(*it)->wyswietl(i++);
	}
	cout << "|\n";
}
/// \details zapisanie wydarzenia
string dzien_wydarzenie::zapiszWydarzenieWDniu(terminy data)  //zapis wydarzenia do pliku
{
	string temp("");
	list < Wydarzenie * >::iterator it;
	for (it = lista_wydarzen.begin(); it != lista_wydarzen.end(); it++)
		temp += ((*it)->to_csv(data)) + "\n";
	return temp;
}
/// \details wyswietlenie wydarzen w biezacym dniu
void dzien_wydarzenie::wypiszTerminy(string tytu³)  //wyswietlenie wydarzen w biezacym dniu
{
	int i = 1;
	list < Wydarzenie * >::iterator it;
	for (it = lista_wydarzen.begin(); it != lista_wydarzen.end(); it++)
	{
		if (typeid(*(*it)) == typeid(termin))
		{
			cout << tytu³;
			(*it)->wyswietl(i++);
		}
	}
}
/// \details usuwanie wydarzen 
void dzien_wydarzenie::usun_wydarzenie_z_listy()
{
	int numer, i;
	wypiszWydarzenie();
	numer = int_input("| Wprowadz numer zdarzenia ktore ma byc usuniete (0, aby anulowac): ", 0);
	list < Wydarzenie * >::iterator it;
	for (it = lista_wydarzen.begin(), i = 0; it != lista_wydarzen.end(); it++)
		if (++i == numer)
		{
			lista_wydarzen.remove(*it);
			break;
		}
}
/// \details usuwanie wszystkich wydarzen
int dzien_wydarzenie::usun_wszystkie_wydarzenia()
{
	int n_ev = lista_wydarzen.size();
	list < Wydarzenie * >::iterator it;
	for (it = lista_wydarzen.begin(); it != lista_wydarzen.end(); it++)
		delete(*it);
	lista_wydarzen.clear();
	return n_ev;
}