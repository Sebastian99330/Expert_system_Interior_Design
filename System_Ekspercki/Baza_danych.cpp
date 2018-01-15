#include <iostream>
#include <vector>
using namespace std;


//Baza danych ma posta� dwuwymiarowego wektora.
//Czyli wektora g��wnego, kt�ry "trzyma ca�� baz� w ca�o�ci",
//oraz poszczeg�lnych wektor�w w nim, kt�re odpowiadaj� poszczeg�lnym cechom: kolorowi, materia�owi itd.
//te "poszczeg�lne" wektory, czyli te w �rodku, trzymaj� dane kt�re interesuj� u�ytkownika
//czyli odpowiednio: w wektorze kolor�w niebieski, ��ty itd; w drugim wektorze (materia��w): drewno, marmur itd.
class Baza_danych : public vector<vector<string>> {
public:

	//konstruktor z argumentem bool czy_uzytkownika. ten argument oznacza: 
	//czy ta baza danych jest u�ytkownika? Je�li tak, to stworzymy pust� baz� danych
	//i u�ytkownik sobie doda z listy wszystkich cech do bazy te cechy, kt�re go interesuj�.
	//Je�li nie, to znaczy �e tworzymy t� "og�ln�" baz� danych zawieraj�c� wszystkie produkty.
	Baza_danych(bool czy_uzytkownika=false){
		
		//tworzymy "pust�" baz� danych, tzn jeszcze j� nie wype�niamy �adnymi danymi
		vector<string> kolor;
		this->push_back(kolor);
	

		vector<string> materialy;
		this->push_back(materialy);
		

		vector<string> firma;
		this->push_back(firma);


		vector<string> cena;
		this->push_back(cena);

		vector<string> kraj_produkcji;
		this->push_back(kraj_produkcji);

		vector<string> wielkosc_plytki;
		this->push_back(kraj_produkcji);
		

		//je�li czy_uzytkownika = true, tzn. �e nie wype�niamy tej bazy �adnymi danymi.
		//u�ytkownik sam je potem wype�ni podczas dialogu z aplikacj�.
		//Je�li czy_uzytkownika = false, tzn �e jest to ta "g��wna", "systemowa"
		//baza danych i j� wype�niamy wszystkimi danymi w tym ifie.
		if (!czy_uzytkownika){
			kolor.push_back("blekitny");
			kolor.push_back("bialy");
			kolor.push_back("bezowy");	//be�owy
			kolor.push_back("ciemnoszary");
			kolor.push_back("szary");
			kolor.push_back("champagne");
			kolor.push_back("dymny");
			kolor.push_back("perlowy");

			materialy.push_back("drewno");
			materialy.push_back("marmur");
			materialy.push_back("kamien");
			materialy.push_back("tekstura");
			materialy.push_back("3d");
			materialy.push_back("monokolor");

			firma.push_back("Tubadzin");
			firma.push_back("Atlas concorde");
			firma.push_back("Villeroy & Boch");

			cena.push_back("40-90zl/m^2");
			cena.push_back("90-140zl/m^2");
			cena.push_back("140-250zl/m^2");


			kraj_produkcji.push_back("Polska");
			kraj_produkcji.push_back("W�ochy");
			kraj_produkcji.push_back("Niemcy");

			wielkosc_plytki.push_back("30x60cm");
			wielkosc_plytki.push_back("60x60cm");
			wielkosc_plytki.push_back("40x80cm");
		}
	}

};
