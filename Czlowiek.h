#pragma once

#include"Zwierze.h"

class Czlowiek : public Zwierze {
public:
    Czlowiek(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek);
    void rysowanie() override;
    void akcja() override;
    string getNazwa() override;
    void specjalnaUmiejetnosc();
    Organizm* klonowanie(int pozycjaX, int pozycjaY) override;
    ~Czlowiek();
};

