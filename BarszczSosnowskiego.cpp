#include "BarszczSosnowskiego.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* obecnySwiat, int pozycjaX, int pozycjaY, int wiek, bool nowoStworzony)
	: Roslina(obecnySwiat, 10, pozycjaX, pozycjaY, wiek, nowoStworzony) {
}

void BarszczSosnowskiego::rysowanie() {
	cout << "B";
}

string BarszczSosnowskiego::getNazwa() {
	return("BarszczSosnowskiego");
}

void BarszczSosnowskiego::akcja() {
    wiek++;
    int obecnaPozycja[2];
    obecnaPozycja[0] = pozycja[0];
    obecnaPozycja[1] = pozycja[1];

    if (obecnaPozycja[0] == 0 && obecnaPozycja[1] == 0) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
        cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

        obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
        obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[0] == obecnySwiat->getN() - 1 && obecnaPozycja[1] == 0) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[0] == 0 && obecnaPozycja[1] == obecnySwiat->getM() - 1) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[0] == obecnySwiat->getN() - 1 && obecnaPozycja[1] == obecnySwiat->getM() - 1) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[0] == 0) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[0] == obecnySwiat->getN() - 1) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[1] == 0) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    else if (obecnaPozycja[1] == obecnySwiat->getM() - 1) {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";
                
            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";
    
            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";
    
            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    else {
        if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] - 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] - 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1)->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0], obecnaPozycja[1] + 1));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0], obecnaPozycja[1] + 1);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] - 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] - 1, obecnaPozycja[1]);
        }
        else if (Zwierze* zwierze = dynamic_cast<Zwierze*>(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]))) {
            cout << "Barszcz Sosnowskiego " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << "), " << "zabija : " << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getNazwa() << " (" << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaX() << "," << obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1])->getpozycjaY() << ").\n";

            obecnySwiat->usunOrganizm(obecnySwiat->getPoleMapy(obecnaPozycja[0] + 1, obecnaPozycja[1]));
            obecnySwiat->setOrganizmMapa(NULL, obecnaPozycja[0] + 1, obecnaPozycja[1]);
        }
    }
    int losuj = rand() % 100 + 1;
    if (losuj > 85) {
        cout << "Rozprzestrzenianie " << this->getNazwa() << " (" << pozycja[0] << "," << pozycja[1] << ").\n";
        int* nowaPozycja = znajdowanieNiezajetegoMiejscaDoRuchu();
        if (nowaPozycja[0] == -1 && nowaPozycja[1] == -1) {
            cout << "Brak pol do rozprzestrzeniania!\n";
            delete nowaPozycja;
            return;
        }
        else {
            klonowanie(nowaPozycja[0], nowaPozycja[1]);
        }
    }
}

Organizm* BarszczSosnowskiego::klonowanie(int pozycjaX, int pozycjaY) {
	return new BarszczSosnowskiego(obecnySwiat, pozycjaX, pozycjaY, 1, true);
}

BarszczSosnowskiego::~BarszczSosnowskiego() {

}
