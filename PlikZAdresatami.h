#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string nazwaTymczasowegoPlikuZAdresatami;
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    bool czyPlikJestPusty(fstream &plikTekstowy);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    void edytujAdresataWPliku(Adresat adresat, string liniaZDanymiAdresataOddzielonePionowymiKreskami);

    public:
    PlikZAdresatami(string nazwaPlikuZAdresatami)
    : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), nazwaTymczasowegoPlikuZAdresatami("Adresaci_tymczasowo.txt")
    {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void ustawIdOstatniegoAdresata(int noweIdOstatniegoUzytkownika);
    void usunWybranegoAdresataZPliku(int idUsunietegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);

};



#endif
