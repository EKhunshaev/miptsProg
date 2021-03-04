#include "human.h"

Human::Human() {
    name = "";
    age = 0;
}

Human::Human(const std::string &name, const int &age) {
    this->name = name;
    this->age = age;
}

std::string Human::getName() {
    return name;
}

int Human::getAge() {
    return age;
}

void Human::setName(const std::string &name) {
    this->name = name;
}

void Human::setAge(const int &age) {
    this->age = age;
}

Student::Student():Human() {
    score = 0;
}

Student::Student(const std::string &name, const int &age, const double &score):Human(name, age) {
    this->score = score;
}

double Student::getScore() {
    return score;
}
void Student::setScore(const double &score) {
    this->score = score;
}

Teacher::Teacher():Human() {
    salary = 0;
}

Teacher::Teacher(const std::string &name, const int &age, const double &salary):Human(name, age) {
    this->salary = salary;
}

double Teacher::getSalary() {
    return salary;
}

void Teacher::setSalary(const double &salary) {
    this->salary = salary;
}
