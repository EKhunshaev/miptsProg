#ifndef MATRIX2D_H
#define MATRIX2D_H
#include <iostream>
#include "../vector2D/vector2D.h"

class Matrix2D {
private:
    double A[2][2];
public:
    //constructors
    Matrix2D();
    Matrix2D(const double &x);
    Matrix2D(const double &a11, const double &a12, const double &a21, const double &a22);
    //getter setter
    double getEl(const int &i, const int &j);
    void setA(const double &a11, const double &a12, const double &a21, const double &a22);
    //Перегрузка операторов потока
    friend std::ostream &operator<<(std::ostream &out, const Matrix2D &mtx);
    friend std::istream &operator>>(std::istream &in, Matrix2D &mtx);
    //+ - *
    //bin
    friend Matrix2D operator+(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend Matrix2D operator-(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend Matrix2D operator*(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend Matrix2D operator*(const Matrix2D &mtx, const double &N);
    friend Matrix2D operator*(const double &N, const Matrix2D &mtx);
    friend Vector2D operator*(const Matrix2D &mtx, Vector2D &V);
    //un
    friend Matrix2D &operator+(Matrix2D &mtx);
    friend Matrix2D operator-(const Matrix2D &mtx);
    //++ --
    friend Matrix2D &operator++(Matrix2D &mtx);
    friend Matrix2D operator++(Matrix2D &mtx, int);
    friend Matrix2D &operator--(Matrix2D &mtx);
    friend Matrix2D operator--(Matrix2D &mtx, int);
    //== (+, -, *)=
    Matrix2D &operator=(const Matrix2D &M);
    friend Matrix2D &operator+=(Matrix2D &mtx1, const Matrix2D &mtx2);
    friend Matrix2D &operator-=(Matrix2D &mtx1, const Matrix2D &mtx2);
    friend Matrix2D &operator*=(Matrix2D &mtx, const double &N);
    //==, !=, >, <, >=, <= (>< по детерминанту)
    friend bool operator==(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator!=(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator>=(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator<=(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator>(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator<(const Matrix2D &mtx1, const Matrix2D &mtx2);
    //&& || !
    friend bool operator&&(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator||(const Matrix2D &mtx1, const Matrix2D &mtx2);
    friend bool operator!(const Matrix2D &mtx);
};

#endif //MATRIX2D_H
