#include <iostream>
#include "Rational.h"

using namespace std;

// 建構子
Rational::Rational(int n, int d){
    numerator = n;
    denominator = (d == 0) ? 1 : d; // 避免分母為0
    reduce();
}

// 最大公因數 (輔助函數)
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

void Rational::reduce(){
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    // 確保分母為正數
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// 加法
Rational Rational::add(const Rational &r) const {
    return Rational(numerator * r.denominator + r.numerator * denominator, denominator * r.denominator);
}
// 減法
Rational Rational::subtract(const Rational &r) const {
    return Rational(numerator * r.denominator - r.numerator * denominator, denominator * r.denominator);
}
// 乘法
Rational Rational::multiply(const Rational &r) const {
    return Rational(numerator * r.numerator, denominator * r.denominator);
}
// 除法
Rational Rational::divide(const Rational &r) const {
    return Rational(numerator * r.denominator, denominator * r.numerator);
}

// 輸出分數
void Rational::printFraction() const {
    cout << numerator << "/" << denominator;
}

// 輸出小數
void Rational::printDecimal() const {
    cout << (double)numerator / denominator;
}