#include "Trawa.h"

Trawa::Trawa(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Roslina(obecnySwiat, 0, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Trawa::rysowanie() {
	cout << "T";
}

string Trawa::getNazwa() {
	return ("Trawa");
}

Organizm* Trawa::klonowanie(int pozycjaX, int pozycjaY) {
	return new Trawa(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Trawa::~Trawa() {

}
