#include "Kontakt.h"
#include "Funkcje.h"
#include <iostream>
#include <string>
using namespace std;
Kontakt::Kontakt(string n, string c, string m, string ic, string tc, string iu, string tu, string tcel, string no) : imie(n), nazwisko(c), mail(m), adres_dom(ic), telefon_dom(tc),
adres_biuro(iu), telefon_biuro(tu), telefon_kom(tcel), notatki(no)
{
}
void Kontakt::input()										// wprowadzenie danych do kontaktu
{
	cout << ogranicznik;
	cout << "| --- DODAWANIE KONTAKTU --- \n";
	cout << "| \"nd\" zadne pole nie moze zostac puste\n";
	cout << "|\n";
	wprowadzanie_i_kontrola("| Imie: ", imie);
	wprowadzanie_i_kontrola("| Nazwisko: ", nazwisko);
	wprowadzanie_i_kontrola("| E-mail: ", mail);
	wprowadzanie_i_kontrola("| Adres (dom): ", adres_dom);
	wprowadzanie_i_kontrola("| Telefon (dom): ", telefon_dom);
	wprowadzanie_i_kontrola("| Adres (praca): ", adres_biuro);
	wprowadzanie_i_kontrola("| Telefon (praca): ", telefon_biuro);
	wprowadzanie_i_kontrola("| Telefon komorkowy: ", telefon_kom);
	wprowadzanie_i_kontrola("| Dodatkowe uwagi: ", notatki);
	cout << "| [ KONTAKT POPRAWNIE DODANY ]\n";
	cout << "|\n";
	cout << ogranicznik;
	pauza();
}
bool Kontakt::operator == (const Kontakt & n) const
{
	return (imie == n.imie && nazwisko == n.nazwisko && mail == n.mail && adres_dom == n.adres_dom && telefon_dom == n.telefon_dom && adres_biuro == n.adres_biuro && telefon_biuro == n.telefon_biuro && telefon_kom == n.telefon_kom && notatki == n.notatki);
}
bool Kontakt::operator < (const Kontakt & n) const
{
	return ((nazwisko != n.nazwisko) ? (nazwisko <= n.nazwisko) : (imie <= n.imie));
}
void Kontakt::WyswietlKontakt(int n_id) const
{
	cout << "+- - - - - - - - - - - - - - - - - - -\n";
	cout << "| [ KONTAKT ID " << n_id << " ]\n";
	cout << "| " << nazwisko << " " << imie << " < " << mail << " >\n";
	cout << "| DOM: " << adres_dom << " - Tel. " << telefon_dom << ".\n";
	cout << "| PRACA: " << adres_dom << " - Tel. " << telefon_dom << ".\n";
	cout << "| KOMORKOWY: " << telefon_kom << "\n";
	cout << "| NOTATKI: " << notatki << "\n";
}
string Kontakt::stworzWierszCSV() const  //dodanie nowej linii do pliku
{
	string temp = imie + ";" + nazwisko + ";" + mail + ";" + adres_dom + ";" + telefon_dom + ";" + adres_biuro + ";" + telefon_biuro + ";" + telefon_kom + ";" + notatki;
	return temp;
}