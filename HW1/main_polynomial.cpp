#include <iostream>

#include "Polynomial.hpp"

int main() {
    Polynomial p1("(3)x^2 + (-1)x^2 + (4)x^5 + (7)x^3");
    Polynomial p2("(4)x^4 + (3)x^3 + (2)x^2 + (1)x^1");
    Polynomial p3;
    p1.printPolynomial();

    p1.simplifyByExponents();

    p1.printPolynomial();

    p3 = p1+p2;

    p3.printPolynomial();



    return 0;
}
