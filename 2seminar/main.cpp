#include <iostream>
#include "vector.h"


int main() {
    Vector2D v0;
    std::cout << "default constructor:(" << v0.getX() << "," << v0.getY() << ")\n";

    Vector2D v1(5);
    Vector2D v2(-2, 6);
    std::cout << "Vectors (" << v1.getX() << "," << v1.getY() << ") and ("
        << v2.getX() << "," << v2.getY() << ") were created\n";

    v1.setX(4); v1.setY(-10);
    std::cout << "Vector v1 were changed (" << v1.getX() << "," << v1.getY() << ")\n";

    Vector2D v3 = v1.times(7);
    std::cout << "v1 times 7 = (" << v3.getX() << "," << v3.getY() << ")\n";

    Vector2D v4 = v1 * 7;
    std::cout << "v1 * 7 = (" << v4.getX() << "," << v4.getY() << ")\n";

    std::cout << "times (v1, v2) = " << v1.times(v2) << std::endl;
    std::cout << "* (v1, v2) = " << v1 * v2 << std::endl;

    Vector2D v5 = v1 + v2;
    std::cout << "v1 + v2 = (" << v5.getX() << "," << v5.getY() << ")\n";
    Vector2D v6 = v1 - v2;
    std::cout << "v1 - v2 = (" << v6.getX() << "," << v6.getY() << ")\n";
    Vector2D v7 = v1 / 5;
    std::cout << "v1 / 5 = (" << v7.getX() << "," << v7.getY() << ")\n";

    std::cout << "abs(v1) = " << v1.abs() << std::endl;

    return 0;
}