#pragma once

#include"Roslina.h"

class Trawa : public Roslina {
public:
    Trawa(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Trawa() override;
};

