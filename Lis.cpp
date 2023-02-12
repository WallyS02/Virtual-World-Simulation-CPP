#include "Lis.h"

Lis::Lis(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Zwierze(obecnySwiat, 3, 7, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Lis::rysowanie() {
	cout << "L";
}

string Lis::getNazwa() {
	return ("Lis");
}

void Lis::akcja() {
    wiek++;
    int* nowaPozycja = znajdowanieMiejscaDoRuchu();

    if (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]) == NULL) {
        obecnySwiat->setOrganizmMapa(this, nowaPozycja[0], nowaPozycja[1]);
        obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
        pozycja[0] = nowaPozycja[0];
        pozycja[1] = nowaPozycja[1];
    }
    else {
        if (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1])->getSila() <= getSila()) {
            kolizja(obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]));
        }
        else {
            cout << "Kolidujace organizmy: " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), ";
            cout << obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1])->getNazwa() << "(" << obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1])->getpozycjaY() << ").\n";
        }
    }
    delete nowaPozycja;
}

Organizm* Lis::klonowanie(int pozycjaX, int pozycjaY) {
	return new Lis(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Lis::~Lis() {

}
