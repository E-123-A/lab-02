#include "fraction.h"
#include <iostream>
#include <numeric>

void Fraction::simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

void Fraction::setNumerator(int num) { numerator = num; simplify(); }
void Fraction::setDenominator(int den) {
    if (den == 0) throw std::invalid_argument("Denominator cannot be zero.");
    denominator = den;
    simplify();
}
int Fraction::getNumerator() const { return numerator; }
int Fraction::getDenominator() const { return denominator; }

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) throw std::domain_error("Division by zero.");
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}
bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}
bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    if (fraction.denominator == 1) {
        os << fraction.numerator;
    } else {
        os << fraction.numerator << "/" << fraction.denominator;
    }
    return os;
}

Fraction::operator double() const {
    return static_cast<double>(numerator) / denominator;
}
Fraction::operator int() const {
    return numerator / denominator;
}
