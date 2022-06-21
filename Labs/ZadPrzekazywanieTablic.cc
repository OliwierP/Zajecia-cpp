#include <iostream>
using namespace std;

typedef struct {
    int t[10];
} table;

void size_test(table x) {
    cout << sizeof(x.t) << ", " << sizeof(x.t[0]) << endl;
}

int main() {
    table tab;
    cout << sizeof(tab.t) << ", " << sizeof(tab.t[0]) << endl;
    cout << "--------------------------------" << endl;
    size_test(tab);
    return 0;
}