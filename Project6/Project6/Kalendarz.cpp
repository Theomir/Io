#include "Kalendarz.h"
using namespace std;
void Kalendarz::czytajPlik(string nazwapliku)
{
	fstream PlikKalendarza;
	int akapit[99];
	int i, j, numer_linii = 0, typ_ev;
	char str[4096];
	PlikKalendarza.open(nazwapliku.c_str(), ios::in);
	if (PlikKalendarza.fail())
	{
		blad_wydruku("Kalendarz" + nazwapliku + " nie istnieje, zostanie utworzony od zera");
		return;
	}
	while (!PlikKalendarza.eof())
	{
		str[0] = '\0';
		if (PlikKalendarza.getline(str, 4096))
		{
			numer_linii++;
			if (PlikKalendarza.fail())
			{
				blad_wydruku("Blad odczytu danych'" + nazwapliku + "', linia " + int_to_string(numer_linii) + " !");
				return;
			}
			for (i = 0, j = 0; str[i] != '\0'; i++)
				if (str[i] == ';')
					akapit[j++] = i;
			akapit[j] = i;
			string linia_kalendarz(str);
			linia_kalendarz.append(";");
			typ_ev = atoi(linia_kalendarz.substr(0, 1).c_str());
			if (j >= 2)
			{
				terminy data_wydarzenia;
				if (data_wydarzenia.input_from_string(linia_kalendarz.substr(akapit[0] + 1, akapit[1] - akapit[0] - 1)))
				{
					if (typ_ev == 1)
					{
						if (j >= 4)
						{
							Spotkanie * e = new
								Spotkanie(linia_kalendarz.substr(akapit[1] + 1, akapit[2] - akapit[1] - 1),
									linia_kalendarz.substr(akapit[2] + 1, akapit[3] - akapit[2] - 1), linia_kalendarz.substr(akapit[3] + 1, akapit[4] -
										akapit[3] - 1),
									linia_kalendarz.substr(akapit[4] + 1, akapit[5] - akapit[4] - 1));
							kalendarz_wydarzen[data_wydarzenia].dodajWydarzenie(e);
						}
						else
							blad_wydruku("Spotkanie niepoprawne '" + nazwapliku + "', linia " + int_to_string(numer_linii) + " !");
					}
					else if (typ_ev == 2)
					{
						if (j >= 4)
						{
							termin * e = new termin(linia_kalendarz.substr(akapit[1] + 1, akapit[2] - akapit[1] - 1),
								atoi(linia_kalendarz.substr(akapit[2] + 1, akapit[3] - akapit[2] - 1).c_str()),
								linia_kalendarz.substr(akapit[3] + 1, akapit[4] - akapit[3] - 1));
							kalendarz_wydarzen[data_wydarzenia].dodajWydarzenie(e);
						}
						else
							blad_wydruku("Termin niepoprawny '" + nazwapliku + "', linia " + int_to_string(numer_linii) + " !");
					}
					else if (typ_ev == 3)
					{
						notatki * e = new notatki(linia_kalendarz.substr(akapit[1] + 1, akapit[2] - akapit[1] - 1));
						kalendarz_wydarzen[data_wydarzenia].dodajWydarzenie(e);
					}
					else
						blad_wydruku("Typ wydarzenia niepoprawny '" + nazwapliku + "', linia " + int_to_string(numer_linii) + " !");
				}
				else
					blad_wydruku("Data niepoprawna '" + nazwapliku + "', linia " + int_to_string(numer_linii) + " ! ");
			}
			else
				blad_wydruku("Linia niepoprawna'" + nazwapliku + "', linia " + int_to_string(numer_linii) + " !");
		}
	}
	PlikKalendarza.close();
}

bool Kalendarz::zapiszPlik(string nazwapliku)
{
	fstream PlikKalendarza;
	PlikKalendarza.open(nazwapliku.c_str(), ios::out);

	if (PlikKalendarza.fail())
	{
		blad_wydruku("Blad otwierania pliku kalendarza'" + nazwapliku + "'!");
		return false;
	}
	map < terminy, dzien_wydarzenie >::iterator it;
	for (it = kalendarz_wydarzen.begin(); it != kalendarz_wydarzen.end(); it++)
	{
		PlikKalendarza << (*it).second.zapiszWydarzenieWDniu((*it).first);
	}
	PlikKalendarza.close();
	return true;
}
void Kalendarz::dodaj_wydarzenie()
{
	terminy nowy;
	wypisz_naglowek("DODAWANIE WYDARZEN");
	nowy.input();
	kalendarz_wydarzen[nowy].wprowadz_wydarzenie();
}
void Kalendarz::dodaj_wydarzenie(terminy nowy)
{
	kalendarz_wydarzen[nowy].wprowadz_wydarzenie();
}
void Kalendarz::usun_wydarzenie()
{
	terminy nowy;
	wypisz_naglowek("USUWANIE WYDARZEN");
	nowy.input();
	kalendarz_wydarzen[nowy].usun_wydarzenie_z_listy();
	pauza();
}
void Kalendarz::usun_wygasniete()
{
	int n_usuniety = 0;
	terminy dzisiaj;
	dzisiaj.dataBiezaca();
	map < terminy, dzien_wydarzenie >::iterator it;
	for (it = kalendarz_wydarzen.begin(); it != kalendarz_wydarzen.end(); it++)
	{
		if ((*it).first < dzisiaj)
			n_usuniety += (*it).second.usun_wszystkie_wydarzenia();
	}
	if (n_usuniety > 0)
		cout << "| " << n_usuniety << " Wydarzenie poprawnie usuniete.\n";
	else
		cout << "| brak wydarzen do usuniecia !\n";
	pauza();
}
void Kalendarz::wyswietl_wydarzenia_dnia()
{
	terminy data;
	data.input();
	wypisz_naglowek("Zobacz wydarzenia" + data.to_string());
	kalendarz_wydarzen[data].wypiszWydarzenie();
	pauza();
}
void Kalendarz::wyswietl_wydarzenia_dnia(terminy data, bool nowy_ekran)
{
	string tytu³ = "Zobacz wydarzenia" + data.to_string();
	if (nowy_ekran)
	{
		czyszczenie_ekranu();
		wypisz_naglowek(tytu³);
	}
	else
		cout << "+------ " << tytu³ << " ----------\n|\n";
	kalendarz_wydarzen[data].wypiszWydarzenie();
	if (nowy_ekran)
		pauza();
}
void Kalendarz::wypiszTerminy()
{
	int n_dni;
	terminy data;
	n_dni = 7 * int_input("Liczba tygodni : ", 1);
	czyszczenie_ekranu();
	wypisz_naglowek("Terminy na kolejne" + int_to_string(n_dni / 7) + " TYGODNI");
	data.dataBiezaca();
	for (int i = 0; i < n_dni; i++, data++)
		kalendarz_wydarzen[data].wypiszTerminy("|--- miedzy " + int_to_string(i) + " dni (" + data.to_string() + ")--\n");
	cout << "|-- Brak wydarzen przed " << data.to_string() << "\n";
	pauza();
}
int Kalendarz::wypiszTerminy(terminy d)
{
	return kalendarz_wydarzen[d].nrWydarzenia();
}