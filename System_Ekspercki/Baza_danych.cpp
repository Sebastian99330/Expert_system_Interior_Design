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
	Baza_danych(){
	
		vector<string> kolor;
		this->push_back(kolor);
		kolor.push_back("niebieski");

		vector<string> materialy;
		this->push_back(materialy);
		kolor.push_back("drewno");

		vector<string> firma;
		this->push_back(firma);
		kolor.push_back("Tubadzin");

		vector<string> cena;
		this->push_back(cena);
		kolor.push_back("150zl/m^2");

		vector<string> kraj_produkcji;
		this->push_back(kraj_produkcji);
		kolor.push_back("niebieski");

		vector<string> wielkosc_plytki;
		this->push_back(kraj_produkcji);
		kolor.push_back("30x60cm");
	}

};
