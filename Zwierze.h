#pragma once

#include"Organizm.h"

class Zwierze : public Organizm {
public:
    Zwierze(Swiat* obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
    bool pasujaceGatunki(Organizm& ogolny);
    void rozmazanie();         
    void akcja() override;                     
    virtual void kolizja(Organizm* kolidujacyOrganizm);
    ~Zwierze();
};
