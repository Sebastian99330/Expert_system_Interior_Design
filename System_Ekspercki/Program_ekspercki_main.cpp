#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Funkcje_globalne.h"

using namespace std;

int main(){
	Baza_cech cala_Baza_cech(false);
	Baza_cech baza_cech_klienta;
	Baza_produktow baza_produktow;



	//przedstawienie u¿ytkownikowi celu programu
	cout << "Witaj w systemie eksperckim dotyczacym Projektowania Wnetrz." << endl;
	cout << "Program podaje uzytkownikowi produkty, ktore spelniaja jego wymagania odnosnie wystroju wnetrz."<<endl;
	cout << "Produkty ktore dobiera ekspert to plytki (na podloge i sciane) oraz drzwi - do lazienek i kuchni."<<endl;
	cout << endl <<"Sposob dzialania programu: " << endl;
	cout << "Uzytkownik najpierw podaje taka ilosc parametrow jaka chce, po czym program zwraca wyniki." << endl;
	cout << "Im wiecej danych poda uzytkownik, tym bardziej precyzyjna oferta zostanie dobrana." << endl;

	cout << endl<<"Aby wprawdzic dane, wpisz wybrana cyfre i potem nacisnij enter." << endl;

	//pierwsze pytanie do u¿ytkownika. Cechê jakiego rodzaju chce podaæ (czy kolor, czy materia³ itd)
	int odpowiedz_kategoria = -1;
	odpowiedz_kategoria = wybierz_rodzaj_cechy(cala_Baza_cech, baza_cech_klienta);
	odpowiedz_kategoria--; //bo u¿ytkownik liczy od 1, a komputer od 0
	while (odpowiedz_kategoria != -1){
		//drugie pytanie do u¿ytkownika - która cecha dok³adnie go interesuje
		int odpowiedz_cecha;
		odpowiedz_cecha = wybierz_ceche(odpowiedz_kategoria, cala_Baza_cech, baza_cech_klienta);

		while (odpowiedz_cecha != -1){
			cout << endl << "Mozesz wybrac jeszcze jedna ceche z tej kategorii," << endl;
			cout << "lub wprowadzic 0 aby wrocic do menu wyboru kategorii." << endl;
			cout << "Nacisnij enter, aby kontynuowac...";
			getchar();
			odpowiedz_cecha = wybierz_ceche(odpowiedz_kategoria, cala_Baza_cech, baza_cech_klienta);

		};
		if (odpowiedz_cecha == -1){
			cout << endl << "Zrezygnowales z podawania cechy z danej kategorii."<<endl;
			cout << "Wybierz inna kategorie, lub zakoncz wprowadzanie danych, jesli wolisz." << endl << endl;
		}

		cout << "Nacisnij enter, aby kontynuowac wybor...";
		getchar();
		odpowiedz_kategoria = wybierz_rodzaj_cechy(cala_Baza_cech, baza_cech_klienta);
		odpowiedz_kategoria--;
	} ;

	

	cout << endl << endl << "Dziekuje! Zakonczono wybor."<<endl<<endl;
	cout << "Cechy, ktore wybrales: "<<endl;
	podsumuj_cechy(baza_cech_klienta);
	cout << endl << endl;
	cout << "Zostanie Ci teraz przedstawiona lista produktow, ktore spelniaja" << endl;
	cout << "twoje oczekiwania, wraz z linkami do strony internetowej z nimi." << endl;
	

	znajdz_produkty(baza_cech_klienta, baza_produktow);

	//ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOW);	//otworzenie przegladarki

	cout << endl << endl << "Koniec programu." << endl;
	cout << "Nacisnij enter, aby wylaczyc program." << endl;
	getchar();
	return 0;
}