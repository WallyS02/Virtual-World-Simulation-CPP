#include "Swiat.h"
#include"Organizm.h"
#include"Zwierze.h"
#include"Roslina.h"
#include"Wilk.h"
#include"Owca.h"
#include"Lis.h"
#include"Zolw.h"
#include"Czlowiek.h"
#include"Antylopa.h"
#include"Trawa.h"
#include"Mlecz.h"
#include"Guarana.h"
#include"WilczeJagody.h"
#include"BarszczSosnowskiego.h"

Lista::Lista(int maksymalnyRozmiar) {
    this->maksymalnyRozmiar = maksymalnyRozmiar;
    obecnyRozmiar = 0;
    element = new wezel;
    element->element = NULL;
    element->nastepny = NULL;
}

int Lista::getMaksymalnyRozmiar() {
    return maksymalnyRozmiar;
}

int Lista::getObecnyRozmiar() {
    return obecnyRozmiar;
}

void Lista::dodaj(Organizm* dodawany) {
    if(obecnyRozmiar >= maksymalnyRozmiar) {
        cout << "Nie mozna dodac wiecej organizmow!\n";
        return;
    }

    wezel *nowyOrganizm = new wezel;
    nowyOrganizm->element = dodawany;
    nowyOrganizm->nastepny = NULL;

    wezel *obecny = element;

    while(obecny->nastepny != NULL){
        if(dodawany->getInicjatywa() > obecny->nastepny->element->getInicjatywa()){
            break;
        }
        else if(dodawany->getInicjatywa() == obecny->nastepny->element->getInicjatywa()){
            if(dodawany->getWiek() >= obecny->nastepny->element->getWiek()){
                break;
            }
        }
        obecny = obecny->nastepny;
    }
    nowyOrganizm->nastepny = obecny->nastepny;
    obecny->nastepny = nowyOrganizm;
    obecnyRozmiar++;
}

void Lista::usun(Organizm* usuwany) {
    wezel *obecny = element;
    for(int i = 0; i < obecnyRozmiar; i++){
        if(obecny->nastepny->element == usuwany){
            break;
        }
        if(i == obecnyRozmiar - 1){
            cout << "Brak takiego organizmu!\n";
            return;
        }
        obecny = obecny->nastepny;
    }

    obecny->nastepny = obecny->nastepny->nastepny;
    delete usuwany;
    obecnyRozmiar--;
}

Lista::~Lista() {

}



int Swiat::getN() {
    return N;
}

int Swiat::getczasOdnowieniaCzlowieka() {
    return czasOdnowieniaCzlowieka;
}

void Swiat::setczasOdnowieniaCzlowieka(int czasOdnowieniaCzlowieka) {
    this->czasOdnowieniaCzlowieka = czasOdnowieniaCzlowieka;
}

int Swiat::getM() {
    return M;
}

bool Swiat::getStatusGry() {
    return statusGry;
}

bool Swiat::getNowoWczytany() {
    return nowoWczytany;
}

void Swiat::setNowoWczytany(bool nowoWczytany) {
    this->nowoWczytany = nowoWczytany;
}

int Swiat::getTura() {
    return tura;
}

void Swiat::setTura(int tura) {
    this->tura = tura;
}

void Swiat::umiescLosowo(Organizm* organizm) {
    int pozycjaX, pozycjaY;
    pozycjaX = rand() % getN();
    pozycjaY = rand() % getM();

    if (mapa[pozycjaX][pozycjaY] == NULL) {
        organizm->setpozycjaX(pozycjaX);
        organizm->setpozycjaY(pozycjaY);
        mapa[pozycjaX][pozycjaY] = organizm;
        organizmy->dodaj(organizm);
    }
    else {
        delete organizm;
    }
}

void Swiat::umiescDokladnie(Organizm* organizm, int osN, int osM) {
    organizm->setpozycjaX(osN);
    organizm->setpozycjaY(osM);
    mapa[osN][osM] = organizm;
    organizmy->dodaj(organizm);
}

Swiat::Swiat(int N, int M) : N(N), M(M) {
    cout << "Tworzenie swiata. \n";
    srand(time(NULL));
    statusGry = true;
    nowoWczytany = false;
    czasOdnowieniaCzlowieka = 0;
    tura = 1;
    mapa = new Organizm **[N];
    for (int i = 0; i < N; i++) {
        mapa[i] = new Organizm *[M];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mapa[i][j] = NULL;
        }
    }
    organizmy = new Lista(N*M);

    umiescLosowo(new Czlowiek(this, -1, -1, 20));

    umiescLosowo(new Owca(this, -1, -1, 4, false));
    umiescLosowo(new Owca(this, -1, -1, 6, false));

    umiescLosowo(new Trawa(this, -1, -1, 2, false));
    umiescLosowo(new Trawa(this, -1, -1, 2, false));

    umiescLosowo(new Mlecz(this, -1, -1, 1, false));

    umiescLosowo(new Guarana(this, -1, -1, 5, false));

    umiescLosowo(new Wilk(this, -1, -1, 11, false));
    umiescLosowo(new Wilk(this, -1, -1, 8, false));

    umiescLosowo(new WilczeJagody(this, -1, -1, 3, false));

    umiescLosowo(new BarszczSosnowskiego(this, -1, -1, 4, false));

    umiescLosowo(new Lis(this, -1, -1, 6, false));

    umiescLosowo(new Zolw(this, -1, -1, 75, false));

    umiescLosowo(new Antylopa(this, -1, -1, 5, false));
    umiescLosowo(new Antylopa(this, -1, -1, 6, false));
}

void Swiat::setStatusGry() {
    if (statusGry)
        statusGry = false;
    else statusGry = true;
}

void Swiat::rysujSwiat() {
    int i, j, k = 0;
    cout << "Tura: " << tura;
    cout << "\n#";

    for(i = 0; i <= N; i++) {
        cout << "#";
    }
    cout << "\n";
    for(i = 0; i <= M; i++){
        cout << "#";
        if (i == M) {
            for (int p = 0; p <= N; p++) {
                cout << '#';
            }
        }
        for(j = 0; j <= N; j++){
            if(j != N && i != M && mapa[j][i] != NULL) {
                if(typeid(*mapa[j][i]).hash_code() == typeid(Czlowiek).hash_code()){
                    mapa[j][i]->rysowanie();
                }
                else{
                    mapa[j][i]->rysowanie();
                }
            }
            else{
                if (j == N && i != M)
                    cout << '#';
                else cout << " ";
            }
        }
        cout << "\n";
    }
    cout << "Legenda :\n[A - Antylopa][J - Wilcza Jagoda][L - Lis]\n[T - Trawa][G - Guarana][B - Barszcz Sosnowskiego]\n[C - Czlowiek][O - Owca][M - Mlecz]\n[Z - Zolw][W - Wilk]\n";
}

void Swiat::wykonajTure() {
cout << "Proces tury: " << tura << "\n";

    wezel *obecny = organizmy->element->nastepny;
    if (czasOdnowieniaCzlowieka > 0) {
        czasOdnowieniaCzlowieka--;
    }

    while(obecny != NULL) {
        if(obecny->element->getNowoStworzony() == true){
            obecny->element->setNowoStworzony(false);
        }
        else{
            obecny->element->akcja();
        }
        obecny = obecny->nastepny;
    }
    getchar();
    tura++;
}

Organizm *Swiat::getPoleMapy(int x, int y) {
    return mapa[x][y];
}

void Swiat::setOrganizm(Organizm* organizm) {
    organizmy->dodaj(organizm);
}

void Swiat::usunOrganizm(Organizm* organizm) {
    organizmy->usun(organizm);
}

void Swiat::setOrganizmMapa(Organizm* organizm, int pozycjaX, int pozycjaY) {
    if (organizm == NULL && mapa[pozycjaX][pozycjaY] == NULL) {

    }
    else mapa[pozycjaX][pozycjaY] = organizm;
}

Swiat::Swiat(string sciezka) {
    srand(time(NULL));

    statusGry = true;
    nowoWczytany = true;

    ifstream wczytywanyPlik;
    wczytywanyPlik.open(sciezka, ios::in);
    if (!wczytywanyPlik) {
        cout << "Brak zapisanego swiata.\n";
        exit(1);
    }

    string slowo;
    int staraTura, staryCzasOdnowieniaCzlowieka, stareN, stareM, staryWiek, staryStatusGry;
    wczytywanyPlik >> staraTura >> staryCzasOdnowieniaCzlowieka;
    wczytywanyPlik >> stareN >> stareM;
    tura = staraTura;
    czasOdnowieniaCzlowieka = staryCzasOdnowieniaCzlowieka;
    N = stareN;
    M = stareM;

    mapa = new Organizm * *[N];
    for (int i = 0; i < N; i++) {
        mapa[i] = new Organizm * [M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            mapa[i][j] = NULL;
        }
    }

    organizmy = new Lista(N * M);

    while (wczytywanyPlik >> slowo) {
        wczytywanyPlik >> stareN >> stareM >> staryWiek >> staryStatusGry;
        if (!slowo.compare("Antylopa")) {
            umiescDokladnie(new Antylopa(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("WilczeJagody")) {
            umiescDokladnie(new WilczeJagody(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Mlecz")) {
            umiescDokladnie(new Mlecz(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Lis")) {
            umiescDokladnie(new Lis(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Trawa")) {
            umiescDokladnie(new Trawa(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Guarana")) {
            umiescDokladnie(new Guarana(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("BarszczSosnowskiego")) {
            umiescDokladnie(new BarszczSosnowskiego(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Czlowiek")) {
            umiescDokladnie(new Czlowiek(this, -1, -1, staryWiek), stareN, stareM);
        }
        else if (!slowo.compare("Owca")) {
            umiescDokladnie(new Owca(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Zolw")) {
            umiescDokladnie(new Zolw(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
        else if (!slowo.compare("Wilk")) {
            umiescDokladnie(new Wilk(this, -1, -1, staryWiek, staryStatusGry), stareN, stareM);
        }
    }
    wczytywanyPlik.close();
    cout << "Wczytano swiat" << "\n";
}

void Swiat::zapiszSwiat(string sciezka) {
    ofstream plikZapisu;
    plikZapisu.open(sciezka, ios::out);
    if (!plikZapisu) {
        cout << "Wystapily problemy z zapisaniem do pliku.\n";
        return;
    }
    else {
        plikZapisu << tura << " " << czasOdnowieniaCzlowieka << "\n";
        plikZapisu << N << " " << M << "\n";
        wezel* obecny = organizmy->element->nastepny;
        while (obecny != NULL) {
            plikZapisu << obecny->element->getNazwa() << " " << obecny->element->getpozycjaX() << " " << obecny->element->getpozycjaY() << " " << obecny->element->getWiek() << " " << obecny->element->getNowoStworzony() << "\n";
            obecny = obecny->nastepny;
        }
        plikZapisu.close();
        cout << "Zapisano swiat do pliku.\n";
    }
}

Swiat::~Swiat() {

}