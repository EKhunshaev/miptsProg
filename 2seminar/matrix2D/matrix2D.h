#ifndef _MATRIX2D_H
#define _MATRIX2D_H
#include "../vector2D/vector.h"
class Matrix2D
{
private:
    double A[2][2];
public:
    //constructors and destructors
    Matrix2D();
    Matrix2D(double x);
    Matrix2D(double a11, double a12, double a21, double a22);
    ~Matrix2D();
    //getters setters
    void setA(double a11, double a12, double a21, double a22);
    double getEl(int i, int j);
    //algebraic operations
    Matrix2D operator*(double N);
    Vector2D operator*(Vector2D V);

    Matrix2D operator*(Matrix2D M);
    Matrix2D operator+(Matrix2D M);
    Matrix2D operator-(Matrix2D M);

    Matrix2D T();   //transpose
    double det();   //determinant

    void printM();
};

#endif //_MATRIX2D_H
