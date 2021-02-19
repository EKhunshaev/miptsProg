#ifndef COMPLEX_H
#define COMPLEX_H
namespace Math {
    class Complex
    {
    private:
        double a, b; // z = a + bi;
    public:
        Complex(double a, double b); //constructor
        ~Complex(); //destructor
        //Getters
        double getRe();
        double getIm();
        //Setters
        void setRe(double a);
        void setIm(double b);

        double mod(); //Модуль числа
        Complex *sum(Complex *C); //сумма
        Complex *dif(Complex *C); //разность
        Complex *conj(); //сопряжение
        Complex *mul(double N); //умножение на число
        Complex *mul(Complex *C); //умножение комплексных чисел
    };
}
#endif //COMPLEX_H
