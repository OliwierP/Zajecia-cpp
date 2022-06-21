#include <iostream>
using namespace std;

/**
 * Zadanie 3.4 (LArytmetykaWskaznikowTablice.cc)
 * --------------------------------------
 * Zaproponuj inne dwa sposoby wyboru wywo�ania funkcji
 * Nazwa� program: ZadWywolanieFunkcji.cc 
 */

void funA() {
    cout << "Wywo�ano funA()" << endl;
}

void funB() {
    cout << "Wywo�ano funB()" << endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char choice;
        cout << "Wybierz funkcje do wywo�ania: " << endl;
        cout << "1 - funA()" << endl;
        cout << "2 - funB()" << endl;
        cin >> choice;
        switch (choice) {
            case '1':
                funA();
                break;
            case '2':
                funB();
                break;
            default:
                cout << "Brak takiej opcji" << endl;
                break;
        }
    } else if (argc == 2) {
        if (argv[1] == string("funA")) {
            funA();
        } else if (argv[1] == string("funB")) {
            funB();
        } else {
            cout << "Brak takiej opcji" << endl;
        }
    } else {
        cout << "Podano niew�a�ciw� liczb� argument�w" << endl;
    }
    return 0;
}