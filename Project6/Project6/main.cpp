#include "ksiazkaAdresowa.h"
#include "Funkcje.h"
#include "Kalendarz.h"
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
const string ksiazka_plik = "ksiazka_adresowa.csv";
const string kalendarz_plik = "kalendarz.csv";
int main()
{
	int n_op;
	ksiazka_adresowa r_glowna;
	Kalendarz a_glowna;
	int temp1;
	terminy data1, data2;
	data1.dataBiezaca();
	data2.dataBiezaca(); data2++;
	r_glowna.czytajPlik(ksiazka_plik);
	a_glowna.czytajPlik(kalendarz_plik);
	do
	{
		pokaz_menu(a_glowna.wypiszTerminy(data1), a_glowna.wypiszTerminy(data2));
		n_op = int_input(" Co zrobic: ", 1, 14);

		switch (n_op)
		{
		case 1:
			a_glowna.dodaj_wydarzenie();
			pauza();
			break;
		case 2:
			data1.dataBiezaca();
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 3:
			data1.dataBiezaca();
			data1++;
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 4:
			data1.input();
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 5:
			temp1 = int_input("Liczba dni (1-30): ", 1, 30);
			data1.dataBiezaca();
			wypisz_naglowek("WYDARZENIA NA NASTEPNE " + int_to_string(temp1) + " DNI");
			for (int i = 1; i <= temp1; i++)
				a_glowna.wyswietl_wydarzenia_dnia(data1++, false);
			pauza();
			break;
		case 6:
			data1.input(" od ");
			data2.input(" Do ");
			wypisz_naglowek("WYDARZENIA OD " + data1.to_string() + " DO " + data2++.to_string());
			while (data1 < data2)
				a_glowna.wyswietl_wydarzenia_dnia(data1++, false);
			pauza();
			break;
		case 7:
			a_glowna.wypiszTerminy();
			break;
		case 8:
			r_glowna.wypisz_adres();
			break;
		case 9:
			r_glowna.dodaj_kontakt();
			break;
		case 10:
			r_glowna.usun_kontakt();
			break;
		case 11:
			a_glowna.usun_wydarzenie();
			break;
		case 12:
			if (potwierdzenie(" Usunac wygasniete wydarzenia (y/n) ?"))
				a_glowna.usun_wygasniete();
			break;
		case 14:
			if (potwierdzenie(" Czy chcesz wyjsc bez zapisywania(y/n) ?"))
				exit(1);
			break;
		}
	} while (n_op != 13);
	while (!r_glowna.zapiszPlik(ksiazka_plik) || !a_glowna.zapiszPlik(kalendarz_plik))
	{
		cout << "\t[blad zapisywania pliku]\n";
		pauza();
	}
	cout << "\t[ Zmiany prawidlowo zapisane w pliku ]\n";
	pauza();
	return 0;
}
