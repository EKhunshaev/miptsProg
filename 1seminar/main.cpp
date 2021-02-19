#include <iostream>
#include "complex.h"

int main() {
    Math::Complex *z1 = new Math::Complex(3, 5);
    Math::Complex *z2 = new Math::Complex(7, -21);
    std::cout << "Created:(" << z1->getRe() << "," << z1->getIm() << ") and ("
        << z2->getRe() << "," << z2->getIm() << ")\n";
    Math::Complex *z3 = z1->sum(z2);
    std::cout << "Sum:(" << z3->getRe() << "," << z3->getIm() << ")\n";

    Math::Complex *z4 = z1->dif(z2);
    std::cout << "Dif:(" << z4->getRe() << "," << z4->getIm() << ")\n";

    Math::Complex *z5 = z1->conj();
    std::cout << "Conj z1:(" << z5->getRe() << "," << z5->getIm() << ")\n";

    Math::Complex *z6 = z1->mul(5);
    std::cout << "z1 mul 5:(" << z6->getRe() << "," << z6->getIm() << ")\n";

    Math::Complex *z7 = z1->mul(z2);
    std::cout << "z1 mul z2:(" << z7->getRe() << "," << z7->getIm() << ")\n";

    std::cout << "mod of z1:" << z1->mod() << "\n";

    Math::Complex *pointers[] = {z1, z2, z3, z4, z5, z6, z7};
    for (Math::Complex *pointer : pointers) {
        delete pointer;
    }
    return 0;
}