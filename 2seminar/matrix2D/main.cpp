#include <iostream>
#include "matrix2D.h"


int main() {
    Matrix2D mtx1;
    std::cout << "default matrix was created:\n";
    mtx1.printM();

    Matrix2D mtx2(1, 2 ,3 ,4);
    std::cout << "mtx2 was created\n";
    mtx2.printM();

    mtx1.setA(3, 5, 2 ,-1);
    std::cout << "mtx1 were changed\n";
    mtx1.printM();

    Matrix2D mtx3 = mtx2 * 2;
    std::cout << "mtx2 * 2 = \n";
    mtx3.printM();

    Vector2D v1(1, 2);
    std::cout << "v1 was created: (" << v1.getX() << "," << v1.getY() << ")\n";
    Vector2D v2 = mtx2 * v1;
    std::cout << "mtx2 * v2 = (" <<  v2.getX() << "," << v2.getY() << ")\n";

    mtx3 = mtx1 + mtx2;
    std::cout << "mtx1 + mtx2 =\n";
    mtx3.printM();

    mtx3 = mtx1 - mtx2;
    std::cout << "mtx1 - mtx2 =\n";
    mtx3.printM();

    mtx3 = mtx1 * mtx2;
    std::cout << "mtx1 * mtx2 =\n";
    mtx3.printM();

    std::cout << "mtx3 determinant" << mtx3.det() << std::endl;
    mtx3 = mtx1.T();
    std::cout << "mtx1T =\n";
    mtx3.printM();


    return 0;
}