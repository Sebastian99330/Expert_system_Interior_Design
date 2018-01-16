#ifndef Funkcje_globalne_cpp
#define Funkcje_globalne_cpp

#include <iostream>
#include <string>
#include <vector>
#include "Funkcje_globalne.h"

using namespace std;
//// cia³a funkcji



int wybierz_rodzaj_cechy(const Baza_danych cala_baza_danych){

	int odpowiedz;
	cout << endl << "Oto lista kategorii cech, ktore mozesz podac: " << endl;
	cout << "1 - kolor wystroju" << endl;
	cout << "2 - materialy plytek oraz drzwi" << endl;
	cout << "3 - Firma produkujaca produkty" << endl;
	cout << "4 - Cena produktu" << endl;
	cout << "5 - Kraj produkcji produktu" << endl;
	cout << "6 - Wielkosc plytki" << endl;
	cout << "Wpisz liczbe 0, aby zakonczyc wprowadzanie." << endl;
	cout << "Wprowadz cyfre (od 0 do "<<cala_baza_danych.size()<<") odpowiadajaca parametrowi, ktory chcesz podac: " << endl;
	odpowiedz=kontrola_poprawnosci_danych(0, 6);
	return odpowiedz;
};

int wybierz_ceche(int numer, const Baza_danych &cala_baza_danych, Baza_danych &baza_danych_klienta){

	//wypisanie wszystkich cech
	cout << endl << "Wszystkie mozliwosci do wyboru z danej cechy: " << endl;
	int ilosc_cech = cala_baza_danych[numer].size();	//czyli np ilosc kolorow, ilosc materialow itd.
	for (int i = 0; i < ilosc_cech; i++){
		cout << i+1 << ". " << cala_baza_danych[numer][i] << endl;
	}
	cout << endl << endl << "Ktora opcja spelnia Twoje wymagania?"<<endl;
	cout << "wprowadzenie cyfry 0 cofnie wykonywanie obecnej operacji" << endl;
	cout << "Wprowadz cyfre (od 0 do "<< ilosc_cech <<") odpowiadajaca opcji, ktora spelnia twoje wymagania: ";
	
	//wczytanie cechy od u¿ytkownika
	int odpowiedz;
	odpowiedz = kontrola_poprawnosci_danych(0, ilosc_cech);
	odpowiedz--; // bo u¿ytkownik-cz³owiek liczy od 1, a komputer od 0
	if (odpowiedz == -1){
		return odpowiedz;
	}
	
	cout << endl << "Wybrales: " << cala_baza_danych[numer][odpowiedz] << endl;


	//teraz dodamy ta ceche do bazy tego klienta
	dodaj_ceche(numer, odpowiedz, cala_baza_danych, baza_danych_klienta);

	return odpowiedz;
}

void dodaj_ceche(int numer, int odpowiedz, const Baza_danych &cala_baza_danych, Baza_danych &baza_danych_klienta){


	//sprawdzimy, czy ta cecha jeszcze nie zostala wczesniej dodana

	//zmienna pomocnicza: czy klient ju¿ wczeœniej doda³ ow¹ cechê?
	bool czy_cecha_dodana = false;

	//przeszukamy po ca³ym wektorze klienta w poszukiwaniu tej cechy, któr¹ chce on dodaæ do swoich upodobañ
	for (int i = 0; i < baza_danych_klienta[numer].size(); i++){
		//jeœli ten element w wektorze który na którym teraz aktualnie jesteœmy, 
		//jest identyczny jak ten który klient chce dodaæ, to znaczy ¿e by³ ju¿ wczeœniej dodany.
		if (cala_baza_danych[numer][odpowiedz] == baza_danych_klienta[numer][i]){
			czy_cecha_dodana = true;
			break;
		}
	}

	//jak cechy nie by³o, to j¹ dodajemy
	if (czy_cecha_dodana == false){
		//dodanie podanej przez u¿ytkownika cechy do jego bazy danych
		baza_danych_klienta[numer].push_back(cala_baza_danych[numer][odpowiedz]);
		cout << endl << "Dodano do cech uzytkownika." << endl;
	}
	else{
		cout << endl << "Wybrana cecha zostala juz wczesniej dodana!" << endl;
	}

}

#endif Funkcje_globalne_cpp