#pragma once

#include"Zwierze.h"

class Zolw : public Zwierze {
public:
    Zolw(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    void akcja() override;
    string getNazwa() override;
    bool odbijanieAtaku(Organizm* organizm) override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Zolw() override;
};

