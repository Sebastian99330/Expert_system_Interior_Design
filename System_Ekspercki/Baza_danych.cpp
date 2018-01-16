#ifndef Baza_danych_cpp
#define Baza_danych_cpp

#include <iostream>
#include <vector>
#include "Baza_danych.h"
using namespace std;


//Baza danych ma posta� dwuwymiarowego wektora.
//Czyli wektora g��wnego, kt�ry "trzyma ca�� baz� w ca�o�ci",
//oraz poszczeg�lnych wektor�w w nim, kt�re odpowiadaj� poszczeg�lnym cechom: kolorowi, materia�owi itd.
//te "poszczeg�lne" wektory, czyli te w �rodku, trzymaj� dane kt�re interesuj� u�ytkownika
//czyli odpowiednio: w wektorze kolor�w niebieski, ��ty itd; w drugim wektorze (materia��w): drewno, marmur itd.
Baza_danych::Baza_danych(bool czy_uzytkownika){

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
		(*this)[0].push_back("blekitny");
		(*this)[0].push_back("bialy");
		(*this)[0].push_back("bezowy");	//be�owy
		(*this)[0].push_back("ciemnoszary");
		(*this)[0].push_back("szary");
		(*this)[0].push_back("champagne");
		(*this)[0].push_back("dymny");
		(*this)[0].push_back("perlowy");

		(*this)[1].push_back("drewno");
		(*this)[1].push_back("marmur");
		(*this)[1].push_back("kamien");
		(*this)[1].push_back("tekstura");
		(*this)[1].push_back("3d");
		(*this)[1].push_back("monokolor");

		(*this)[2].push_back("Tubadzin");
		(*this)[2].push_back("Atlas concorde");
		(*this)[2].push_back("Villeroy & Boch");

		(*this)[3].push_back("40-90zl/m^2");
		(*this)[3].push_back("90-140zl/m^2");
		(*this)[3].push_back("140-250zl/m^2");


		(*this)[4].push_back("Polska");
		(*this)[4].push_back("Wlochy");
		(*this)[4].push_back("Niemcy");

		(*this)[5].push_back("30x60cm");
		(*this)[5].push_back("60x60cm");
		(*this)[5].push_back("40x80cm");
	}
};


#endif Baza_danych_cpp
