#include <iostream>
#include <vector>
using namespace std;


//Baza danych ma postaæ dwuwymiarowego wektora.
//Czyli wektora g³ównego, który "trzyma ca³¹ bazê w ca³oœci",
//oraz poszczególnych wektorów w nim, które odpowiadaj¹ poszczególnym cechom: kolorowi, materia³owi itd.
//te "poszczególne" wektory, czyli te w œrodku, trzymaj¹ dane które interesuj¹ u¿ytkownika
//czyli odpowiednio: w wektorze kolorów niebieski, ¿ó³ty itd; w drugim wektorze (materia³ów): drewno, marmur itd.
class Baza_danych : public vector<vector<string>> {
public:

	//konstruktor z argumentem bool czy_uzytkownika. ten argument oznacza: 
	//czy ta baza danych jest u¿ytkownika? Jeœli tak, to stworzymy pust¹ bazê danych
	//i u¿ytkownik sobie doda z listy wszystkich cech do bazy te cechy, które go interesuj¹.
	//Jeœli nie, to znaczy ¿e tworzymy tê "ogóln¹" bazê danych zawieraj¹c¹ wszystkie produkty.
	Baza_danych(bool czy_uzytkownika=false){
		
		//tworzymy "pust¹" bazê danych, tzn jeszcze j¹ nie wype³niamy ¿adnymi danymi
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
		

		//jeœli czy_uzytkownika = true, tzn. ¿e nie wype³niamy tej bazy ¿adnymi danymi.
		//u¿ytkownik sam je potem wype³ni podczas dialogu z aplikacj¹.
		//Jeœli czy_uzytkownika = false, tzn ¿e jest to ta "g³ówna", "systemowa"
		//baza danych i j¹ wype³niamy wszystkimi danymi w tym ifie.
		if (!czy_uzytkownika){
			kolor.push_back("blekitny");
			kolor.push_back("bialy");
			kolor.push_back("bezowy");	//be¿owy
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
			kraj_produkcji.push_back("W³ochy");
			kraj_produkcji.push_back("Niemcy");

			wielkosc_plytki.push_back("30x60cm");
			wielkosc_plytki.push_back("60x60cm");
			wielkosc_plytki.push_back("40x80cm");
		}
	}

};
