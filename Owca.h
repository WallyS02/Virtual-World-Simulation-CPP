#pragma once

#include"Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Owca() override;
};

