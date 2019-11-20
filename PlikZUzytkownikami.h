#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami{
string nazwaPlikuZUzytkownikami;
fstream plikTekstowy;

string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
bool czyPlikJestPusty();
Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    void wczytajUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy);

};

#endif
