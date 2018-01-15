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
