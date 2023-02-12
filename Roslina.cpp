#include "Roslina.h"

Roslina::Roslina(Swiat* obecnySwiat, int sila, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony) 
	: Organizm(obecnySwiat, sila, 0, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void Roslina::akcja() {
    if (this->getNazwa().compare("Mlecz")) {
        wiek++;
    }
    int losuj = rand() % 100 + 1;
    if (losuj > 85) {
        cout << "Rozprzestrzenianie " << this->getNazwa() << " (" << pozycja[0] << ", " << pozycja[1] << ").\n";
        int* nowaPozycja = znajdowanieNiezajetegoMiejscaDoRuchu();
        if (nowaPozycja[0] == -1 && nowaPozycja[1] == -1) {
            cout << "Brak miejsca na rozprzestrzenianie!\n";
            delete nowaPozycja;
            return;
        }
        else {
            klonowanie(nowaPozycja[0], nowaPozycja[1]);
        }
    }
}

Roslina::~Roslina() {

}
