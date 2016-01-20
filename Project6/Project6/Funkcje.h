#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "terminy.h"
#include <cstdlib> 
#include <ctime>
#include <iostream>
const string ogranicznik = "+===========================================\n";
void czyszczenie_ekranu();
void pauza();
int int_input(string tekst, int min, int max = -1);
string string_input();
void wypisz_naglowek(string tytu³ = "KALENDARZ");
void blad_wydruku(string error);
void wprowadzanie_i_kontrola(string pole, string & wartosc);
bool potwierdzenie(string tekst);
void pokaz_menu(int wydarzenia_dzis, int wydarzenia_jutro);
string int_to_string(const int n);
#endif