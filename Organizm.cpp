#include "Organizm.h"

Organizm::Organizm(Swiat* obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony) {
	this->obecnySwiat = obecnySwiat;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->pozycja[0] = pozycjaX;
	this->pozycja[1] = pozycjaY;
	if (pozycjaX == -1 && pozycjaY == -1) return;
	this->wiek = wiek;
	this->nowoStworzony = nowoStworzony;
	obecnySwiat->setOrganizmMapa(this, pozycjaX, pozycjaY);
	obecnySwiat->setOrganizm(this);
}

int* Organizm::znajdowanieMiejscaDoRuchu() {
    int* nowaPozycja = new int[2];
    nowaPozycja[0] = pozycja[0];
    nowaPozycja[1] = pozycja[1];

    int pole;
    bool zlyRuch;
    do {
        pole = rand() % 4;
        zlyRuch = false;
        switch (pole) {
        case 0:    
            if (nowaPozycja[1] == 0) {
                zlyRuch = true;
            }
            else nowaPozycja[1]--;
            break;
        case 1:     
            if (nowaPozycja[0] == obecnySwiat->getN() - 1) {
                zlyRuch = true;
            }
            else nowaPozycja[0]++;
            break;
        case 2:     
            if (nowaPozycja[1] == obecnySwiat->getM() - 1) {
                zlyRuch = true;
            }
            else nowaPozycja[1]++;
            break;
        case 3:     
            if (nowaPozycja[0] == 0) {
                zlyRuch = true;
            }
            else nowaPozycja[0]--;
        }
    } while (zlyRuch);
    return nowaPozycja;
}

int* Organizm::znajdowanieNiezajetegoMiejscaDoRuchu() {
    int* nowaPozycja = new int[2];
    nowaPozycja[0] = pozycja[0];
    nowaPozycja[1] = pozycja[1];

    if ((nowaPozycja[1] != 0) && (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1] - 1) == NULL)) {
        nowaPozycja[1]--;
        return nowaPozycja;
    }
    else if ((nowaPozycja[0] != obecnySwiat->getN() - 1) && (obecnySwiat->getPoleMapy(nowaPozycja[0] + 1, nowaPozycja[1]) == NULL)) {
        nowaPozycja[0]++;
        return nowaPozycja;
    }
    else if ((nowaPozycja[1] != obecnySwiat->getM() - 1) && (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1] + 1) == NULL)) {
        nowaPozycja[1]++;
        return nowaPozycja;
    }
    else if ((nowaPozycja[0] != 0) && (obecnySwiat->getPoleMapy(nowaPozycja[0] - 1, nowaPozycja[1]) == NULL)) {
        nowaPozycja[0]--;
        return nowaPozycja;
    }

    nowaPozycja[0] = -1;
    nowaPozycja[1] = -1;
    return nowaPozycja;
}

int Organizm::getSila() {
	return sila;
}

void Organizm::setSila(int sila) {
    this->sila = sila;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}

void Organizm::setpozycjaX(int pozycjaX) {
	this->pozycja[0] = pozycjaX;
}

void Organizm::setpozycjaY(int pozycjaY) {
	this->pozycja[1] = pozycjaY;
}

int Organizm::getpozycjaX() {
	return pozycja[0];
}

int Organizm::getpozycjaY() {
	return pozycja[1];
}

int Organizm::getWiek() {
	return wiek;
}

bool Organizm::getNowoStworzony() {
	return nowoStworzony;
}

void Organizm::setNowoStworzony(bool nowoStworzony) {
	this->nowoStworzony = nowoStworzony;
}

bool Organizm::odbijanieAtaku(Organizm* organizm) {
	return false;
}

Organizm::~Organizm() {

}