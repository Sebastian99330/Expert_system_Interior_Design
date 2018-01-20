//Uniwersytet Kardyna³a Stefana Wyszyñskiego
//Wydzia³ Matematyczno-Przyrodniczy
//Rok akademicki 2017/2018

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include "Funkcje_globalne.h"

using namespace std;

int main(){
	//ustawienie nazwy okna konsoli
	SetConsoleTitle(TEXT("Wybierz plytki"));
	Baza_cech cala_baza_cech(false);
	Baza_cech baza_cech_klienta;
	Baza_produktow baza_produktow;
	vector<Produkt> pasujace_produkty;


	//przedstawienie u¿ytkownikowi celu programu
	cout << "Witaj w systemie eksperckim dotyczacym Projektowania Wnetrz." << endl;
	cout << "Program przedstawia uzytkownikowi produkty, ktore spelniaja jego wymagania odnosnie wystroju wnetrz."<<endl;
	cout << "Produkty ktore dobiera ekspert to plytki (na podloge i sciane) oraz drzwi - do lazienek i kuchni."<<endl;
	cout << endl <<"Sposob dzialania programu: " << endl;
	cout << "Uzytkownik najpierw podaje taka ilosc parametrow jaka chce, po czym program zwraca wyniki." << endl;
	cout << "Im wiecej danych poda uzytkownik, tym bardziej precyzyjna oferta zostanie dobrana." << endl;

	cout << endl<<"Aby wprawdzic dane, wpisz wybrana cyfre i potem nacisnij enter." << endl;

	//pierwsze pytanie do u¿ytkownika. Cechê jakiego rodzaju chce podaæ (czy kolor, czy materia³ itd)
	int odpowiedz_kategoria = -1;
	odpowiedz_kategoria = wybierz_rodzaj_cechy(cala_baza_cech, baza_cech_klienta);
	odpowiedz_kategoria--; //bo u¿ytkownik liczy od 1, a komputer od 0
	
	bool nie_wprowadzono_danych=false;
	if (odpowiedz_kategoria == -1){
		nie_wprowadzono_danych = true;
	}

	//wczytywanie cech od u¿ytkownika
	while (odpowiedz_kategoria != -1){
		//drugie pytanie do u¿ytkownika - która cecha dok³adnie go interesuje
		int odpowiedz_cecha;
		odpowiedz_cecha = wybierz_ceche(odpowiedz_kategoria, cala_baza_cech, baza_cech_klienta);

		while (odpowiedz_cecha != -1){
			cout << endl << "Mozesz wybrac jeszcze jedna ceche z tej kategorii," << endl;
			cout << "lub wprowadzic 0 aby wrocic do menu wyboru kategorii." << endl;
			cout << "Nacisnij enter, aby kontynuowac...";
			getchar();
			odpowiedz_cecha = wybierz_ceche(odpowiedz_kategoria, cala_baza_cech, baza_cech_klienta);

		};
		if (odpowiedz_cecha == -1){
			cout << endl << "Zrezygnowales z podawania cechy z danej kategorii."<<endl;
			cout << "Wybierz inna kategorie, lub zakoncz wprowadzanie danych, jesli wolisz." << endl << endl;
		}

		cout << "Nacisnij enter, aby kontynuowac wybor...";
		getchar();
		odpowiedz_kategoria = wybierz_rodzaj_cechy(cala_baza_cech, baza_cech_klienta);
		odpowiedz_kategoria--;
	} ;

	
	if (nie_wprowadzono_danych == false){
	cout << endl << endl << "Dziekuje! Zakonczono wybor."<<endl<<endl;

	//wyœwietlenie u¿ytkownikowi cech, które wybra³
	cout << "Cechy, ktore wybrales: "<<endl;
	podsumuj_cechy(baza_cech_klienta);

	
		cout << endl << endl;
		cout << "Zostanie Ci teraz przedstawiona lista produktow, ktore spelniaja" << endl;
		cout << "twoje oczekiwania, wraz z linkami do strony internetowej z nimi." << endl;
	
		//wyœwietlenie produktów, które spe³niaj¹ warunki u¿ytkownika
		znajdz_produkty(baza_cech_klienta, baza_produktow, pasujace_produkty);
		otworz_przegladarke(baza_cech_klienta, baza_produktow, pasujace_produkty);
	}
	else{
		cout << endl<<endl<<"Nie wprowadziles zadnych danych!" << endl;
		cout << "System zatem nie moze wyswietlic zadnych produktow." << endl;
	}
	cout << endl << endl << "Koniec programu." << endl;
	cout << "Nacisnij enter, aby wylaczyc program." << endl;
	getchar();
	return 0;
}