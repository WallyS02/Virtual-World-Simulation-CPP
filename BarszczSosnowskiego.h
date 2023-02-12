#pragma once

#include"Roslina.h"

class BarszczSosnowskiego : public Roslina {
public:
    BarszczSosnowskiego(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    void rysowanie() override;
    void akcja() override;
    string getNazwa() override;
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~BarszczSosnowskiego() override;
};

