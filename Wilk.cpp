#include "Wilk.h"

Wilk::Wilk(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Zwierze(obecnySwiat, 9, 5, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Wilk::rysowanie() {
	cout << "W";
}

string Wilk::getNazwa() {
	return ("Wilk");
}

Organizm* Wilk::klonowanie(int pozycjaX, int pozycjaY) {
	return new Wilk(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Wilk::~Wilk() {

}
