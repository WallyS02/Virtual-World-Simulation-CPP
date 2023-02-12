#pragma once

#include"Zwierze.h"

class Lis : public Zwierze {
public:
    Lis(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    void akcja() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Lis() override;
};

