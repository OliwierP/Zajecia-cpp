#include <iostream>


void ZadKcpp::Funkcja1() {

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 8;
    int h = 9;
    int j = 10;


    int *p;
    p = &a;
    printf(" %d\n", *p);
    p++;
    printf("1. %d\n", *p);
    ++p;
    printf("2. %d\n", *p);
    ++*p;
    printf("3. %d\n", *p);
    ++(*p);
    printf("4. %d\n", *p);
    ++*(p);
    printf("5. %d\n", *p);
    *p++;
    printf("6. %d\n", *p);
    (*p)++;
    printf("7. %d\n", *p);
    *(p)++;
    printf("8. %d\n", *p);
    *++p;
    printf("9. %d\n", *p);
    *(++p);
    printf("10. %d\n", *p);
}

void ZadKcpp::Funkcja2() {

    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *p;
    p = tab;
    printf(" %d\n", *p);
    p++;
    printf("1. %d\n", *p);
    ++p;
    printf("2. %d\n", *p);
    ++*p;
    printf("3. %d\n", *p);
    ++(*p);
    printf("4. %d\n", *p);
    ++*(p);
    printf("5. %d\n", *p);
    *p++;
    printf("6. %d\n", *p);
    (*p)++;
    printf("7. %d\n", *p);
    *(p)++;
    printf("8. %d\n", *p);
    *++p;
    printf("9. %d\n", *p);
    *(++p);
    printf("10. %d\n", *p);
}

void ZadKcpp::Funkcja3() {
    int a = 0, b = 0, c = 0;
    printf("%d, %d, %d \n\n", &a, &b, &c);
    std::cout << "Uwaga ponizsze rozwiazanie jest prawidlowe gdy adresy liczb a,b,c poszeregowane sa w następującym porzadku &a > &b > &c" << std::endl << std::endl;

    std::cout << "1. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    int *p;
    p = &b;
    *p = 10;

    std::cout << "2. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *(p - 1) = *p + 10;

    std::cout << "3. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *p = *p + *(p - 1);

    std::cout << "4. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *(p + 1) = *p + *(p - 1) - 10;

    std::cout << "5. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *p += *(p - 1);

    std::cout << "6. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *(&b - 1) += *(&b + 1);

    std::cout << "7. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    *p += 20;

    std::cout << "8. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    //p = p + 1;
    p++;
    *p *= 2;

    std::cout << "9. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

    int *p2 = (p - 1);
    *p2 = 90;

    std::cout << "10. "<< "A, B, C: " << a << " "<< b << " " << c << std::endl;

}
