#ifndef Funkcje_globalne_cpp
#define Funkcje_globalne_cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //dla usuwania elementów z vectora
#include "Funkcje_globalne.h"

using namespace std;
//// cia³a funkcji



int wybierz_rodzaj_cechy(const Baza_cech cala_Baza_cech){

	int odpowiedz;
	cout << endl << "Oto lista kategorii cech, ktore mozesz podac: " << endl;
	cout << "1 - kolor wystroju" << endl;
	cout << "2 - materialy plytek oraz drzwi" << endl;
	cout << "3 - Firma produkujaca produkty" << endl;
	cout << "4 - Cena produktu" << endl;
	cout << "5 - Kraj produkcji produktu" << endl;
	cout << "6 - Wielkosc plytki" << endl;
	cout << "Wpisz liczbe 0, aby zakonczyc wprowadzanie." << endl;
	cout << "Wprowadz cyfre (od 0 do "<<cala_Baza_cech.size()<<") odpowiadajaca parametrowi, ktory chcesz podac: " << endl;
	odpowiedz=kontrola_poprawnosci_danych(0, 6);
	return odpowiedz;
};

int wybierz_ceche(int numer_kategorii, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta){

	//wypisanie wszystkich cech
	cout << endl << "Wszystkie mozliwosci do wyboru z danej cechy: " << endl;
	int ilosc_cech = cala_Baza_cech[numer_kategorii].size();	//czyli np ilosc kolorow, ilosc materialow itd.
	for (int i = 0; i < ilosc_cech; i++){
		cout << i + 1 << ". " << cala_Baza_cech[numer_kategorii][i];
		//jak cecha zosta³a ju¿ dodana, to o tym wspomnimy u¿ytkownikowi.
		bool czy_dodane;
		czy_dodane = czy_cecha_dodana(numer_kategorii, i, cala_Baza_cech, Baza_cech_klienta);
		if (czy_dodane == true){
			cout << " (juz dodane. Wybierz ponownie aby usunac) ";
		}
		cout<< endl;
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
	
	cout << endl << "Wybrales: " << cala_Baza_cech[numer_kategorii][odpowiedz] << endl;


	//teraz dodamy ta ceche do bazy tego klienta
	dodaj_ceche(numer_kategorii, odpowiedz, cala_Baza_cech, Baza_cech_klienta);

	return odpowiedz;
}

void dodaj_ceche(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta){

	//sprawdzimy, czy ta cecha jeszcze nie zostala wczesniej dodana
	//zmienna pomocnicza: czy klient ju¿ wczeœniej doda³ ow¹ cechê?
	bool czy_dodana = false;
	czy_dodana = czy_cecha_dodana(numer_kategorii, odpowiedz, cala_Baza_cech, Baza_cech_klienta);

	//jak cechy nie by³o, to j¹ dodajemy
	if (czy_dodana == false){
		//dodanie podanej przez u¿ytkownika cechy do jego bazy danych
		Baza_cech_klienta[numer_kategorii].push_back(cala_Baza_cech[numer_kategorii][odpowiedz]);
		cout << endl << "Dodano do cech uzytkownika." << endl;
	}
	else{
		usun_ceche(numer_kategorii, odpowiedz, cala_Baza_cech, Baza_cech_klienta);
		cout << endl << "Usunieto ceche. Jesli chcesz, mozesz dodac ja ponownie." << endl;
	}

	//wypisanie wszystkich dodanych cech z danej kategorii
	cout << endl <<"Do tej pory z tej kategorii dodales: "<< endl;
	int ilosc_cech = Baza_cech_klienta[numer_kategorii].size();
	for (int i = 0; i < ilosc_cech; i++){
		cout << Baza_cech_klienta[numer_kategorii][i];
		//nie chcemy wypisywaæ przecinka po ostatnim elemencie
		int indeks_ostatniego_elementu = Baza_cech_klienta[numer_kategorii].size() - 1;
		if (i != indeks_ostatniego_elementu){
			cout<< ", ";
		}
	}
	cout << endl;
}

bool czy_cecha_dodana(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta){
	
	//zmienna pomocnicza: czy klient ju¿ wczeœniej doda³ ow¹ cechê?
	//tak naprawdê zmienna zbêdna ale zostawiam dla przejrzystoœci kodu
	bool czy_dodana = false;

	//przeszukamy po ca³ym wektorze klienta w poszukiwaniu tej cechy, któr¹ chce on dodaæ do swoich upodobañ
	int ilosc_cech = Baza_cech_klienta[numer_kategorii].size();
	for (int i = 0; i < ilosc_cech; i++){
		//jeœli ten element w wektorze który na którym teraz aktualnie jesteœmy, 
		//jest identyczny jak ten który klient chce dodaæ, to znaczy ¿e by³ ju¿ wczeœniej dodany.
		if (cala_Baza_cech[numer_kategorii][odpowiedz] == Baza_cech_klienta[numer_kategorii][i]){
			czy_dodana = true;
			return true;
		}
	}
	return false;
}


void usun_ceche(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &Baza_cech_klienta){

	//usuwamy ceche z bazy danych u¿ytkownika

	string napis = cala_Baza_cech[numer_kategorii][odpowiedz];
	vector<string>::iterator iter1 = std::find(Baza_cech_klienta[numer_kategorii].begin(), Baza_cech_klienta[numer_kategorii].end(), napis);
	if (iter1 != Baza_cech_klienta[numer_kategorii].end())
	{
		Baza_cech_klienta[numer_kategorii].erase(iter1);
	}


	//vector<string>::iterator iter = find(Baza_cech_klienta.begin(), Baza_cech_klienta.end(), napis);
	//Baza_cech_klienta.erase(remove(Baza_cech_klienta.begin(), Baza_cech_klienta.end(), cala_Baza_cech[numer_kategorii][odpowiedz]), Baza_cech_klienta.end());


}

#endif Funkcje_globalne_cpp