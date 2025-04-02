#include <iostream>
#include "fraction.h"

int main() {
    Fraction f1(3, 4);
    Fraction f2(1, 2);
    Fraction f3 = f1 + f2;
    Fraction f4 = f1 - f2;
    Fraction f5 = f1 * f2;
    Fraction f6 = f1 / f2;

    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "f1 + f2: " << f3 << std::endl;
    std::cout << "f1 - f2: " << f4 << std::endl;
    std::cout << "f1 * f2: " << f5 << std::endl;
    std::cout << "f1 / f2: " << f6 << std::endl;

    std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
    std::cout << "f1 != f2: " << (f1 != f2) << std::endl;
    std::cout << "f1 < f2: " << (f1 < f2) << std::endl;
    std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
    std::cout << "f1 <= f2: " << (f1 <= f2) << std::endl;
    std::cout << "f1 >= f2: " << (f1 >= f2) << std::endl;

    double d = f1;
    int i = static_cast<int>(f1);

    std::cout << "Double: " << d << std::endl;
    std::cout << "Integer: " << i << std::endl;

    return 0;
}
