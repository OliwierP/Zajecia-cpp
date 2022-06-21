#include <iostream>
#include <string>
using namespace std;



int main() {
    string word;
    cout << "Podaj dowolne slowo: ";
    cin >> word;
    switch (word[0]) {
    case 't':
        switch (word[1]) {
        case 'a':
            switch (word[2]) {
            case 'k':
                cout << "Podano slowo: tak" << endl;
                break;

            default:
                cout << "Podano bledne slowo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano bledne slowo." << endl;
            break;
        
        }
        break;

    case 'n':
        switch (word[1]) {
        case 'i':
            switch (word[2]) {
            case 'e':
                cout << "Podano slowo: nie" << endl;
                break;

            default:
                cout << "Podano bledne slowo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano bledne slowo." << endl;
            break;
        }
        break;
    
    default:
        cout << "Podano bledne slowo." << endl;
        break;
    }
}
