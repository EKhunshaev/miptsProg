#include "matrix2D.h"
#include <iostream>
//constructors & destructors
Matrix2D::Matrix2D() {
    A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0;
}

Matrix2D::Matrix2D(double x) {
    A[0][0] = A[0][1] = A[1][0] = A[1][1] = x;
}

Matrix2D::Matrix2D(double a11, double a12, double a21, double a22) {
    A[0][0] = a11;
    A[0][1] = a12;
    A[1][0] = a21;
    A[1][1] = a22;
}

Matrix2D::~Matrix2D() {
//    std::cout << "Matrix was deleted:\n" << A[0][0] << " " << A[0][1]
//        << std::endl << A[1][0] << " " << A[1][1] << std::endl;
}
//getters and setters
void Matrix2D::setA(double a11, double a12, double a21, double a22) {
    A[0][0] = a11;
    A[0][1] = a12;
    A[1][0] = a21;
    A[1][1] = a22;
}

double Matrix2D::getEl(int i, int j) {
    if (i >= 1 && i <= 2 && j >= 1 && j <= 2) {
        return A[i-1][j-1];
    } else {
        std::cout << "There is no element A(" << i << j << std::endl;
        return 0;
    }
}
//operators

Matrix2D Matrix2D::operator*(double N) {
    Matrix2D res(A[0][0] * N, A[0][1] * N, A[1][0] * N, A[1][1] * N);
    return res;
}

Vector2D Matrix2D::operator*(Vector2D V) {
    Vector2D res(A[0][0] * V.getX() + A[0][1] * V.getY(),
                 A[1][0] * V.getX() + A[1][1] * V.getY());
    return res;
}

Matrix2D Matrix2D::operator*(Matrix2D M) {
    Matrix2D res(A[0][0] * M.getEl(1, 1) + A[0][1] * M.getEl(2,1),       //11
                 A[0][0] * M.getEl(1, 2) + A[0][1] * M.getEl(2,2),       //12
                 A[1][0] * M.getEl(1, 1) + A[1][1] * M.getEl(2,1),       //21
                 A[1][0] * M.getEl(1, 2) + A[1][1] * M.getEl(2,2));     //22
    return res;
}

Matrix2D Matrix2D::operator+(Matrix2D M) {
    Matrix2D res(A[0][0] + M.getEl(1, 1),
                 A[0][1] + M.getEl(1, 2),
                 A[1][0] + M.getEl(2, 1),
                 A[1][1] + M.getEl(2, 2));
    return res;
}

Matrix2D Matrix2D::operator-(Matrix2D M) {
    Matrix2D res(A[0][0] - M.getEl(1, 1),
                 A[0][1] - M.getEl(1, 2),
                 A[1][0] - M.getEl(2, 1),
                 A[1][1] - M.getEl(2, 2));
    return res;
}
//transpose and determinant
Matrix2D Matrix2D::T() {
    Matrix2D res(A[0][0],
                 A[1][0],
                 A[0][1],
                 A[1][1]);
    return res;
}

double Matrix2D::det() {
    return A[0][0] * A[1][1] - A[0][1] * A[1][0];
}
//print func
void Matrix2D::printM() {
    std::cout << A[0][0] << " " << A[0][1]
              << std::endl << A[1][0] << " " << A[1][1] << std::endl;
}