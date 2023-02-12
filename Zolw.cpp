#include "Zolw.h"

Zolw::Zolw(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Zwierze(obecnySwiat, 2, 1, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Zolw::rysowanie() {
	cout << "Z";
}

string Zolw::getNazwa() {
	return ("Zolw");
}

void Zolw::akcja() {
	wiek++;
	int losowanie = rand() % 100 + 1;
	if (losowanie > 75) {
		Zwierze::akcja();
	}
}

bool Zolw::odbijanieAtaku(Organizm* organizm) {
	return (organizm->getSila() < 5);
}

Organizm* Zolw::klonowanie(int pozycjaX, int pozycjaY) {
	return new Zolw(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Zolw::~Zolw() {

}
