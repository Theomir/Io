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
	do												// menu glowne 
	{
		pokaz_menu(a_glowna.wypiszTerminy(data1), a_glowna.wypiszTerminy(data2));
		n_op = int_input(" Co zrobic: ", 1, 14);
		switch (n_op)
		{
		case 1:  //dowdawanie wydarzenia
			a_glowna.dodaj_wydarzenie();
			pauza();
			break;
		case 2:
			data1.dataBiezaca(); // wsywietl wydarzenia na dzis
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 3:
			data1.dataBiezaca(); //wysietl wydarzenia na jutro
			data1++;
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 4: //wyswietl wydarzenia dla konkretnego dnia
			data1.input();
			a_glowna.wyswietl_wydarzenia_dnia(data1);
			break;
		case 5://wyswietl wydarzenia w najblizszych dniach
			temp1 = int_input("Liczba dni (1-30): ", 1, 30);
			data1.dataBiezaca();
			wypisz_naglowek("WYDARZENIA NA NASTEPNE " + int_to_string(temp1) + " DNI");
			for (int i = 1; i <= temp1; i++)
				a_glowna.wyswietl_wydarzenia_dnia(data1++, false);
			pauza();
			break;
		case 6: // wyswietl wydarzenia od do
			data1.input(" od ");
			data2.input(" Do ");
			wypisz_naglowek("WYDARZENIA OD " + data1.to_string() + " DO " + data2++.to_string());
			while (data1 < data2)
				a_glowna.wyswietl_wydarzenia_dnia(data1++, false);
			pauza();
			break;
		case 7://wypisz terminy w najblizszych tygodniach
			a_glowna.wypiszTerminy();
			break;
		case 8://wyswietl ksiazke adrsowa
			r_glowna.wypisz_adres();
			break;
		case 9://dodaj nowy kontakt
			r_glowna.dodaj_kontakt();
			break;
		case 10://usun kontakt
			r_glowna.usun_kontakt();
			break;
		case 11://ususn wydarzenie
			a_glowna.usun_wydarzenie();
			break;
		case 12://usun wygasniete wydarzenia
			if (potwierdzenie(" Usunac wygasniete wydarzenia (y/n) ?"))
				a_glowna.usun_wygasniete();
			break;
		case 14://wychodzenie bez zapisywania
			if (potwierdzenie(" Czy chcesz wyjsc bez zapisywania(y/n) ?"))
				exit(1);
			break;
		}
	} while (n_op != 13);// zapisz i wyjdz
	while (!r_glowna.zapiszPlik(ksiazka_plik) || !a_glowna.zapiszPlik(kalendarz_plik))
	{
		cout << "\t[blad zapisywania pliku]\n";
		pauza();
	}
	cout << "\t[ Zmiany prawidlowo zapisane w pliku ]\n";//zapisanie poprawne plików
	pauza();
	return 0;
}
