#define _CRT_SECURE_NO_WARNINGS
#define _AFX_SECURE_NO_DEPRECATE
#include "Funkcje.h"
#include <string>
#include <cstdio>
#include <cstdlib>
void czyszczenie_ekranu()
{
	system("cls");//komenda systemowa
}
void pauza()
{
	cout << ogranicznik;
	system("pause");
}
int int_input(string tekst, int min, int max)
{
	char bufor[15];
	int n;
	do
	{
		cout << tekst;
		cin >> bufor;
		n = atoi(bufor);
	} while (n < min || (max != -1 && n > max));
	return n;
}
string string_input()
{
	char bufor[255];
	do
	{
		gets_s(bufor);
	} while (bufor[0] == '\0');
	return string(bufor);
}
void wypisz_naglowek(string tytu³)
{
	const string dni[] =
	{
		"niedziela", "poniedzialek", "wtorek", "sroda", "czwartek", "piatek", "sobota"
	};
	terminy dzisiaj;
	dzisiaj.dataBiezaca();
	time_t tmp;
	struct tm *tm_aktualny;
	time(&tmp);
	tm_aktualny = localtime(&tmp);
	czyszczenie_ekranu();
	cout << ogranicznik;
	cout << "| --- " << tytu³ << " --- \n";
	cout << "| Dzisiaj: " << dni[tm_aktualny->tm_wday] << " " << dzisiaj << " - Godzina " << tm_aktualny->tm_hour << ":";
	cout.fill('0'); cout.width(2);
	cout << tm_aktualny->tm_min << "\n";
	cout << "|\n";
}
void blad_wydruku(string error)
{
	cout << "[ " << error << " ]\n";
	pauza();
}
void wprowadzanie_i_kontrola(string pole, string & wartosc)
{
	string temp;
	bool poprawny = false;
	while (!poprawny)
	{
		cout << pole;
		temp = string_input();
		if (temp == "nd" || temp == "ND") temp = "";
		if (temp.find(';') == -1)
			poprawny = true;
		else
		{
			poprawny = false;
			cout << "Znak ';' niedozwolony!\n";
		}
	}
	wartosc = temp;
}
bool potwierdzenie(string tekst)
{
	char sn;
	do
	{
		cout << tekst;
		cin >> sn;
	} while (sn != 'y' && sn != 'n');
	return sn == 'y';
}
void pokaz_menu(int wydarzenia_dzis, int wydarzenia_jutro)
{
	wypisz_naglowek();
	cout << "| 1 - Dodaj wydarzenie\n";
	cout << "| 2 - Dzisiejsze wydarzenia [" << wydarzenia_dzis << "]\n";
	cout << "| 3 - Wydarzenia jutrzejsze [" << wydarzenia_jutro << "]\n";
	cout << "| 4 - Wydarzenia ...\n";
	cout << "| 5 - Wydarzenia w najblizszych dniach ...\n";
	cout << "| 6 - Wydarzenia od ... do...\n";
	cout << "| 7 - Wydarzenia w najblizszych tygodniach ...\n";
	cout << "|\n";
	cout << "| --- Ksiazka adresowa ---\n";
	cout << "| 8 - Wyswietl ksiazke adresowa\n";
	cout << "| 9 - Dodaj nowy kontakt\n";
	cout << "| 10 - Usun kontakt ...\n";
	cout << "|\n";
	cout << "| 11 - Usun wydarzenie ...\n";
	cout << "| 12 - Usun wygasniete wydarzenia\n";
	cout << "|\n";
	cout << "| 13 - Zapisz i zamknij\n";
	cout << "| 14 - Wyjscie bez zapisywania\n";
	cout << ogranicznik;
}
string int_to_string(int n)
{
	string tmp, ret;
	if (n < 0) {
		ret = "-";
		n = -n;
	}
	do {
		tmp += n % 10 + 48;
		n -= n % 10;
	} while (n /= 10);
	for (int i = tmp.size() - 1; i >= 0; i--)
		ret += tmp[i];
	return ret;
}
