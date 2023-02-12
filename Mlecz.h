#pragma once

#include"Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    void akcja() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Mlecz() override;
};

