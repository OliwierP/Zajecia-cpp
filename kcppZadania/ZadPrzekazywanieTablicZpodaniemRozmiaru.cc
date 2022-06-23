#include <iostream>


void przekaz_tablica(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        std::cout << "tablica[" << i << "] = " << tablica[i] << std::endl;
    }
}

void przekaz_tablica2(int *tablica2, int rozmiar2) {
    for (int i = 0; i < rozmiar2; i++) {
        std::cout << "tablica2[" << i << "] = " << *(tablica2 + i) << std::endl;
    }
}


int main() {
    
    int array[] = {3, 4, 6};
    int array_size = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Rozmiar array = " << array_size << std::endl << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << "array[" << i << "] = " << array[i] << std::endl;
    }
    
    std::cout << '\n';
    przekaz_tablica(array, array_size);
    std::cout << '\n';
    przekaz_tablica2(array, array_size);
}
