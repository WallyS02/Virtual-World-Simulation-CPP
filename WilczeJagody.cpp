#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Roslina(obecnySwiat, 99, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void WilczeJagody::rysowanie() {
	cout << "J";
}

string WilczeJagody::getNazwa() {
	return("WilczaJagoda");
}

Organizm* WilczeJagody::klonowanie(int pozycjaX, int pozycjaY) {
	return new WilczeJagody(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

WilczeJagody::~WilczeJagody() {

}
