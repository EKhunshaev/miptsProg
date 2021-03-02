#include "matrix2D.h"

Matrix2D::Matrix2D() {
    A[0][0] = A[0][1] = A[1][0] = A[1][1] = 0;
}

Matrix2D::Matrix2D(const double &x) {
    A[0][0] = A[0][1] = A[1][0] = A[1][1] = x;
}
Matrix2D::Matrix2D(const double &a11, const double &a12, const double &a21, const double &a22) {
    A[0][0] = a11;
    A[0][1] = a12;
    A[1][0] = a21;
    A[1][1] = a22;
}
//getter setter
double Matrix2D::getEl(const int &i, const int &j) {
    if (i > 0 && i < 3 && j > 0 && j < 3) {
        return A[i-1][j-1];
    } else {
        std::cout << "There is no element A(" << i << ',' << j << ")" << std::endl;
        return 0;
    }
}
void Matrix2D::setA(const double &a11, const double &a12, const double &a21, const double &a22) {
    A[0][0] = a11;
    A[0][1] = a12;
    A[1][0] = a21;
    A[1][1] = a22;
}
//Перегрузка операторов потока
std::ostream &operator<<(std::ostream &out, const Matrix2D &mtx) {
    out << mtx.A[0][0] << ' ' << mtx.A[0][1] << std::endl
        << mtx.A[1][0] << ' ' << mtx.A[1][1];
    return out;
}

std::istream &operator>>(std::istream &in, Matrix2D &mtx) {
    in >> mtx.A[0][0] >> mtx.A[0][1] >> mtx.A[1][0] >> mtx.A[1][1];
    return in;
}
//+ - *
//bin
Matrix2D operator+(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    Matrix2D res(mtx1.A[0][0] + mtx2.A[0][0], mtx1.A[0][1] + mtx2.A[0][1],
                 mtx1.A[1][0] + mtx2.A[1][0], mtx1.A[1][1] + mtx2.A[1][1]);
    return res;
}

Matrix2D operator-(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    Matrix2D res(mtx1.A[0][0] - mtx2.A[0][0], mtx1.A[0][1] - mtx2.A[0][1],
                 mtx1.A[1][0] - mtx2.A[1][0], mtx1.A[1][1] - mtx2.A[1][1]);
    return res;
}

Matrix2D operator*(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    Matrix2D res(mtx1.A[0][0] * mtx2.A[0][0] + mtx1.A[0][1] * mtx2.A[1][0],
                 mtx1.A[0][0] * mtx2.A[0][1] + mtx1.A[0][1] * mtx2.A[1][1],
                 mtx1.A[1][0] * mtx2.A[0][0] + mtx1.A[1][1] * mtx2.A[1][0],
                 mtx1.A[1][0] * mtx2.A[0][1] + mtx1.A[1][1] * mtx2.A[1][1]);
    return res;
}

Matrix2D operator*(const Matrix2D &mtx, const double &N) {
    Matrix2D res(mtx.A[0][0] * N, mtx.A[0][1] * N,
                 mtx.A[1][0] * N, mtx.A[1][1] * N);
    return res;
}

Matrix2D operator*(const double &N, const Matrix2D &mtx) {
    Matrix2D res(mtx.A[0][0] * N, mtx.A[0][1] * N,
                 mtx.A[1][0] * N, mtx.A[1][1] * N);
    return res;
}

Vector2D operator*(const Matrix2D &mtx, Vector2D &V) {
    Vector2D res(mtx.A[0][0] * V.getX() + mtx.A[0][1] * V.getY(),
               mtx.A[1][0] * V.getX() + mtx.A[1][1] * V.getY());
    return res;
}
//un
Matrix2D &operator+(Matrix2D &mtx) {
    return mtx;
}

Matrix2D operator-(const Matrix2D &mtx) {
    return mtx * -1;
}
//++ --
Matrix2D &operator++(Matrix2D &mtx) {
    mtx.A[0][0]++;
    mtx.A[1][1]++;
    return mtx;
}

Matrix2D operator++(Matrix2D &mtx, int) {
    Matrix2D res = mtx;
    mtx.A[0][0]++;
    mtx.A[1][1]++;
    return res;
}
Matrix2D &operator--(Matrix2D &mtx) {
    mtx.A[0][0]--;
    mtx.A[1][1]--;
    return mtx;
}
Matrix2D operator--(Matrix2D &mtx, int) {
    Matrix2D res = mtx;
    mtx.A[0][0]--;
    mtx.A[1][1]--;
    return res;
}
//== (+, -, *)=
Matrix2D &Matrix2D::operator=(const Matrix2D &M) {
    A[0][0] = M.A[0][0];
    A[1][0] = M.A[1][0];
    A[0][1] = M.A[0][1];
    A[1][1] = M.A[1][1];
    return *this;
}
Matrix2D &operator+=(Matrix2D &mtx1, const Matrix2D &mtx2) {
    mtx1 = (mtx1 + mtx2);
    return mtx1;
}
Matrix2D &operator-=(Matrix2D &mtx1, const Matrix2D &mtx2) {
    mtx1 = (mtx1 - mtx2);
    return mtx1;
}
Matrix2D &operator*=(Matrix2D &mtx, const double &N) {
    mtx = mtx * N;
    return mtx;
}
//==, !=, >, <, >=, <= (>< по детерминанту)
bool operator==(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    bool res = mtx1.A[0][0] == mtx2.A[0][0] &&
            mtx1.A[0][1] == mtx2.A[0][1] &&
            mtx1.A[1][0] == mtx2.A[1][0] &&
            mtx1.A[1][1] == mtx2.A[1][1];
    return res;
}

bool operator!=(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    bool res = mtx1.A[0][0] != mtx2.A[0][0] ||
               mtx1.A[0][1] != mtx2.A[0][1] ||
               mtx1.A[1][0] != mtx2.A[1][0] ||
               mtx1.A[1][1] != mtx2.A[1][1];
    return res;
}

bool operator>=(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return ((mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1]) -
            (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1])) >= 0;
}

bool operator<=(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return ((mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1]) -
           (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1])) <= 0;
}

bool operator>(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1] -
           (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1]) > 0;
}

bool operator<(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1] -
           (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1]) <= 0;
}
//&& || !
bool operator&&(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return (mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1]) &&
           (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1]);
}

bool operator||(const Matrix2D &mtx1, const Matrix2D &mtx2) {
    return (mtx1.A[0][0] * mtx1.A[1][1] - mtx1.A[1][0] * mtx1.A[0][1]) ||
           (mtx2.A[0][0] * mtx2.A[1][1] - mtx2.A[1][0] * mtx2.A[0][1]);
}

bool operator!(const Matrix2D &mtx) {
    return !(mtx.A[0][0] * mtx.A[1][1] - mtx.A[1][0] * mtx.A[0][1]);
}