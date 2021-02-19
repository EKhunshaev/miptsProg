#include <iostream>
#include <cmath>
#include "complex.h"

//constructors and destructors
Math::Complex::Complex(double a, double b) {
    this->a = a; this->b = b;
}

Math::Complex::~Complex() {
    std::cout << "Complex obj has been deleted: z = " << a << " + i"  << b << '\n';
}
//getters and setter
double Math::Complex::getRe() {
    return a;
}

double Math::Complex::getIm() {
    return b;
}

void Math::Complex::setRe(double a) {
    this->a = a;
}

void Math::Complex::setIm(double b) {
    this->b = b;
}
//operations
double Math::Complex::mod() {
    return sqrt(a*a + b*b);
}

Math::Complex *Math::Complex::sum(Math::Complex *C) {
    return new Math::Complex(a + C->a, b + C->b);
}

Math::Complex *Math::Complex::dif(Math::Complex *C) {
    return new Math::Complex(a - C->a, b - C->b);
}

Math::Complex *Math::Complex::conj() {
    return new Math::Complex(a, -b);
}

Math::Complex *Math::Complex::mul(double N) {
    return new Math::Complex(a * N, b * N);
}

Math::Complex *Math::Complex::mul(Math::Complex *C) {
    return new Math::Complex(a * C->a - b * C->b, a * C->b + C->a * b); //(a + bi)(c + di) = ac - bd + i(ad + cb);
}