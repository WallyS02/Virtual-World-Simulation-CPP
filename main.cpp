// Sebastian Kutny, 2022, index : 188586
// Data realizacji projektu : 26.04.2022

#include <iostream>
#include"Swiat.h"

using namespace std;

int main() {
    cout << "      |        PO 2022            |\n";
    cout << "      | Sebastian Kutny 188586    |\n";
    cout << "      |        Sterowanie         |\n";
    cout << "      |   w - gora   s - dol      |\n";
    cout << "      |   a - lewo  d - prawo     |\n";
    cout << "      | r - specjalna umiejetnosc |\n";
    cout << "      |        q - zapis          |\n";
    cout << "      |       e - wyjscie         |\n";
    cout << "      |   - - - - - - - - - - -   |\n";
    cout << "      |  1 - Nowa gra             |\n";
    cout << "      |  2 - Wczytaj gre          |\n";
    cout << "      |  3 - Wyjdz                |\n";
    cout << "      |   - - - - - - - - - - -   |\n";
    cout << "      | Wybierz opcje :  ";
    int wybor;
    cin >> wybor;
    int N, M, przerwa;
    if (wybor == 1) {
        cout << "      | Rozmiar nowego swiata : ";
        cin >> N >> M;
        Swiat nowySwiat(N, M);
        while (nowySwiat.getStatusGry()) {
            system("cls");
            nowySwiat.rysujSwiat();
            nowySwiat.wykonajTure();
            przerwa = getchar();
        }
        system("cls");
        nowySwiat.rysujSwiat();
    }
    else if (wybor == 2) {
        string sciezka;
        cout << "      | Nazwa pliku do wczytania : ";
        cin >> sciezka;
        sciezka = sciezka + ".txt";
        Swiat wczytywanySwiat(sciezka);
        while (wczytywanySwiat.getStatusGry()) {
            system("cls");
            wczytywanySwiat.rysujSwiat();
            wczytywanySwiat.wykonajTure();
            przerwa = getchar();
        }
        system("cls");
        wczytywanySwiat.rysujSwiat();
    }
    else {
        exit(1);
    }
    cout << "Koniec gry \n";
    cout << "Wcisnij cokolwiek aby wyjsc...";
    getchar();
    return 0;
}