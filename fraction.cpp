#include "fraction.h"
#include <numeric>

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero. Setting to 1.\n";
        denominator = 1;
    }
    reduce();
}

void Fraction::reduce() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }
void Fraction::setNumerator(int num) { numerator = num; reduce(); }
void Fraction::setDenominator(int den) {
    if (den == 0) {
        std::cerr << "Error: Denominator cannot be zero.\n";
        return;
    }
    denominator = den;
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        std::cerr << "Error: Division by zero fraction.\n";
        return *this;
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}
