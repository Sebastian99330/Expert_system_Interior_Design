#include <iostream>
#include <vector>
#include <string>
#include "Funkcje_globalne.h"

using namespace std;

int main(){
	Baza_danych cala_baza_danych(false);
	Baza_danych baza_danych_klienta;


	//krok 1 ze schematu blokowego - wyjasnij cel programu
	cout << "Witaj w systemie eksperckim dotyczacym Projektowania Wnetrz." << endl;
	cout << "Program podaje uzytkownikowi produkty, ktore spelniaja jego wymagania odnosnie wystroju wnetrz."<<endl;
	cout << "Produkty ktore dobiera ekspert to plytki (na podloge i sciane) oraz drzwi - do lazienek i kuchni."<<endl;
	cout << endl <<"Sposob dzialania programu: " << endl;
	cout << "Uzytkownik najpierw podaje taka ilosc parametrow jaka chce, po czym program zwraca wyniki." << endl;
	cout << "Im wiecej danych poda uzytkownik, tym bardziej precyzyjna oferta zostanie dobrana." << endl;

	//
	int odpowiedz = -1;
	do{
		odpowiedz = zadaj_pytanie();
		odpowiedz--; //bo u¿ytkownik liczy od 1, a komputer od 0
		if (odpowiedz == -1)
			break;
		wybierz_ceche(odpowiedz, cala_baza_danych, baza_danych_klienta);

	} while (odpowiedz != -1);

	cout << endl<<endl<< "Dziekuje! Wybrales 0. Pozdrawiam!";

	cout << endl << endl << "Koniec programu." << endl;
	return 0;
}

