#include <iostream>
#include <vector>
#include <string>
#include "Funkcje_globalne.h"

using namespace std;

int main(){
	Baza_danych cala_baza_danych(false);
	Baza_danych baza_danych_klienta;


	//przedstawienie u¿ytkownikowi celu programu
	cout << "Witaj w systemie eksperckim dotyczacym Projektowania Wnetrz." << endl;
	cout << "Program podaje uzytkownikowi produkty, ktore spelniaja jego wymagania odnosnie wystroju wnetrz."<<endl;
	cout << "Produkty ktore dobiera ekspert to plytki (na podloge i sciane) oraz drzwi - do lazienek i kuchni."<<endl;
	cout << endl <<"Sposob dzialania programu: " << endl;
	cout << "Uzytkownik najpierw podaje taka ilosc parametrow jaka chce, po czym program zwraca wyniki." << endl;
	cout << "Im wiecej danych poda uzytkownik, tym bardziej precyzyjna oferta zostanie dobrana." << endl;

	//pierwsze pytanie do u¿ytkownika. Cechê jakiego rodzaju chce podaæ (czy kolor, czy materia³ itd)
	int odpowiedz_kategoria = -1;
	do{
		odpowiedz_kategoria = wybierz_rodzaj_cechy();
		odpowiedz_kategoria--; //bo u¿ytkownik liczy od 1, a komputer od 0
		if (odpowiedz_kategoria == -1)
			break;
		//drugie pytanie do u¿ytkownika - która cecha dok³adnie go interesuje
		int odpowiedz_cecha;
		do{
			odpowiedz_cecha = wybierz_ceche(odpowiedz_kategoria, cala_baza_danych, baza_danych_klienta);
		} while (odpowiedz_cecha != -1);
		if (odpowiedz_cecha == -1){
			cout << endl << "Zrezygnowales z podawania cechy z danej kategorii!"<<endl;
			cout << "Wybierz inna kategorie, lub zakoncz wprowadzanie danych, jesli wolisz." << endl;
		}
			
	} while (odpowiedz_kategoria != -1);

	cout << endl<<endl<< "Dziekuje! Wybrales 0. Pozdrawiam!";

	cout << endl << endl << "Koniec programu." << endl;
	return 0;
}

