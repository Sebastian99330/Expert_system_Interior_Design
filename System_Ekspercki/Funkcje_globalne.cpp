#ifndef Funkcje_globalne_cpp

#include <iostream>
#include <string>
#include <vector>
#include "Funkcje_globalne.h"

using namespace std;
//// cia³a funkcji



int zadaj_pytanie(){

	int odpowiedz;
	cout << endl << "Oto lista parametrow, ktore mozesz podac: " << endl;
	cout << "1 - kolor wystroju" << endl;
	cout << "2 - materialy plytek oraz drzwi" << endl;
	cout << "3 - Firma produkujaca produkty" << endl;
	cout << "4 - Cena produktu" << endl;
	cout << "5 - Kraj produkcji produktu" << endl;
	cout << "6 - Wielkosc plytki" << endl;
	cout << "Wpisz liczbe 0, aby zakonczyc wprowadzanie." << endl;
	cout << "Wprowadz cyfre (od 0 do 6) odpowiadajaca parametrowi, ktory chcesz podac: " << endl;
	odpowiedz=kontrola_poprawnosci_danych(0, 6);
	return odpowiedz;
};

void wybierz_ceche(int numer, Baza_danych cala_baza_danych, Baza_danych baza_danych_klienta){
	cout << endl << "Wszystkie mozliwosci do wyboru z danej cechy: " << endl;
	int ilosc_cech = cala_baza_danych[numer].size();	//czyli np ilosc kolorow, ilosc materialow itd.
	for (int i = 0; i < ilosc_cech; i++){
		cout << i+1 << ". " << cala_baza_danych[numer][i] << endl;
	}
	cout << endl << endl << "Ktora opcja spelnia Twoje wymagania?"<<endl;
	cout << "Wprowadz cyfre (od 0 do 6) odpowiadajaca opcji, ktora spelnia twoje wymagania: ";
	int odpowiedz;
	odpowiedz = kontrola_poprawnosci_danych(0, ilosc_cech);
	


}

#endif Funkcje_globalne_cpp