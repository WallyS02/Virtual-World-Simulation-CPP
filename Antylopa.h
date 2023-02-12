#pragma once

#include"Zwierze.h"

class Antylopa : public Zwierze {
public:
    Antylopa(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    int* znajdowanieMiejscaDoRuchu() override;
    void rysowanie() override;
    string getNazwa() override;
    void kolizja(Organizm* kolidujacyOrganizm) override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Antylopa() override;
};
