#include <iostream>
#include <vector>
#include <string>
#include "Baza_danych.cpp"

using namespace std;

//deklaracje funkcji
int zadaj_pytanie();
bool kontrola_poprawnosci_danych();	//zwraca true jak wprowadzono poprawne dane, false jesli b³êdne
void przedstaw_mozliwosci (int);

int main(){
	Baza_danych cala_baza_danych;
	Baza_danych baza_danych_klienta;


	//krok 1 ze schematu blokowego - wyjasnij cel programu
	cout << "Witaj w systemie eksperckim dotyczacym Projektowania Wnetrz." << endl;
	cout << "Program podaje uzytkownikowi produkty, ktore spelniaja jego wymagania odnosnie wystroju wnetrz."<<endl;
	cout << "Produkty ktore dobiera ekspert to plytki (na podloge i sciane) oraz drzwi - do lazienek i kuchni."<<endl;
	cout << endl <<"Sposob dzialania programu: " << endl;
	cout << "Uzytkownik najpierw podaje taka ilosc parametrow jaka chce, po czym program zwraca wyniki." << endl;
	cout << "Im wiecej danych poda uzytkownik, tym bardziej precyzyjna oferta zostanie dobrana." << endl;

	//
	int odpowiedz = 0;
	do{
		odpowiedz = zadaj_pytanie();
	} while (odpowiedz != 0);

	cout << endl<<endl<< "Dziekuje! Wybrales 0. Pozdrawiam!";

	cout << endl << endl << "Koniec programu." << endl;
	return 0;
}


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
	cout << "Wpisz liczbe 0, aby zakonczyc wprowadzanie."<<endl;
	cout << "Wprowadz cyfre odpowiadajaca parametrowi, ktory chcesz podac: " << endl;
	while (!(cin >> odpowiedz) || getchar() != '\n'){
		cout << "Wprowadzono zle dane. Prosze wprowadzic cyfre jeszcze raz: ";
		cin.clear(); //czyœci flagê b³êdu
		cin.sync(); //czyœci bufor strumienia
	}
	return odpowiedz;
};

void przedstaw_mozliwosci(int numer){

}