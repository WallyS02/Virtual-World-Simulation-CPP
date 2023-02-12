#include "Antylopa.h"

Antylopa::Antylopa(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Zwierze(obecnySwiat, 4, 4, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

int* Antylopa::znajdowanieMiejscaDoRuchu() {
    int* nowaPozycja = new int[2];

    nowaPozycja[0] = pozycja[0];
    nowaPozycja[1] = pozycja[1];

    int pole;
    bool zlyRuch;
    do {
        pole = rand() % 8;
        zlyRuch = false;
        switch (pole) {
        case 0:
            if (nowaPozycja[1] == 0)
                zlyRuch = true;
            else nowaPozycja[1]--;
            break;
        case 1:
            if (nowaPozycja[0] == obecnySwiat->getN() - 1)
                zlyRuch = true;
            else nowaPozycja[0]++;
            break;
        case 2:
            if (nowaPozycja[1] == obecnySwiat->getM() - 1)
                zlyRuch = true;
            else nowaPozycja[1]++;
            break;
        case 3:
            if (nowaPozycja[0] == 0)
                zlyRuch = true;
            else nowaPozycja[0]--;
            break;
        case 4:
            if (nowaPozycja[1] <= 1)
                zlyRuch = true;
            else nowaPozycja[1] -= 2;
            break;
        case 5:
            if (nowaPozycja[0] >= obecnySwiat->getN() - 2)
                zlyRuch = true;
            else nowaPozycja[0] += 2;
            break;
        case 6:
            if (nowaPozycja[1] >= obecnySwiat->getM() - 2)
                zlyRuch = true;
            else nowaPozycja[1] += 2;
            break;
        case 7:
            if (nowaPozycja[0] <= 1)
                zlyRuch = true;
            else nowaPozycja[0] -= 2;
            break;
        }
    } while (zlyRuch);

    return nowaPozycja;
}

void Antylopa::rysowanie() {
	cout << "A";
}

string Antylopa::getNazwa() {
	return ("Antylopa");
}

void Antylopa::kolizja(Organizm* kolidujacyOrganizm) {
    int losuj = rand() % 2;
    if ((losuj > 0) && !(pasujaceGatunki(*kolidujacyOrganizm)) && (kolidujacyOrganizm->getSila() > sila)) {
        cout << "Kolidujace organizmy: " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), ";
        cout << kolidujacyOrganizm->getNazwa() << " (" << kolidujacyOrganizm->getpozycjaX() << "," << kolidujacyOrganizm->getpozycjaY() << ").\n";
        int* nowaPozycja = znajdowanieNiezajetegoMiejscaDoRuchu();
        if ((nowaPozycja[0] != -1) && (nowaPozycja[1] != -1)) {
            obecnySwiat->setOrganizmMapa(this, nowaPozycja[0], nowaPozycja[1]);
            obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
            pozycja[0] = nowaPozycja[0];
            pozycja[1] = nowaPozycja[1];
        }
    }
    else {
        Zwierze::kolizja(kolidujacyOrganizm);
    }
}

Organizm* Antylopa::klonowanie(int pozycjaX, int pozycjaY) {
	return new Antylopa(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Antylopa::~Antylopa() {

}
