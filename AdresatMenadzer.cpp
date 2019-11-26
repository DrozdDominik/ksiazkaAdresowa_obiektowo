#include "AdresatMenadzer.h"


void AdresatMenadzer::ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata)
{
    idOstatniegoAdresata = noweIdOstatniegoAdresata;
}

int AdresatMenadzer::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

int AdresatMenadzer::dodajAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    return idOstatniegoAdresata;
}

Adresat AdresatMenadzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{

    Adresat adresat;
    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    string imie;
    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();
    imie = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imie);
    adresat.ustawImie(imie);

    string nazwisko;
    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();
    nazwisko = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwisko);
    adresat.ustawNazwisko(nazwisko);

    string numerTelefonu;
    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();
    numerTelefonu = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(numerTelefonu);
    adresat.ustawNumerTelefonu(numerTelefonu);

    string email;
    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();
    email = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(email);
    adresat.ustawEmail(email);

    string adres;
    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();
    adres = plikZAdresatami.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adres);
    adresat.ustawAdres(adres);

    return adresat;
}

int AdresatMenadzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(vector <Adresat> &adresaci, int idZalogowanegoUzytkownika)
{
  return plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);

}

 void AdresatMenadzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}
