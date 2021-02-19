#include <iostream>
#include <cmath>
#include "vector.h"

//constructors and destructor
Vector2D::Vector2D() {
    x = 0; y = 0;
}

Vector2D::Vector2D(double x) {
    this->x = x; y = x;
}

Vector2D::Vector2D(double x, double y) {
    this->x = x; this->y = y;
}

Vector2D::~Vector2D() {
    //std::cout << "Vector (" << x << ',' << y << ") was deleted\n";
}
//Getters&Setters
double Vector2D::getX() {
    return x;
}

double Vector2D::getY() {
    return y;
}
void Vector2D::setX(double x) {
    this->x = x;
}
void Vector2D::setY(double y) {
    this->y = y;
}
//times - умножение на число и скалярное умножение
Vector2D Vector2D::times(double N) {
    Vector2D res(x * N, y * N);
    return res;
}

double Vector2D::times(Vector2D V) {
    return x * V.getX() + y * V.getY();
}

//* + - / abs
Vector2D Vector2D::operator*(double N) {
    Vector2D res(x * N, y * N);
    return res;
}

double Vector2D::operator*(Vector2D V) {
    return x * V.getX() + y * V.getY();
}

Vector2D Vector2D::operator+(Vector2D V) {
    Vector2D res(x + V.getX(), y + V.getY());
    return res;
}
Vector2D Vector2D::operator-(Vector2D V) {
    Vector2D res(x - V.getX(), y - V.getY());
    return res;
}
Vector2D Vector2D::operator/(double N) {
    Vector2D res(x / N, y / N);
    return res;
}

double Vector2D::abs() {
    return sqrt(x * x + y * y);
}

//double sum and Vector2D sum
double sum(double x, double y) {
    return x + y;
}

Vector2D sum(Vector2D V1, Vector2D V2) {
    Vector2D res(V1.getX() + V2.getX(), V1.getY() + V2.getY());
    return res;
}