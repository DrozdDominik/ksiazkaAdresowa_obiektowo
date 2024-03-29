#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "Adresat.h"

using namespace std;

class UzytkownikMenadzer {
int idZalogowanegoUzytkownika;
vector <Uzytkownik> uzytkownicy;
PlikZUzytkownikami plikZUzytkownikami;

Uzytkownik podajDaneNowegoUzytkownika();
int pobierzIdNowegoUzytkownika();
bool czyIstniejeLogin(string login);


public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    int pobierzIdZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
    void wypiszWszystkichUzytkownikow();
};

#endif
