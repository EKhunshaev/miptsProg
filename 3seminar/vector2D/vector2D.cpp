#include "vector2D.h"
#include <cmath>
//constructors
Vector2D::Vector2D() {
    x = 0; y = 0;
}

Vector2D::Vector2D(const double &x, const double &y) {
    this->x = x; this->y = y;
}
//getters and setters
double Vector2D::getX() {
    return x;
}

double Vector2D::getY() {
    return y;
}

void Vector2D::setX(const double &x) {
    this->x = x;
}

void Vector2D::setY(const double &y) {
    this->y = y;
}

// << >>
std::ostream &operator<<(std::ostream &out, const Vector2D &V) {
    out << '(' << V.x << ',' << V.y << ')';
    return out;
}

std::istream &operator>>(std::istream &in, Vector2D &V) {
    in >> V.x >> V.y;
    return in;
}

// + - *
Vector2D operator+(const Vector2D &V1, const Vector2D &V2) {
    return Vector2D(V1.x + V2.x, V1.y + V2.y);
}

Vector2D &operator+(const Vector2D &V) {
    return V;
}

Vector2D operator-(const Vector2D &V1, const Vector2D &V2) {
    return Vector2D(V1.x - V2.x, V1.y - V2.y);
}

Vector2D operator-(const Vector2D &V) {
    return Vector2D(-V.x, -V.y);
}

Vector2D operator*(const Vector2D &V, const double &N) {
    return Vector2D(V.x * N, V.y * N);
}

Vector2D operator*(const double &N, const Vector2D &V) {
    return Vector2D(V.x * N, V.y * N);
}

double operator*(const Vector2D &V1, const Vector2D &V2) {
    return V1.x * V2.x + V1.y * V2.y;
}

//++ --
Vector2D &operator++(Vector2D &V) {
    ++V.x;
    ++V.y;
    return V;
}

Vector2D operator++(Vector2D &V, int) {
    Vector2D res = V;
    V.x++;
    V.y++;
    return res;
}

Vector2D &operator--(Vector2D &V) {
    --V.x;
    --V.y;
    return V;
}

Vector2D operator--(Vector2D &V, int) {
    Vector2D res = V;
    V.x--;
    V.y--;
    return res;
}
//= += -= *=
Vector2D &Vector2D::operator=(const Vector2D &V) {
    x = V.x; y = V.y;
    return *this;
}

Vector2D &operator+=(Vector2D &V1, const Vector2D &V2) {
    V1.x += V2.x;
    V1.y += V2.y;
    return V1;
}

Vector2D &operator-=(Vector2D &V1, const Vector2D &V2) {
    V1.x -= V2.x;
    V1.y -= V2.y;
    return V1;
}

Vector2D &operator*=(Vector2D &V, const double &N) {
    V.x *= N;
    V.y *= N;
    return V;
}
//== != > <= <=
bool operator==(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x == V2.x && V1.y == V2.y);
}

bool operator!=(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x != V2.x || V1.y != V2.y);
}

bool operator>(const Vector2D &V1, const Vector2D &V2) { //в сравнениях по сумма координт
    return (V1.x + V1.y) > (V2.x + V2.y);
}

bool operator<(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x + V1.y) < (V2.x + V2.y);
}

bool operator>=(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x + V1.y) >= (V2.x + V2.y);
}

bool operator<=(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x + V1.y) <= (V2.x + V2.y);
}

friend bool operator&&(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x * V1.x + V1.y * V1.y) && (V2.x * V2.x + V2.y * V2.y);
}

friend bool operator||(const Vector2D &V1, const Vector2D &V2) {
    return (V1.x * V1.x + V1.y * V1.y) || (V2.x * V2.x + V2.y * V2.y);
}

friend bool operator!(const Vector2D &V) {
    return (V.x * V.x + V.y * V.y) == 0;
}