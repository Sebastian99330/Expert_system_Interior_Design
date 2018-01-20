#pragma once
#include <string>
#include <iostream>
using namespace std;

//Klasa pojedynczej cechy, czyli np. BIA£EGO koloru.
class Cecha
{
public:
	
	int id_cechy;	//id do latwiejszego przeszukiwania (po int'ach a nie po string'ach)
	int id_kategorii;	//czy kolor, czy material itd
	string cecha;	//jaki dok³adnie kolor, lub jaki dok³adnie materia³ itd
	Cecha(int id, int typ, string c);

	bool operator!=(Cecha &cc) {
		bool wynik; (id_cechy != cc.id_cechy) ? wynik = true : wynik = false; return wynik;
	}
	bool operator==(Cecha &cc) {
		bool wynik; (id_cechy == cc.id_cechy) ? wynik = true : wynik = false; return wynik;
	}

	bool operator!=(string str) {
		bool wynik; (cecha != str) ? wynik = true : wynik = false; return wynik;
	}
	bool operator==(string str) {
		bool wynik; (cecha == str) ? wynik = true : wynik = false; return wynik;
	}
};

