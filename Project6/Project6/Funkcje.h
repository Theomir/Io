#ifndef FUNKCJE_H
#define FUNKCJE_H
#include "terminy.h"
#include <cstdlib> 
#include <ctime>
#include <iostream>
const string ogranicznik = "+===========================================\n";
void czyszczenie_ekranu(); //funkcja czyszczaca ekran
void pauza();
int int_input(string tekst, int min, int max = -1); //wprowadzanie danych liczbowych
string string_input(); //wprowadzanie danych tekstowych
void wypisz_naglowek(string tytu³ = "KALENDARZ"); //wypisywanie naglowka
void blad_wydruku(string error); //wyswietl blad
void wprowadzanie_i_kontrola(string pole, string & wartosc); //sprawdzanie poprawnosci danych
bool potwierdzenie(string tekst); //potwierdzenie operacji
void pokaz_menu(int wydarzenia_dzis, int wydarzenia_jutro); //wyswietlanie menu
string int_to_string(const int n);
#endif