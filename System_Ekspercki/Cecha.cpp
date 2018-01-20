#include "Cecha.h"
#include <string>
#include <iostream>
using namespace std;

//konstruktor z argumentami. Po prostu inicjalizuje pola klasy.
Cecha::Cecha(int id_c, int id_kat, string c)
{
	id_cechy = id_c;
	id_kategorii = id_kat;
	cecha = c;

}