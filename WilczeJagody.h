#pragma once

#include"Roslina.h"

class WilczeJagody : public Roslina {
public:
    WilczeJagody(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~WilczeJagody() override;
};

