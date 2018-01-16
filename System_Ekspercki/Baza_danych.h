#ifndef Baza_danych_h

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
	Baza_danych(bool czy_uzytkownika = true);

};


#endif Baza_danych_h
