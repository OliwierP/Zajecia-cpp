#include <iostream>
#include <string>
using namespace std;



int main() {
    string word;
    cout << "Podaj dowolne s�owo: ";
    cin >> word;
    switch (word[0]) {
    case 't':
        switch (word[1]) {
        case 'a':
            switch (word[2]) {
            case 'k':
                cout << "Podano s�owo: tak" << endl;
                break;

            default:
                cout << "Podano b��dne s�owo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano b��dne s�owo." << endl;
            break;
        
        }
        break;

    case 'n':
        switch (word[1]) {
        case 'i':
            switch (word[2]) {
            case 'e':
                cout << "Podano s�owo: nie" << endl;
                break;

            default:
                cout << "Podano b��dne s�owo." << endl;
                break;
            }
            break;

        default:
            cout << "Podano b��dne s�owo." << endl;
            break;
        }
        break;
    
    default:
        cout << "Podano b��dne s�owo." << endl;
        break;
    }
}