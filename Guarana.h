#pragma once

#include"Roslina.h"

class Guarana : public Roslina {
public:
    Guarana(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Guarana() override;
};

