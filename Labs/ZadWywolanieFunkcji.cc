#include <iostream>
using namespace std;

/**
 * Zadanie 3.4 (LArytmetykaWskaznikowTablice.cc)
 * --------------------------------------
 * Zaproponuj inne dwa sposoby wyboru wywo³ania funkcji
 * Nazwaæ program: ZadWywolanieFunkcji.cc 
 */

void funA() {
    cout << "Wywo³ano funA()" << endl;
}

void funB() {
    cout << "Wywo³ano funB()" << endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char choice;
        cout << "Wybierz funkcje do wywo³ania: " << endl;
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
        cout << "Podano niew³aœciw¹ liczbê argumentów" << endl;
    }
    return 0;
    
}
