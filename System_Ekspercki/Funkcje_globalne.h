#ifndef Funkcje_globalne_h
#define Funkcje_globalne_h

#include <iostream>
#include <string>
#include <vector>
#include "Baza_cech.h"

using namespace std;
//// cia³a funkcji


template <class typ>	//szablon funkcji s³u¿¹cej do kontroli wczytywanych danych
typ kontrola_poprawnosci_danych(typ k, typ l){
	typ liczba;
	while (!(cin >> liczba) || liczba<k || liczba>l || getchar() != '\n'){
		cout << "Nie ma takiej mozliwosci! Odpowiedz na pytanie jeszcze raz ." << endl;
		cout << "Podaj cyfre od 0 do 6: ";
		cin.clear(); //czyœci flagê b³êdu
		cin.sync(); //czyœci bufor strumienia
	}
	return liczba;
}


int wybierz_rodzaj_cechy(const Baza_cech cala_Baza_cech);


int wybierz_ceche(int numer, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta);

void dodaj_ceche(int numer, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta);

bool czy_cecha_dodana(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta);

void usun_ceche(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta);


#endif Funkcje_globalne_h