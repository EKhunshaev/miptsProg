#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
class Vector2D {
    double x, y;
public:
    Vector2D();
    Vector2D(const double &x, const double &y);

    double getX();
    double getY();
    void setX(const double &x);
    void setY(const double &y);
    //перегрузка операторов направления потока << >>
    friend std::ostream &operator<<(std::ostream &out, const Vector2D &V);
    friend std::istream &operator>>(std::istream &in, Vector2D &V);
    //+ - *
    friend Vector2D operator+(const Vector2D &V1, const Vector2D &V2);
    friend Vector2D &operator+(const Vector2D &V);
    friend Vector2D operator-(const Vector2D &V1, const Vector2D &V2);
    friend Vector2D operator-(const Vector2D &V);
    friend Vector2D operator*(const Vector2D &V, const double &N);
    friend Vector2D operator*(const double &N, const Vector2D &V);
    friend double operator*(const Vector2D &V1, const Vector2D &V2);
    // ++ --
    friend Vector2D &operator++(Vector2D &V);
    friend Vector2D operator++(Vector2D &V, int);
    friend Vector2D &operator--(Vector2D &V);
    friend Vector2D operator--(Vector2D &V, int);
    // == (+, -, *)=
    Vector2D &operator=(const Vector2D &V);
    friend Vector2D &operator+=(Vector2D &V1, const Vector2D &V2);
    friend Vector2D &operator-=(Vector2D &V1, const Vector2D &V2);
    friend Vector2D &operator*=(Vector2D &V, const double &N);
    //== != < > <= >=
    friend bool operator==(const Vector2D &V1, const Vector2D &V2);
    friend bool operator!=(const Vector2D &V1, const Vector2D &V2);
    friend bool operator>(const Vector2D &V1, const Vector2D &V2);
    friend bool operator<(const Vector2D &V1, const Vector2D &V2);
    friend bool operator>=(const Vector2D &V1, const Vector2D &V2);
    friend bool operator<=(const Vector2D &V1, const Vector2D &V2);
    //&& || !
    friend bool operator&&(const Vector2D &V1, const Vector2D &V2);
    friend bool operator||(const Vector2D &V1, const Vector2D &V2);
    friend bool operator!(const Vector2D &V);
};
#endif //VECTOR2D_H
