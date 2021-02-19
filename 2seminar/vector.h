#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
private:
    double x, y;
public:
    //Перегрузка методов
    Vector2D();     //Initialize x = y = 0;
    Vector2D(double x);     //Initialize x = y = x
    Vector2D(double x, double y);
    ~Vector2D();
    //Getter and setters
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);

    Vector2D times(double N);   //умножение на число
    double times(Vector2D V);   //скалярное умножение

    Vector2D operator*(double N);
    double operator*(Vector2D V);
    Vector2D operator+(Vector2D V);
    Vector2D operator-(Vector2D V);
    Vector2D operator/(double N);
    double abs();
};

//Перегрузка функций
double sum(double x, double y);
Vector2D *sum(Vector2D *V1, Vector2D *V2);

#endif //VECTOR2D_H
