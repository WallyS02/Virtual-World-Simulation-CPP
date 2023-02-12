#include "Mlecz.h"

Mlecz::Mlecz(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Roslina(obecnySwiat, 0, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Mlecz::rysowanie() {
	cout << "M";
}

void Mlecz::akcja() {
	wiek++;
	Roslina::akcja();
	Roslina::akcja();
	Roslina::akcja();
}

string Mlecz::getNazwa() {
	return ("Mlecz");
}

Organizm* Mlecz::klonowanie(int pozycjaX, int pozycjaY) {
	return new Mlecz(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

Mlecz::~Mlecz() {

}
