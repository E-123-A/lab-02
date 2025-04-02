#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce();

public:
    Fraction(int num = 0, int den = 1);

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int num);
    void setDenominator(int den);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};

#endif // FRACTION_H
