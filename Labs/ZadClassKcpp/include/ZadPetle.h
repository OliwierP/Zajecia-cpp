#include <iostream>


void ZadKcpp::petleWhile() {
    int i = 0;
    while (i < 10) {
        std::cout << i++ << std::endl;
        i++;
    }
    i = 0;
    while (i < 10) {
        std::cout << ++i << std::endl;
    }
}

void ZadKcpp::petleDoWhile() {
    int i = 0;
    do {
        std::cout << i++ << std::endl;
    }
    while(i < 10);
    i = 0;
    do {
        std::cout << ++i << std::endl;
    }
    while(i < 10);
}

void ZadKcpp::petleFor() {
    for(int i = 0; i < 10; i++) {
        std::cout << i << std::endl;
    }
    for (int i = 0; i < 10; ++i) {
        std::cout << i << std::endl;
    }
}
