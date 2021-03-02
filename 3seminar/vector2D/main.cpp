#include <iostream>
#include "vector2D.h"

int main() {
    Vector2D V1;
    Vector2D V2;
    std::cout << "Enter 2 vectors' coordinates" << std::endl;
    std::cin >> V1 >> V2;
    std::cout << "You enter 2 vectors:" << V1 << " " << V2 << std::endl;

    std::cout << "V1 + V2 = " << V1 + V2 << std::endl;
    std::cout << "+V1 = " << +V1 << std::endl;
    std::cout << "V1 - V2 = " << V1 - V2 << std::endl;
    std::cout << "-V1 = " << -V1 << std::endl;
    std::cout << "V1 * V2 = " << V1 * V2 << std::endl;
    std::cout << "V1 * 5 = " << V1 * 5 << std::endl;
    std::cout << "3 * V1 = " << 3 * V1 << std::endl;

    std::cout << "++V1 = " << ++V1 << std::endl;
    std::cout << "V1++ = " << V1++ << std::endl;
    std::cout << "V1-- = " << V1-- << std::endl;
    std::cout << "--V1 =" << --V1 << std::endl;

    Vector2D V3;
    std::cout << "V3 = V1 => " << (V3 = V1) << std::endl;
    std::cout << "V3 += V2 => " << (V3 += V2) << std::endl;
    std::cout << "V3 -= V2 =>" << (V3 -= V2) << std::endl;
    std::cout << "V3 *= 3 =>" << (V3 *= 3) << std::endl;

    std::cout << "V1 == V3 => " << (V1 == V3) << std::endl;
    std::cout << "V1 * 3 == V3 => " << (V1 * 3 == V3) << std::endl;
    Vector2D V0;
    std::cout << "V1 && (0,0) => " << (V1 && V0) << std::endl;
    std::cout << "V1 || (0,0) => " << (V1 || V0) << std::endl;
    std::cout << "!V1 => " << !V1 << std::endl;

    return 0;
}