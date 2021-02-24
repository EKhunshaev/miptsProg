//Написать класс дробь 4/3
//Упрощение дроби при любом действии 4/2 = 2/1 (отдельный метод)
//Знаменатель != 0
//3 конструктора - по умолчанию - от двух целых чисел числитель/знаменатель - перевод десятичной дроби в обыкновенную (нет периодичных)
//Сделать методы - представляет дробь в десятичном
//метод возвращающий целую часть
//перегрузить операторы +, -, (f * d, f * f, d * f), /, =(int double)
//++ -- += -= *= /=
//==, >, <, !=, <= >=
//<< >>

//class header class.h
#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction
{
private:
    int n, m; //fraction n/m
public:
    //constructors and destructors
    Fraction();
    Fraction(double d);
    Fraction(const int &n, const int &m);
    //getters and seters
    int getN();
    int getM();
    void setN(const int &n);
    void setM(const int &m);
    //methods
    double doubleFraction(); // 1/2 -> 0.5 Возвращение десятичного представления
    int iPart(); //Возвращение целой части 4/3 -> 1
    void simp();
    //<< >>
    friend std::ostream &operator<<(std::ostream &out, const Fraction &F);
    friend std::istream &operator>>(std::istream &in, Fraction &F);

    //+ -
    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);
    Fraction &operator=(double d);
    Fraction &operator=(const int &i);
    //++ -- += -= *= /=
    friend Fraction &operator++(Fraction &f);
    friend Fraction operator++(Fraction &f, int);
    friend Fraction &operator--(Fraction &f);
    friend Fraction operator--(Fraction &f, int);

    friend Fraction &operator+=(Fraction &f1, const Fraction &f2);
    friend Fraction &operator-=(Fraction &f1, const Fraction &f2);
    friend Fraction &operator*=(Fraction &f1, const Fraction &f2);
    friend Fraction &operator/=(Fraction &f1, const Fraction &f2);
    //==, >, <, !=, <= >=
    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator>(const Fraction &f1, const Fraction &f2);
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);
};




#endif

//main.cpp
#include <iostream>
//#include "fraction.h"


int main() {
    //constructors
    Fraction f1;
    std::cout << "Default f1 = " << f1 << std::endl;
    std::cout << "Enter n and m in fraction n/m" << std::endl;
    std::cin >> f1;
    std::cout << "Your number is " << f1 << std::endl;

    Fraction f2(27, 54); //0,5
    Fraction f3(-1.2); // 6/5
    std::cout << "f2(27, 54) and f3(-1.2): f2 = "<< f2 << " f3 = " << f3 << std::endl;

    std::cout << "f3 = " << f3.doubleFraction() << " and its iPart " << f3.iPart() << std::endl;

    std::cout << "f2 + f3 = " << f2 + f3 << std::endl;
    std::cout << "f2 - f3 = " << f2 - f3 << std::endl;
    std::cout << "f2 * f3 = " << f2 * f3 << std::endl;
    std::cout << "f2 * f3.doubleFraction = " << f2 * f3.doubleFraction() << std::endl;
    std::cout << "f2.doubleFraction * f3 = " << f2.doubleFraction() * f3 << std::endl;

    std::cout << "f2 / f3 = " << f2 / f3 << std::endl;

    std::cout << "++f2 = " << ++f2 << std::endl;
    std::cout << "f2++ = " << f2++ << std::endl;
    std::cout << "f2-- = " << f2-- << std::endl;
    std::cout << "--f2 = " << --f2 << std::endl;

    std::cout << "f2 += f3 = " << (f2 += f3) << std::endl;
    std::cout << "f2 -= f3 = " << (f2 -= f3) << std::endl;
    std::cout << "f2 *= f3 = " << (f2 *= f3) << std::endl;
    std::cout << "f2 /= f3 = " << (f2 /= f3) << std::endl;

    std::cout << "f1 == f2 = " << (f1 == f2) << std::endl;
    std::cout << "f1 == f1 = " << (f1 == f1) << std::endl;
    std::cout << "f1 != f2 = " << (f1 != f2) << std::endl;
    std::cout << "f1 != f1 = " << (f1 != f1) << std::endl;
    std::cout << "f1 > f2 = " << (f1 > f2) << std::endl;
    std::cout << "f1 < f2 = " << (f1 < f2) << std::endl;

    return 0;
}


//class.cpp

#include <iostream>
//#include "fraction.h"
#include <algorithm>

//constructors and destructors
Fraction::Fraction() {
    n = 1; m = 1;
}

Fraction::Fraction(double d) {
    int M = 1;
    while((int)d - d != 0) {
        M *= 10;
        d *= 10;
    }
    n = (int)d;
    m = M;
    this->simp();
}

Fraction::Fraction(const int &n, const int &m) {
    if (m == 0) {
        std::cout << "Ошибка: Знаменатель равен 0 в конструкторе;\nДробь = 1" << std::endl;
        this->n = 1; this->m = 1;
    } else {
        this->n = n; this->m = m;
    }
    this->simp();
}
//getters and seters
int Fraction::getN() {
    return n;
}

int Fraction::getM() {
    return m;
}
void Fraction::setN(const int &n) {
    this->n = n;
    this->simp();
}

void Fraction::setM(const int &m) {
    if (m == 0) {
        std::cout << "Ошибка: Знаменатель равен 0 в методе setM; значение m осталось прежним" << std::endl;
    } else {
        this->m = m;
        this->simp();
    }
}
//methods
double Fraction::doubleFraction() {
    return (double)n / m;
}
int Fraction::iPart() {
    return n / m;
}

void Fraction::simp() {
    int k = std::__gcd(n, m);
    n /= k;
    m /= k;

    if (m < 0) {
        n = -n;
        m = -m;
    }
}

//<< >>
std::ostream &operator<<(std::ostream &out, const Fraction &F) {
    out << F.n << "/" << F.m;
    return out;
}
std::istream &operator>>(std::istream &in, Fraction &F) {
    in >> F.n >> F.m;
    F.simp();
    return in;
}

//+ -
Fraction operator+(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.n * f2.m + f2.n * f1.m, f1.m * f2.m);
}

Fraction operator-(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.n * f2.m - f2.n * f1.m, f1.m * f2.m);
}

Fraction operator*(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.n * f2.n, f1.m * f2.m);
}

Fraction operator/(const Fraction &f1, const Fraction &f2) {
    return Fraction(f1.n * f2.m, f1.m * f2.n);
}

Fraction &Fraction::operator=(double d) {
    //double -> fraction
    int M = 1;
    while((int)d - d != 0) {
        M *= 10;
        d *= 10;
    }
    n = (int)d;
    m = M;
    return *this;
}
Fraction &Fraction::operator=(const int &i) {
    n = i;
    m = 1;
    return *this;
}
//++ -- += -= *= /=
Fraction &operator++(Fraction &f) {
    f.n += f.m;
    f.simp();
    return f;
}

Fraction operator++(Fraction &f, int) {
    Fraction res = f;
    f.n += f.m;
    f.simp();
    return res;
}

Fraction &operator--(Fraction &f) {
    f.n -= f.m;
    f.simp();
    return f;
}

Fraction operator--(Fraction &f, int) {
    Fraction res = f;
    f.n -= f.m;
    f.simp();
    return res;
}

Fraction &operator+=(Fraction &f1, const Fraction &f2) {
    f1.n = f1.n * f2.m + f2.n * f1.m;
    f1.m = f1.m * f2.m;
    f1.simp();
    return f1;
}
Fraction &operator-=(Fraction &f1, const Fraction &f2) {
    f1.n = f1.n * f2.m - f2.n * f1.m;
    f1.m = f1.m * f2.m;
    f1.simp();
    return f1;
}
Fraction &operator*=(Fraction &f1, const Fraction &f2) {
    f1.n *= f2.n;
    f1.m *= f2.m;
    f1.simp();
    return f1;
}
Fraction &operator/=(Fraction &f1, const Fraction &f2) {
    f1.n *= f2.m;
    f1.m *= f2.n;
    f1.simp();
    return f1;
}
//==, >, <, !=, <= >=
bool operator==(const Fraction &f1, const Fraction &f2) {
    return f1.n == f2.n && f1.m == f2.m;
}

bool operator>(const Fraction &f1, const Fraction &f2) {
    return f1.n * f2.m > f1.m * f2.n;
}
bool operator<(const Fraction &f1, const Fraction &f2) {
    return f1.n * f2.m < f1.m * f2.n;
}
bool operator>=(const Fraction &f1, const Fraction &f2) {
    return f1.n * f2.m > f1.m * f2.n || f1.n == f2.n && f1.m == f2.m;
}
bool operator<=(const Fraction &f1, const Fraction &f2) {
    return f1.n * f2.m < f1.m * f2.n || f1.n == f2.n && f1.m == f2.m;

}
bool operator!=(const Fraction &f1, const Fraction &f2) {
    return f1.n != f2.n || f1.m != f2.m;
}