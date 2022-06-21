#include <iostream>
#include <string>
using namespace std;



int main() {
    string word;
    cout << "Podaj dowolne s這wo: ";
    cin >> word;
    switch (word[0]) {
    case 't':
        switch (word[1]) {
        case 'a':
            switch (word[2]) {
            case 'k':
                cout << "Podano s這wo: tak" << endl;
                break;

            default:
                cout << "Podano b喚dne s這wo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano b喚dne s這wo." << endl;
            break;
        
        }
        break;

    case 'n':
        switch (word[1]) {
        case 'i':
            switch (word[2]) {
            case 'e':
                cout << "Podano s這wo: nie" << endl;
                break;

            default:
                cout << "Podano b喚dne s這wo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano b喚dne s這wo." << endl;
            break;
        }
        break;
    
    default:
        cout << "Podano b喚dne s這wo." << endl;
        break;
    }
}