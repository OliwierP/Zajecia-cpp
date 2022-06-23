#include <iostream>


bool ZadKcpp::czy_parzysta_modulo(int num) {

    return !(num % 2);

}

bool ZadKcpp::czy_parzysta_bit(int num) {

    num = num & 0;
    return num;

}

bool ZadKcpp::czy_parzysta_inna(int num) {


    bool result = (num % 2? 1: 0);
    result = !result;
    return result;
}
