#include <iostream>


class ZadKcpp {

public:

    ZadKcpp(){};



    void zadPetle() {
        petleFor();
        petleWhile();
        petleDoWhile();
    }

    void zadParzysta() {
        int number;
        std::cout << "podaj liczbe: \n";
        std::cin >> number;
        bool modulo = czy_parzysta_modulo(number);
        bool bit = czy_parzysta_bit(number);
        bool other = czy_parzysta_inna(number);
        std::cout << "modulo: " << (modulo ? "true" : "false") << " bitowo: " << (bit ? "true" : "false") << " inaczej: " << (other ? "true" : "false") << std::endl;
    }

    void zadPrzekazywanieTablicZpodaniemRozmiaru() {
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

    void zadArytmetykaWskaznikow() {
        Funkcja1();
        printf("\n\n\n\n\n\n");
        Funkcja2();
        printf("\n\n\n\n\n\n");
        Funkcja3();
    }

    void zadAdresowaniePamieci() {
        showAddresses();
    }

    int Menu() {
        int choice;
        do {
            std::cout << std::endl << "MENU" << std::endl << std::endl;
            std::cout <<"1) Petle" <<
                std::endl <<"2) Parzysta" <<
                std::endl << "3) Przekazywanie Tablic z podaniem rozmiaru" <<
                std::endl << "4) Adresowanie pamieci" <<
                std::endl << "5) Arytmetyka wskaznikow" <<
                std::endl << "6) Wyjdz"
                << std::endl << std::endl;

            std::cin >> choice;
            switch(choice) {
                case 1:
                    zadPetle();
                    break;
                case 2:
                    zadParzysta();
                    break;
                case 3:
                    zadPrzekazywanieTablicZpodaniemRozmiaru();
                    break;
                case 4:
                    zadAdresowaniePamieci();
                    break;
                case 5:
                    zadArytmetykaWskaznikow();
                    break;
                case 6:
                    break;
                default:
                    std::cout << " Nie ma takiej opcji w MENU";
                    break;
            }
        }
        while(choice != 6);
        return 0;
    }
private:
    bool czy_parzysta_modulo(int num);
    void Funkcja1();
    void Funkcja2();
    void Funkcja3();
    void showAddresses();
    void petleFor();
    void petleWhile();
    void petleDoWhile();

    bool czy_parzysta_bit(int num);
    bool czy_parzysta_inna(int num);
    void showIq();
    void przekaz_tablica(int tab[], int size);
    void przekaz_tablica2(int *tab, int size);



};

#include "ZadAdresowaniePamieci.h"
#include "ZadArytmetykaWskaznikow.h"
#include "ZadParzysta.h"
#include "ZadPetle.h"
#include "ZadPrzekazywanieTablicZpodaniemRozmiaru.h"
