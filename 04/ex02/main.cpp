#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

void breakLine() {
    std::cout << "\n";
    std::cout << "################################################################################\n";
    std::cout << "\n";
}
int main(void) {
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;  //should not create a leak delete i;
        delete i;  //should not create a leak delete i;
    }
    breakLine();
    {
        const Cat* bob = new Cat();
        const Cat* bob2 = new Cat();
        bob->printIdeas();
        bob2->printIdeas();
        *const_cast<Cat*>(bob) = *bob2;
        bob->printIdeas();
        delete bob;
        delete bob2;
    }
    {
        const Animal* animals[100];
        for (int i = 0; i < 100; i++) {
            std::cout << i << "\n";
            if (i / 50) {
                animals[i] = new Cat();
            } else {
                animals[i] = new Dog();
            }
        }
        for (int i = 0; i < 100; i++) {
            delete animals[i];
        }
    }
    breakLine();
}
