#include "Guarana.h"

Guarana::Guarana(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Roslina(obecnySwiat, 0, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Guarana::rysowanie() {
	cout << "G";
}

string Guarana::getNazwa() {
	return ("Guarana");
}

Organizm* Guarana::klonowanie(int pozycjaX, int pozycjaY) {
	return new Guarana(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Guarana::~Guarana() {

}
