#pragma once

#include<fstream>

class Organizm;

using std::string;

struct wezel {
	Organizm* element;
	wezel* nastepny;
};

class Lista {
	int maksymalnyRozmiar;
	int obecnyRozmiar;
public:
	Lista(int maksymalnyRozmiar);
	wezel* element;
	int getMaksymalnyRozmiar();
	int getObecnyRozmiar();
	void dodaj(Organizm *dodawany);
	void usun(Organizm *usuwany);
	~Lista();
};

class Swiat {
	int N, M, tura;
	bool statusGry, nowoWczytany;
	Organizm*** mapa;
	Lista* organizmy;
	int czasOdnowieniaCzlowieka;
public:
	Swiat(int N, int M);
	Swiat(string sciezka);
	int getN();
	int getM();
	int getczasOdnowieniaCzlowieka();
	bool getStatusGry();
	int getTura();
	bool getNowoWczytany();
	void setNowoWczytany(bool nowoWczytany);
	void setTura(int tura);
	void setStatusGry();
	void setOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	Organizm *getPoleMapy(int x, int y);
	void setOrganizmMapa(Organizm* organizm, int pozycjaX, int pozycjaY);
	void setczasOdnowieniaCzlowieka(int czasOdnowieniaCzlowieka);
	void rysujSwiat();
	void wykonajTure();
	void umiescLosowo(Organizm* organizm);
	void umiescDokladnie(Organizm * organizm, int osN, int osM);
	void zapiszSwiat(string sciezka);
	~Swiat();
};
