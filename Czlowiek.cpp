#include "Czlowiek.h"

Czlowiek::Czlowiek(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek)
	: Zwierze(obecnySwiat, 5, 4, pozycjaX, pozycjaY, wiek, false) {
}

void Czlowiek::rysowanie() {
	cout << "C";
}

string Czlowiek::getNazwa() {
	return ("Czlowiek");
}

void Czlowiek::akcja() {
    wiek++;
    if (sila > 5)
        sila--;
    int ruchGracza;

    int nowaPozycja[2];
    nowaPozycja[0] = pozycja[0];
    nowaPozycja[1] = pozycja[1];

    cout << "Porusz sie zgodnie ze sterowaniem: ";
    if (obecnySwiat->getTura() == 1) {
        ruchGracza = getchar();
    }
    if (obecnySwiat->getNowoWczytany() == true) {
        ruchGracza = getchar();
    }
    ruchGracza = getchar();

    if (ruchGracza == 97) {
        nowaPozycja[0]--;
    }
    else if (ruchGracza == 100) {
        nowaPozycja[0]++;
    }
    else if (ruchGracza == 119) {
        nowaPozycja[1]--;
    }
    else if (ruchGracza == 115) {
        nowaPozycja[1]++;
    }
    else if (ruchGracza == 114) {
        specjalnaUmiejetnosc();
    }
    else if (ruchGracza == 113) {
        string sciezka;
        cout << "\nPodaj nazwe pliku do wczytania : ";
        cin >> sciezka;
        sciezka = sciezka + ".txt";
        obecnySwiat->zapiszSwiat(sciezka);
    }
    else if (ruchGracza == 101) {
        exit(1);
    }
    cout << "\n";
    obecnySwiat->setNowoWczytany(false);

    if ((nowaPozycja[0] < 0 || nowaPozycja[1] < 0) || (nowaPozycja[0] >= obecnySwiat->getN()) || (nowaPozycja[1] >= obecnySwiat->getM())) {
        cout << "\nZly ruch! Tracisz ture.\n";
        return;
    }

    if (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]) == NULL) {
        obecnySwiat->setOrganizmMapa(this, nowaPozycja[0], nowaPozycja[1]);
        obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
        pozycja[0] = nowaPozycja[0];
        pozycja[1] = nowaPozycja[1];
    }
    else {
        kolizja(obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]));
    }
}

void Czlowiek::specjalnaUmiejetnosc() { // Magiczny eliksir
    if (obecnySwiat->getczasOdnowieniaCzlowieka() == 0) {
        cout << "Aktywowano specjalna umiejetnosc Magiczny Eliksir.\n";
        obecnySwiat->setczasOdnowieniaCzlowieka(15);
        this->setSila(15);
    }
    else {
        cout << "Nie mozna uzyc specjalnej umiejetnosci. Zaczekaj.\n";
    }
}

Organizm* Czlowiek::klonowanie(int pozycjaX, int pozycjaY) {
	return new Czlowiek(obecnySwiat, pozycjaX, pozycjaY, 1);
}

Czlowiek::~Czlowiek() {
	obecnySwiat->setStatusGry();
}
