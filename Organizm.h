#pragma once

#include <string>
#include <iostream>

using std::string;
using namespace std;

class Swiat;

class Organizm {
protected:
	Swiat* obecnySwiat;
	int sila;
	int inicjatywa;
	int pozycja[2];
	int wiek;
	bool nowoStworzony;
public:
	Organizm(Swiat* obecnySwiat, int sila, int inicjatywa, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony);
	virtual int* znajdowanieMiejscaDoRuchu();
	int* znajdowanieNiezajetegoMiejscaDoRuchu();
	int getSila();
	void setSila(int sila);
	int getInicjatywa();
	void setpozycjaX(int x);
	void setpozycjaY(int y);
	int getpozycjaX();
	int getpozycjaY();
	int getWiek();
	bool getNowoStworzony();
	void setNowoStworzony(bool nowoStworzony);
	virtual bool odbijanieAtaku(Organizm* organizm);
	virtual Organizm* klonowanie(int posX, int posY) = 0;
	virtual string getNazwa() = 0;
	virtual void rysowanie() = 0;
	virtual void akcja() = 0;
	virtual ~Organizm();
};
#include"Swiat.h"