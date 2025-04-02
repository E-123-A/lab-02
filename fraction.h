#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Fraction(int num = 0, int den = 1);

    void setNumerator(int num);
    void setDenominator(int den);
    int getNumerator() const;
    int getDenominator() const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

    operator double() const;
    explicit operator int() const;
};

#endif // FRACTION_H
