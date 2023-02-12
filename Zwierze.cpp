#include "Zwierze.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Czlowiek.h"

Zwierze::Zwierze(Swiat* obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Organizm(obecnySwiat, sila, inicjatywa, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

bool Zwierze::pasujaceGatunki(Organizm& ogolny) {
	return (this->getNazwa() == ogolny.getNazwa());
}

void Zwierze::rozmazanie() {
int *nowaPozycja = znajdowanieNiezajetegoMiejscaDoRuchu();
    if(nowaPozycja[0] == -1 && nowaPozycja[1] == -1){
        cout << "Rozmnazanie " << this->getNazwa() << " nieudane. Brak miejsca!\n";
        return;
    }
    klonowanie(nowaPozycja[0], nowaPozycja[1]);
    delete nowaPozycja;
}

void Zwierze::akcja() {
    if (this->getNazwa().compare("Zolw")) {
        wiek++;
    }
    int* nowaPozycja = znajdowanieMiejscaDoRuchu();
    if (obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]) == NULL) {
        obecnySwiat->setOrganizmMapa(this, nowaPozycja[0], nowaPozycja[1]);
        obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
        pozycja[0] = nowaPozycja[0];
        pozycja[1] = nowaPozycja[1];
    }
    else {
        kolizja(obecnySwiat->getPoleMapy(nowaPozycja[0], nowaPozycja[1]));
    }
    delete nowaPozycja;
}

void Zwierze::kolizja(Organizm* kolidujacyOrganizm) {
    if (pasujaceGatunki(*kolidujacyOrganizm)) {
        if (typeid(*kolidujacyOrganizm).hash_code() == typeid(Czlowiek).hash_code()) {
            return;
        }
        cout << "Kolidujace organizmy: " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), ";
        cout << kolidujacyOrganizm->getNazwa() << " (" << kolidujacyOrganizm->getpozycjaX() << "," << kolidujacyOrganizm->getpozycjaY() << ").\n";
        rozmazanie();
        return;
    }
    else {
        if (kolidujacyOrganizm->odbijanieAtaku(this)) {
            cout << "Kolidujace organizmy: " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), ";
            cout << kolidujacyOrganizm->getNazwa() << " (" << kolidujacyOrganizm->getpozycjaX() << "," << kolidujacyOrganizm->getpozycjaY() << ").\n";
            return;
        }
        cout << "Kolidujace organizmy: " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), ";
        cout << kolidujacyOrganizm->getNazwa() << " (" << kolidujacyOrganizm->getpozycjaX() << "," << kolidujacyOrganizm->getpozycjaY() << ").\n";
        if (sila >= kolidujacyOrganizm->getSila() && typeid(*kolidujacyOrganizm).hash_code() != typeid(WilczeJagody).hash_code() && typeid(*kolidujacyOrganizm).hash_code() != typeid(BarszczSosnowskiego).hash_code()) {
            cout << "Zwyciestwo organizmu " << this->getNazwa() << "\n";
            if (typeid(*kolidujacyOrganizm).hash_code() == typeid(Guarana).hash_code()) {
                cout << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << ") sila zwiekszona.\n";
                sila += 3;
            }
            obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
            pozycja[0] = kolidujacyOrganizm->getpozycjaX();
            pozycja[1] = kolidujacyOrganizm->getpozycjaY();
            obecnySwiat->setOrganizmMapa(this, pozycja[0], pozycja[1]);

            obecnySwiat->usunOrganizm(kolidujacyOrganizm);
        }
        else {
            cout << "Smierc " << this->getNazwa() << ".\n";
            obecnySwiat->setOrganizmMapa(NULL, pozycja[0], pozycja[1]);
            obecnySwiat->usunOrganizm(this);
        }
    }
}

Zwierze::~Zwierze() {

}
