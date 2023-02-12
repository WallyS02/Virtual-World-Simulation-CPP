#pragma once

#include"Organizm.h"

class Roslina : public Organizm {
public:
    Roslina(Swiat* obecnySwiat, int sila, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void akcja() override;
    ~Roslina();
};

