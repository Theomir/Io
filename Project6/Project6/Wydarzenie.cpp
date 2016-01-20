#include "Wydarzenie.h"
Wydarzenie::Wydarzenie(string t) : typ(t)
{
}
void Wydarzenie::wyswietl(int n_wydarzenie) const
{
	cout << "| +-- [nr. " << n_wydarzenie << "] -- " << typ << " --------------\n| |\n";
}
void Wydarzenie::input()
{
	cout << "|\n| -- DODAWANIE " << typ << " --\n";
}
void Wydarzenie::wyznacz_i_pokaz_trase(string trasa) {

}
Spotkanie::Spotkanie() : Wydarzenie("Spotkanie")
{
}
Spotkanie::Spotkanie(string nazwa, string l, string np, string n) : Wydarzenie("Spotkanie"), nazwa(nazwa), miejsce(l),
nazwisko_osoby(np), notatki(n)
{
}
void Spotkanie::wyswietl(int n_wydarzenie) const
{
	Wydarzenie::wyswietl(n_wydarzenie);
	cout << "| | " << nazwa << endl;
	cout << "| | miejsce:" << miejsce << endl;
	cout << "| | z:" << nazwisko_osoby << endl;
	cout << "| | " << notatki << "\n| +-------------------------------------------\n|\n";
}
string Spotkanie::to_csv(terminy data) const
{
	return string("1;" + data.to_csv() + ";" + nazwa + ";" + miejsce + ";" + nazwisko_osoby + ";" + notatki);
}
void Spotkanie::input()
{
	Wydarzenie::input();
	wprowadzanie_i_kontrola("| [1/4] nazwa: ", nazwa);
	wprowadzanie_i_kontrola("| [2/4] miejsce:", miejsce);
	wprowadzanie_i_kontrola("| [3/4] Z kim: ", nazwisko_osoby);
	wprowadzanie_i_kontrola("| [4/4] Notatka:", notatki);
	cout << "|\t[zakonczono]\n";
}
termin::termin(string nazwa, int piorytet, string n) : Wydarzenie("TERMIN"), nazwa(nazwa), piorytet(piorytet), notatki(n)
{
}
void termin::wyswietl(int n_wydarzenie) const
{
	Wydarzenie::wyswietl(n_wydarzenie);
	cout << "| | " << nazwa << " (" << gwiazdki[piorytet] << ")\n";
	cout << "| | " << notatki << "\n| +-------------------------------------------\n|\n";
}
string termin::to_csv(terminy data) const
{
	return string("2;" + data.to_csv() + ";" + nazwa + ";" + int_to_string(piorytet) + ";" + notatki);
}
void termin::input()
{
	Wydarzenie::input();
	wprowadzanie_i_kontrola("| [1/3] Nazwa: ", nazwa);
	piorytet = int_input("| [2/3] Piorytet [1-5]:", 1, 5);
	wprowadzanie_i_kontrola("| [3/3] Notatka:", notatki);
	cout << "|\t[zakonczono]\n";
}
notatki::notatki(string t) : Wydarzenie("Notatki"), tekst(t)
{
}
void notatki::wyswietl(int n_wydarzenie) const
{
	Wydarzenie::wyswietl(n_wydarzenie);
	cout << "| | " << tekst << "\n| +-------------------------------------------\n";
}
string notatki::to_csv(terminy data) const
{
	return string("3;" + data.to_csv() + ";" + tekst);
}
void notatki::input()
{
	Wydarzenie::input();
	wprowadzanie_i_kontrola("| [1/1] Tekst: ", tekst);
	cout << "|\t[Zakonczono]\n";
}