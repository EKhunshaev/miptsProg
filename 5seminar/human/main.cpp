#include <iostream>
#include "human.h"

int main() {
    Human h("Козлова София Александровна", 10);
    std::cout << h.getName() << " " << h.getAge() << std::endl;

    Student s("Андреев Тимофей Викторович", 22, 4);
    std::cout << s.getName() << " " << s.getAge() << " " << s.getScore() << std::endl;

    Teacher t("Иванов Алексей Дмитриевич", 25, 40000);
    std::cout << t.getName() << " " << t.getAge() << " " << t.getSalary() << std::endl;

    return 0;
}
