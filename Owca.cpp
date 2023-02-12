#include "Owca.h"

Owca::Owca(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Zwierze(obecnySwiat, 4, 4, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Owca::rysowanie() {
	cout << "O";
}

string Owca::getNazwa() {
	return ("Owca");
}

Organizm* Owca::klonowanie(int pozycjaX, int pozycjaY) {
	return new Owca(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Owca::~Owca() {

}
