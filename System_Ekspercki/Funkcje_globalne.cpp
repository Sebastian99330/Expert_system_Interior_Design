#ifndef Funkcje_globalne_cpp
#define Funkcje_globalne_cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //dla usuwania element�w z vectora
#include <windows.h> //do otworzenia przegl�darki, ShellExecute
#include "Funkcje_globalne.h"

using namespace std;



int wybierz_rodzaj_cechy(const Baza_cech cala_Baza_cech, const Baza_cech &baza_cech_klienta){

	int odpowiedz;
	cout << endl << "Oto lista kategorii cech, ktore mozesz podac: " << endl;
	cout << "1 - kolor wystroju"<<"\t\t\t("; wypisz_wybrane_cechy(0, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "2 - tekstura plytek" << "\t\t\t("; wypisz_wybrane_cechy(1, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "3 - Firma produkujaca produkty" << "\t\t("; wypisz_wybrane_cechy(2, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "4 - Cena produktu" << "\t\t\t("; wypisz_wybrane_cechy(3, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "5 - Kraj produkcji" << "\t\t\t("; wypisz_wybrane_cechy(4, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "6 - Wielkosc plytki" << "\t\t\t("; wypisz_wybrane_cechy(5, cala_Baza_cech, baza_cech_klienta);
	cout << ")" << endl;
	cout << "Wpisz liczbe 0, aby zakonczyc wprowadzanie." << endl;
	cout << "Wprowadz cyfre (od 0 do "<<cala_Baza_cech.size()<<") odpowiadajaca parametrowi, ktory chcesz podac: ";
	odpowiedz=kontrola_poprawnosci_danych(0, 6);
	return odpowiedz;
};

void wypisz_wybrane_cechy(int nr_kategorii, const Baza_cech &cala_Baza_cech, const Baza_cech &baza_cech_klienta){
	int ilosc_cech = baza_cech_klienta[nr_kategorii].size();
	if (ilosc_cech==0){
		cout << "Jeszcze nic nie wybrano z tej kategorii";
		return;
	}
	for (int i = 0; i < ilosc_cech; i++){
		if (i == 0){
			cout << "Wybrano: ";
		}
		cout << baza_cech_klienta[nr_kategorii][i].cecha;
		//nie chcemy wypisywa� przecinka po ostatnim elemencie
		int indeks_ostatniego_elementu = baza_cech_klienta[nr_kategorii].size() - 1;
		if (i != indeks_ostatniego_elementu){
			cout << ", ";
		}
	}

}

int wybierz_ceche(int numer_kategorii, const Baza_cech &cala_Baza_cech, Baza_cech &baza_cech_klienta){

	//wypisanie wszystkich cech
	cout << endl << "Wszystkie mozliwosci do wyboru z danej cechy: " << endl;
	int ilosc_cech = cala_Baza_cech[numer_kategorii].size();	//czyli np ilosc kolorow, ilosc tekstur itd.
	for (int i = 0; i < ilosc_cech; i++){
		cout << i + 1 << ". " << cala_Baza_cech[numer_kategorii][i].cecha;
		//jak cecha zosta�a ju� dodana, to o tym wspomnimy u�ytkownikowi.
		bool czy_dodane;
		czy_dodane = czy_cecha_dodana(numer_kategorii, i, cala_Baza_cech, baza_cech_klienta);
		if (czy_dodane == true){
			cout << " (juz dodane. Wybierz ponownie aby usunac) ";
		}
		cout<< endl;
	}
	cout << endl << endl << "Ktora opcja spelnia Twoje wymagania?"<<endl;
	cout << "wprowadzenie cyfry 0 cofnie wykonywanie obecnej operacji" << endl;
	cout << "Wprowadz cyfre (od 0 do "<< ilosc_cech <<") odpowiadajaca opcji, ktora spelnia twoje wymagania: ";
	
	//wczytanie cechy od u�ytkownika
	int odpowiedz;
	odpowiedz = kontrola_poprawnosci_danych(0, ilosc_cech);
	odpowiedz--; // bo u�ytkownik-cz�owiek liczy od 1, a komputer od 0
	if (odpowiedz == -1){
		return odpowiedz;
	}
	
	cout << endl << "Wybrales: " << cala_Baza_cech[numer_kategorii][odpowiedz].cecha << endl;


	//teraz dodamy ta ceche do bazy tego klienta
	dodaj_ceche(numer_kategorii, odpowiedz, cala_Baza_cech, baza_cech_klienta);

	return odpowiedz;
}

void dodaj_ceche(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &baza_cech_klienta){

	//sprawdzimy, czy ta cecha jeszcze nie zostala wczesniej dodana
	//zmienna pomocnicza: czy klient ju� wcze�niej doda� ow� cech�?
	bool czy_dodana = false;
	czy_dodana = czy_cecha_dodana(numer_kategorii, odpowiedz, cala_Baza_cech, baza_cech_klienta);

	//jak cechy nie by�o, to j� dodajemy
	if (czy_dodana == false){
		//dodanie podanej przez u�ytkownika cechy do jego bazy danych
		baza_cech_klienta[numer_kategorii].push_back(cala_Baza_cech[numer_kategorii][odpowiedz]);
		cout << endl << "Dodano do cech uzytkownika." << endl;
	}
	else{
		usun_ceche(numer_kategorii, odpowiedz, cala_Baza_cech, baza_cech_klienta);
		cout << endl << "Usunieto ceche. Jesli chcesz, mozesz dodac ja ponownie." << endl;
	}

	//wypisanie wszystkich dodanych cech z danej kategorii
	cout << endl <<"Do tej pory z tej kategorii dodales: "<< endl;
	wypisz_wybrane_cechy(numer_kategorii, cala_Baza_cech, baza_cech_klienta);
	cout << endl;
}

bool czy_cecha_dodana(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &baza_cech_klienta){
	
	//zmienna pomocnicza: czy klient ju� wcze�niej doda� ow� cech�?
	//tak naprawd� zmienna zb�dna ale zostawiam dla przejrzysto�ci kodu
	bool czy_dodana = false;

	//przeszukamy po ca�ym pasujace_produktyze klienta w poszukiwaniu tej cechy, kt�r� chce on doda� do swoich upodoba�
	int ilosc_cech = baza_cech_klienta[numer_kategorii].size();
	for (int i = 0; i < ilosc_cech; i++){
		//je�li ten element w pasujace_produktyze kt�ry na kt�rym teraz aktualnie jeste�my, 
		//jest identyczny jak ten kt�ry klient chce doda�, to znaczy �e by� ju� wcze�niej dodany.
		if (cala_Baza_cech[numer_kategorii][odpowiedz].id_cechy == baza_cech_klienta[numer_kategorii][i].id_cechy){
			czy_dodana = true;
			return true;
		}
	}
	return false;
}


void usun_ceche(int numer_kategorii, int odpowiedz, const Baza_cech &cala_Baza_cech, Baza_cech &baza_cech_klienta){

	//usuwamy ceche z bazy danych u�ytkownika

	string napis = cala_Baza_cech[numer_kategorii][odpowiedz].cecha;
	
	vector<Cecha>::iterator iter1 = baza_cech_klienta[numer_kategorii].begin();
	
	iter1 = std::find(baza_cech_klienta[numer_kategorii].begin(), baza_cech_klienta[numer_kategorii].end(), napis);
	if (iter1 != baza_cech_klienta[numer_kategorii].end())
	{
		baza_cech_klienta[numer_kategorii].erase(iter1);
	}
	


	//vector<string>::iterator iter = find(baza_cech_klienta.begin(), baza_cech_klienta.end(), napis);
	//baza_cech_klienta.erase(remove(baza_cech_klienta.begin(), baza_cech_klienta.end(), cala_Baza_cech[numer_kategorii][odpowiedz]), baza_cech_klienta.end());


}


void podsumuj_cechy(Baza_cech &baza_cech_klienta){
	
	//lecimy po ca�ej bazie danych
	int ilosc_kategorii = baza_cech_klienta.size();
	for (int i = 0; i < ilosc_kategorii; i++){
		int ilosc_cech = baza_cech_klienta[i].size();
		if (ilosc_cech == 0){
			continue;
		}
		for (int j = 0; j < ilosc_cech; j++){
			
			if (j == 0){
				switch (i)
				{
				case 0: cout << "Kolor: "; break;
				case 1: cout << "Tekstura: "; break;
				case 2: cout << "Firma: "; break;
				case 3: cout << "Cena: "; break;
				case 4: cout << "Kraj pochodzenia: "; break;
				case 5: cout << "Wiekosc plytki: "; break;
				default:
					break;
				}
			}
			cout << baza_cech_klienta[i][j].cecha;
			//nie chcemy wypisywa� przecinka po ostatnim elemencie
			int indeks_ostatniego_elementu = baza_cech_klienta[i].size() - 1;
			if (j != indeks_ostatniego_elementu){
				cout << ", ";
			}
			
		}
		cout << endl;
	}

}

void znajdz_produkty(Baza_cech &baza_cech_klienta, const Baza_produktow &baza_produktow, vector<Produkt> &pasujace_produkty){

	cout << endl;

	//inicjalizacja podstawowych, pomocniczych zmiennych
	int ilosc_produktow = baza_produktow.size();
	int licznik = 1;
	int ilosc_kategorii = baza_cech_klienta.size();

	//Zaczynamy chodzi� po wszystkich cechach, kt�re u�ytkownik sobie wybra�
	//�eby znale�� produkty pasuj�ce do nich.
	//Baza cech to wektor, kt�ry zawiera wektory.
	//Wewn�trzne wektory to wektory zawieraj�ce konkretne cechy (jak: zielony kolor, drewniane p�ytki).
	//Zewn�trzny wektor to wektor, kt�ry zawiera te mniejsze wektory cech, pogrupowane kategoriami.

	//pierwszy for to przej�cie ca�ego "g��wnego" wektora bazy cech klienta
	for (int i = 0; i < ilosc_kategorii; i++){
		int ilosc_cech = baza_cech_klienta[i].size();
		//je�li klient sobie nie upodoba� �adnej cechy z danej kategorii, to jej nie przechodzimy
		if (ilosc_cech == 0){
			continue;
		}
		//drugi for to przej�cie ca�ego WEWN�TRZNEGO wektora cech (zawieraj�cego konkretne cechy)
		for (int j = 0; j < ilosc_cech; j++){

			//trzeci for, dla por�wnania ka�dej cechy (z bazy danych klienta kt�r� obchodzimy)
			//z list� wszystkich produkt�w kt�re mamy (i zapisujemy te, kt�re pasuj�)
			//czyli trzeci for obchodzi wszystkie produkty
			for (int k = 0; k < ilosc_produktow; k++){
				
				int id_cechy2 = baza_cech_klienta[i][j].id_cechy;

				//Por�wnamy produkt, na kt�rym teraz jeste�my 
				//podczas przeszukiwania bazy danych produkt�w -
				//z cech�, na kt�rej teraz jeste�my podczas przeszukiwania bazy cech.

				//zmienna pomocnicza dla uproszczenia kodu
				bool czy_produkt_pasuje = false;

				//U�ywamy takiego wielokrotnego if'a, bo musimy -
				//badaj�c te przedzia�y (0-7 itd), badamy z kt�r� cech� mamy por�wnywa� produkt.
				//Baza cech jest tak zbudowana, �e kolejne cechy maj� kolejne liczby id - bez wzgl�du na kategori�.
				//Czyli nie jest tak, �e dla kolor�w id rosn� kolejno od 0,
				//i potem dla materia��w znowu od 0.
				//Tylko dla materia��w id_cech lec� dalej, np od 8 itd.
				//Dlatego musimy zbada� przedzia�y, kt�rych zakresy znamy z tego jak wype�nili�my Baza_cech.
				//Potem jak wiemy w jakiej kategorii cech jeste�my, mo�emy por�wnywa� odpowiednie id z produktu
				//np id_koloru albo id_materialu.
				if (id_cechy2>0 && id_cechy2 <= 7){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_koloru);
				}
				else if (id_cechy2>=8 && id_cechy2 <= 13){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_materialu);
				}
				else if (id_cechy2 >= 14 && id_cechy2 <= 16){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_firmy);
				}
				else if (id_cechy2 >= 17 && id_cechy2 <= 19){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_ceny);
				}
				else if (id_cechy2 >= 20 && id_cechy2 <= 22){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_kraju_produkcji);
				}
				else if (id_cechy2 >= 23 && id_cechy2 <= 27){
					czy_produkt_pasuje = (baza_cech_klienta[i][j].id_cechy == baza_produktow[k].id_wielkosc_plytki);
				}

				//je�li produkt pasuje do cechy... 
				if (czy_produkt_pasuje==true){
					//to wypisujemy nazw� produktu i link url
					cout << licznik++ << ". " << baza_produktow[k].nazwa_produktu << endl;
					cout<< "Link do przegladarki internetowej: "<< baza_produktow[k].link_url << endl;
					//dodajemy ten produkt do wektora produkt�w, kt�re pasuj� klientowi
					pasujace_produkty.push_back(baza_produktow[k]);

				}
			}
		}
	}
}

void otworz_przegladarke(Baza_cech &baza_cech_klienta, const Baza_produktow &baza_produktow, vector<Produkt> &pasujace_produkty){


	cout << endl << endl;
	cout << "Mozesz teraz otworzyc ktorys produkt w przegladarce internetowej." << endl;
	int odpowiedz;
	do{
		cout << endl << "Wpisz 0 jesli nie chcesz otwierac przegladarki i chcesz zakonczyc prace programu," << endl;
		cout << "Lub podaj cyfre produktu ktory chcialbys zobaczyc: ";
		int ilosc_pasujacych_produktow = pasujace_produkty.size();
		odpowiedz = kontrola_poprawnosci_danych(0, ilosc_pasujacych_produktow);
		odpowiedz--; //bo czlowiek liczy od 1 a komputer od 0
		if (odpowiedz == -1){
			continue;
		}

		//konwersja stringu - napisu url, do formatu potrzebnego do otworzenia przegladarki
		wstring stemp = wstring(pasujace_produkty[odpowiedz].link_url.begin(), pasujace_produkty[odpowiedz].link_url.end());
		LPCWSTR otwieracz = stemp.c_str();
		ShellExecute(0, 0, otwieracz, 0, 0, SW_SHOW);	//otworzenie przegladarki
	} while (odpowiedz != -1);
}



#endif Funkcje_globalne_cpp