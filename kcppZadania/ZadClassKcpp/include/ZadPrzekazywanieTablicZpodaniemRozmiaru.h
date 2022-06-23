#include <iostream>


void ZadKcpp::przekaz_tablica(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "tablica[" << i << "] = " << tablica[i] << std::endl;
    }
}

void ZadKcpp::przekaz_tablica2(int *tablica2, int rozmiar2) {
    for (int i = 0; i < rozmiar2; i++) {
        std::cout << "tablica2[" << i << "] = " << *(tablica2 + i) << std::endl;
    }
}
