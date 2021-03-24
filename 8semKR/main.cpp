//1 Задача
 /* IIV реализовать класс Время ЧЧ:ММ. Минут 0-59.Часы тоже неограниченны
 * Конструктор по умолчанию и от 2х аргументов, геттеры сеттеры, Метод приводящий к правильному формату
 * Оператор +, -
 *
 */
/* 2 Задача - наследование
 * IIV отнаследоать HH:MM:SS
 * Конструкторы, геттеры сеттеры, метод к формату
 * + - для класса
 */
/* 3 Задача
 * Реализовать шаблон класса занятие
 * Дата или время (от варианта) в качестве шаблонной переменной (часы минуты, часы минуты секунды, трейтье время минуты инт или дабл)
 * Динамический массив std::string с именами учеников на занятии (можно динамически или через вектор)
 * + - операторы времени Занятие C = A + B
 * B - время A - занятие
 * 2 конструктора, геттеры сеттеры
 * Метод добавления студента
 * Исключение при слишком большом имени студента (20 символов)
 */
//2 вариант

#include <iostream>
#include <string>
#include <vector>
// Задание 1 Класс времени Часы:Минуты
class HhMm
{
protected:
    int h, m;
    void simp(); //упрощает время
public:
    HhMm();
    HhMm(const int &h, const int &m);

    int getH();
    int getM();

    void setH(const int &h);
    void setM(const int &m);

    friend HhMm operator+(const HhMm &t1, const HhMm &t2);
    friend HhMm operator-(const HhMm &t1, const HhMm &t2);
};

// Задание 2 - класс Часы:Минуты:Секунды
class HhMmSs:public HhMm
{
protected:
    int s;
    void simp();
public:
    HhMmSs();
    HhMmSs(const int &h, const int &m, const int &s);

    void setS(const int &s);
    int getS();

    friend HhMmSs operator+(const HhMmSs &t1, const HhMmSs &t2);
    friend HhMmSs operator-(const HhMmSs &t1, const HhMmSs &t2);
};

//Задание 3
template <typename T>
class Para
{
protected:
    T time;
    std::vector<std::string> students;
public:
    Para();
    Para(const T &t, const std::vector<std::string> list);

    T getTime();
    std::vector<std::string> getStudents();

    void setTime(const T &t); //Меняет время
    void setStudents(const std::vector<std::string> &list); //Очищает вектор students и записывает новый

    void addStudent(const std::string &name); //Добавляет студента

    template <typename T1>
    friend Para<T1> operator+(const Para<T1> &p, const T1 &t);
    template <typename T1>
    friend Para<T1> operator-(const Para<T1> &p, const T1 &t);
};

int main() {
    //Задание 1 тесты
    std::cout << "----Тесты задания 1----" << std::endl;
    HhMm t1(0, -171);
    HhMm t2(17, 59);
    std::cout << "2 HhMm was created: " << t1.getH() << ": " << t1.getM() << std::endl;
    std::cout << t2.getH() << ":" << t2.getM() << std::endl;

    HhMm t3 = t1 + t2;
    std::cout << "t1 + t2 = " << t3.getH() << ":" << t3.getM() << std::endl;
    t3 = t1 - t2;
    std::cout << "t1 - t2 = " << t3.getH() << ":" << t3.getM() << std::endl;
    std::cout << "----конец тестов задания 1----" << std::endl;

    //Задание 2 тесты
    std::cout << "----Тесты задания 2----" << std::endl;
    HhMmSs h1(0, -171, 29848);
    HhMmSs h2(17, 59, -293);
    std::cout << "2 HhMmSs was created: " << h1.getH() << ":" << h1.getM() << ":" << h1.getS() << std::endl;
    std::cout << h2.getH() << ":" << h2.getM() << ":" << h2.getS() << std::endl;

    HhMmSs h3 = h1 + h2;
    std::cout << "h1 + h2 = " << h3.getH() << ":" << h3.getM() << ":" << h3.getS() << std::endl;
    h3 = h1 - h2;
    std::cout << "h1 + h2 = " << h3.getH() << ":" << h3.getM() << ":" << h3.getS() << std::endl;
    std::cout << "----конец тестов задания 2----" << std::endl;

    std::cout << "----Тесты задания 3----" << std::endl;

    Para<HhMm> p(t1, {"Sasha", "Misha", "AAAAAAAAAA BBBBBBBBB CCCCCCCC"});
    HhMm timeC = p.getTime();
    std::vector<std::string> studC = p.getStudents();

    std::cout << timeC.getH() << ":" << timeC.getM() << std::endl;
    for (auto &student : studC) {
        std::cout << student << " ";
    }
    std::cout << std::endl;

    p.addStudent("Ivanov Ivan Ivanovich-Fedorovich");
    studC = p.getStudents();
    for (auto &student : studC) {
        std::cout << student << " ";
    }
    std::cout << std::endl;
    Para<HhMm> p1 = p + t2;
    timeC = p1.getTime();
    std::cout << timeC.getH() << ":" << timeC.getM() << std::endl;

    std::cout << "----конец тестов задания 3----" << std::endl;

    return 0;
}

//Задание 1 - Класс времени Часы:Минуты
void HhMm::simp() {
    if (m >= 0) {
        h += m / 60;
        m %= 60;
    } else { // Минуты не могут быть меньше -60 при операциях + - с двумя временами
        h += (m / 60 - 1);
        m = m % 60 + 60;
    }
}

HhMm::HhMm() {
    h = 0; m = 0;
}

HhMm::HhMm(const int &h, const int &m) {
    this->h = h; this->m = m;
    simp();
}

int HhMm::getH() {
    return h;
}

int HhMm::getM() {
    return m;
}

void HhMm::setH(const int &h) {
    this->h = h;
}

void HhMm::setM(const int &m) {
    this->m = m;
    simp();
}

HhMm operator+(const HhMm &t1, const HhMm &t2) {
    return HhMm(t1.h + t2.h, t1.m + t2.m);
}

HhMm operator-(const HhMm &t1, const HhMm &t2) {
    return HhMm(t1.h - t2.h, t1.m - t2.m);
}
//2 Задание - наследование от Часы:Минуты -> Часы:Минуты:Секунды
void HhMmSs::simp() {
    if (s >= 0) {
        m += s / 60;
        s %= 60;
    } else {
        m += (s / 60 - 1);
        s = (s % 60 + 60);
    }

    if (m >= 0) {
        h += m / 60;
        m %= 60;
    } else {
        h += (m / 60 - 1);
        m = (m % 60 + 60);
    }
}

HhMmSs::HhMmSs():HhMm() {
    s = 0;
}

HhMmSs::HhMmSs(const int &h, const int &m, const int &s):HhMm(h, m) {
    this->s = s;
    simp();
}

void HhMmSs::setS(const int &s) {
    this->s = s;
    simp();
}
int HhMmSs::getS() {
    return s;
}

HhMmSs operator+(const HhMmSs &t1, const HhMmSs &t2) {
    return HhMmSs(t1.h + t2.h, t1.m + t2.m, t1.s + t2.s);
}

HhMmSs operator-(const HhMmSs &t1, const HhMmSs &t2) {
    return HhMmSs(t1.h - t2.h, t1.m - t2.m, t1.s - t2.s);
}

//3 Задание
template <typename T>
Para<T>::Para() {
    time = T(); //default constructor of T class
    students.clear();
}

template <typename T>
Para<T>::Para(const T &t, const std::vector<std::string> list) {
    time = t;
    for (auto &student : list) {
        addStudent(student);
    }
}

template <typename T>
T Para<T>::getTime() {
    return time;
}

template <typename T>
std::vector<std::string> Para<T>::getStudents() {
    return students;
}

template <typename T>
void Para<T>::setTime(const T &t) {
    time = t;
}

template <typename T>
void Para<T>::setStudents(const std::vector<std::string> &list) {
    for (auto &student : list) {
        addStudent(student);
    }
}

template <typename T>
void Para<T>::addStudent(const std::string &name) {
    try {
        if (name.length() > 20) {
            throw "Длина имени " + name + " превышает 20 символов! Обрезание строки до 20 символов";
        } else {
            students.push_back(name);
        }
    } catch(const std::string &er) {
        std::cout << "Обработка исключения: " << er << std::endl;
        students.push_back(name.substr(0, 20));
    }
}

template <typename T>
Para<T> operator+(const Para<T> &p, const T &t) {
    return Para<T>(p.time + t, p.students);
}

template <typename T>
Para<T> operator-(const Para<T> &p, const T &t) {
    return Para<T>(p.time - t, p.students);
}