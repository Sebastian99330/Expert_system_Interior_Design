#ifndef Funkcje_globalne_h

#include <iostream>
#include <string>
#include <vector>
#include "Baza_danych.h"

using namespace std;
//// cia�a funkcji


template <class typ>	//szablon funkcji s�u��cej do kontroli wczytywanych danych
typ kontrola_poprawnosci_danych(typ k, typ l){
	typ liczba;
	while (!(cin >> liczba) || liczba<k || liczba>l || getchar() != '\n'){
		cout << "Nie ma takiej mozliwosci! Odpowiedz na pytanie jeszcze raz ." << endl;
		cout << "Podaj cyfre od 0 do 6: ";
		cin.clear(); //czy�ci flag� b��du
		cin.sync(); //czy�ci bufor strumienia
	}
	return liczba;
}


int zadaj_pytanie();


void wybierz_ceche(int numer, Baza_danych cala_baza_danych, Baza_danych baza_danych_klienta);

#endif Funkcje_globalne_h