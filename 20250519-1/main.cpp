#include <iostream>
#include <string>
#include "Rational.h"

using namespace std;

int main() {
    while (true) {
        int n1, d1, n2, d2;
        cout << "\nplease input the two rational number (numerator/denominator) or 'x' to exit: ";

        string temp;
        cin >> temp;
        if (temp == "x" || temp == "X") break;
        n1 = stoi(temp);
        cin >> d1 >> n2 >> d2;

        Rational r1(n1, d1);
        Rational r2(n2, d2);
        Rational result;

        char op;
        cout << "please input the operator (+, -, *, /): ";
        cin >> op;

        switch (op) {
            case '+':
                result = r1.add(r2);
                break;
            case '-':
                result = r1.subtract(r2);
                break;
            case '*':
                result = r1.multiply(r2);
                break;
            case '/':
                result = r1.divide(r2);
                break;
            default:
                cout << "unknown operator!" << endl;
                continue;
        }

        cout << "output format (1: fraction, 2: decimal): ";
        int format;
        cin >> format;
        if (format == 1) {
            cout << "result is: ";
            result.printFraction();
        } else if (format == 2) {
            cout << "result is: ";
            result.printDecimal();
        } else {
            cout << "unknown format!" << endl;
        }
    }
    return 0;
}