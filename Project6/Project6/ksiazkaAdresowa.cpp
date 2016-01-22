#include "ksiazkaAdresowa.h"
#include "Funkcje.h"
#include <fstream>
#include <string>
using namespace std;
void ksiazka_adresowa::czytajPlik(string nazwapliku)  //wczytywanie ksiazki z pliku
{
	fstream ksiazka_adresowa_plik;
	char str[4096];
	ksiazka_adresowa_plik.open(nazwapliku.c_str(), ios::in | ios::out);
	if (ksiazka_adresowa_plik.fail())
	{
		blad_wydruku("Plik ksiazki adresowej: '" + nazwapliku + "' nie istnieje, zostanie utworzona od zera");
		return;
	}
	while (!ksiazka_adresowa_plik.eof())
	{
		int akapit[9];
		int i, j, numer_linii = 0;
		str[0] = '\0';
		if (ksiazka_adresowa_plik.getline(str, 4096))
		{
			if (ksiazka_adresowa_plik.fail())
			{
				blad_wydruku("blad odczytu danych '" + nazwapliku + "'");
				return;
			}
			numer_linii++;
			for (i = 0, j = 0; str[i] != '\0' && j < 10; i++)
				if (str[i] == ';')
					akapit[j++] = i;
			akapit[j] = i;
			string s;
			if (j != 8)
				blad_wydruku("Znaleziono b³edy w '" + nazwapliku + "'!, linia " + int_to_string(numer_linii) + "");
			else
			{
				string linia_kontakt(str);
				linia_kontakt.append(";");
				string n(linia_kontakt, 0, akapit[0] - 0);
				string c(linia_kontakt, akapit[0] + 1, akapit[1] - akapit[0] - 1);
				string m(linia_kontakt, akapit[1] + 1, akapit[2] - akapit[1] - 1);
				string ic(linia_kontakt, akapit[2] + 1, akapit[3] - akapit[2] - 1);
				string tc(linia_kontakt, akapit[3] + 1, akapit[4] - akapit[3] - 1);
				string iu(linia_kontakt, akapit[4] + 1, akapit[5] - akapit[4] - 1);
				string tu(linia_kontakt, akapit[5] + 1, akapit[6] - akapit[5] - 1);
				string tcel(linia_kontakt, akapit[6] + 1, akapit[7] - akapit[6] - 1);
				string no(linia_kontakt, akapit[7] + 1, akapit[8] - akapit[7] - 1);

				Kontakt cont_corr(n, c, m, ic, tc, iu, tu, tcel, no);

				lista_kontaktow.push_back(cont_corr);
			}
		}
	}
	lista_kontaktow.unique();
	lista_kontaktow.sort();
	ksiazka_adresowa_plik.close();
}
bool ksiazka_adresowa::zapiszPlik(string nazwapliku)
{
	fstream ksiazka_adresowa_plik;
	ksiazka_adresowa_plik.open(nazwapliku.c_str(), ios::out);
	if (ksiazka_adresowa_plik.fail())
	{
		blad_wydruku("Blad otwarcia ksiazki adresowej!");
		return false;
	}
	list < Kontakt >::iterator it;
	for (it = lista_kontaktow.begin(); it != lista_kontaktow.end(); it++)
		ksiazka_adresowa_plik << (*it).stworzWierszCSV() << "\n";
	ksiazka_adresowa_plik.close();
	return true;
}
void ksiazka_adresowa::dodaj_kontakt()
{
	czyszczenie_ekranu();
	Kontakt nuovoc;
	nuovoc.input();
	lista_kontaktow.push_back(nuovoc);
	lista_kontaktow.unique();
	lista_kontaktow.sort();
}
void ksiazka_adresowa::usun_kontakt()
{
	wypisz_adres();
	int i, n_id;
	if (lista_kontaktow.size() > 0)
	{
		n_id = int_input("wprowadz numer kontaktu ktory ma byc usuniety (0 aby anulowac): ", 0, lista_kontaktow.size());
		list < Kontakt >::iterator it;
		for (it = lista_kontaktow.begin(), i = 0; it != lista_kontaktow.end(); it++)
			if (++i == n_id)
			{
				lista_kontaktow.remove(*it);
				break;
			}
	}
}
void ksiazka_adresowa::wypisz_adres()
{
	int i;
	wypisz_naglowek("KSIAZKA ADRESOWA");
	cout << "| [" << lista_kontaktow.size() << " Kontakt ]\n";
	cout << "|\n";
	list < Kontakt >::iterator it;
	for (it = lista_kontaktow.begin(), i = 0; it != lista_kontaktow.end(); it++)
		(*it).WyswietlKontakt(++i);
	pauza();
}