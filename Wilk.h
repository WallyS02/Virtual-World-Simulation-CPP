#pragma once

#include"Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Wilk() override;
};

