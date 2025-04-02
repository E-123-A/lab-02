#include <iostream>
#include "fraction.h"

int main() {
    Fraction a(3, 4);
    Fraction b(2, 5);

    std::cout << "Fraction A: " << a << std::endl;
    std::cout << "Fraction B: " << b << std::endl;

    std::cout << "A + B = " << (a + b) << std::endl;
    std::cout << "A - B = " << (a - b) << std::endl;
    std::cout << "A * B = " << (a * b) << std::endl;
    std::cout << "A / B = " << (a / b) << std::endl;

    return 0;
}
