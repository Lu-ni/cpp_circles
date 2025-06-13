#include "Cat.hpp"

#include <iostream>

Cat::Cat() {
    std::cout << "CREATING A CATTTTT\n";
    this->type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Copy-constructing Cat\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Assigning Cat\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "DESTROYING A CATTTTT\n";
}
void Cat::makeSound(void) const {
    std::cout << "         /\\_/\\   ________________\n";
    std::cout << "        / o o \\ /                \\____________\n";
    std::cout << " MIAOU>(  > <  )                  |\n";
    std::cout << "        \\_____/ \\________________/\n";
}
