#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
private:
    int numerator;
    int denominator;
    void reduce();

public:
    Rational(int n=0, int d=1);
    
    Rational add(const Rational &r) const;
    Rational subtract(const Rational &r) const;
    Rational multiply(const Rational &r) const;
    Rational divide(const Rational &r) const;

    void printFraction() const;
    void printDecimal() const;
};

#endif
