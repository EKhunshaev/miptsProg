#ifndef HUMAN_H
#define HUMAN_H

#include <string>

class Human
{
protected:
    std::string name;
    int age;
public:
    Human();
    Human(const std::string &name, const int &age);

    std::string getName();
    int getAge();
    void setName(const std::string &name);
    void setAge(const int &age);
};

class Student:public Human
{
protected:
    double score;
public:
    Student();
    Student(const std::string &name, const int &age, const double &score);

    double getScore();
    void setScore(const double &score);
};

class Teacher:public Human
{
protected:
    double salary;
public:
    Teacher();
    Teacher(const std::string &name, const int &age, const double &salary);

    double getSalary();
    void setSalary(const double &salary);
};



#endif //HUMAN_H
