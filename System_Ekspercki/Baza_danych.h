#ifndef Baza_danych_h

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
	Baza_danych(bool czy_uzytkownika = true);

};


#endif Baza_danych_h
