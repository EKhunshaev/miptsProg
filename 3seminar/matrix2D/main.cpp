#include <iostream>
#include "matrix2D.h"


int main() {
    Matrix2D A;
    Matrix2D B;
    std::cout << "Initialize 2 matrix A and B. Pattern: A11 A12 A21 A22:" << std::endl;
    std::cin >> A >> B;

    std::cout << "A + B = \n" << A + B << std::endl;
    std::cout << "A - B = \n" << A - B << std::endl;
    std::cout << "A * B = \n" << A * B << std::endl;
    std::cout << "A * 4 = \n" << A * 4 << std::endl;

    Vector2D V(7,2);
    std::cout << "A * (7,2) = \n" << A * V << std::endl;

    std::cout << "+A = \n" << +A << std::endl;
    std::cout << "-A = \n" << -A << std::endl;

    std::cout << "++A = \n" << ++A << std::endl;
    std::cout << "A++ = \n" << A++ << std::endl;
    std::cout << "A-- = \n" << A-- << std::endl;
    std::cout << "--A = \n" << --A << std::endl;

    std::cout << "A += B => \n" << (A += B) << std::endl;
    std::cout << "A -= B => \n" << (A -= B) << std::endl;
    std::cout << "A *= 5 => \n" << (A *= 5) << std::endl;

    std::cout << "A == B => " << (A == B) << std::endl;
    std::cout << "A != B => " << (A != B) << std::endl;
    std::cout << "A >= B => " << (A >= B) << std::endl;
    std::cout << "A <= B => " << (A <= B) << std::endl;

    std::cout << "A && B => " << (A && B) << std::endl;
    return 0;
}