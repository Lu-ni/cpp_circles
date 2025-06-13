#include "Cat.hpp"

#include <iostream>

#include "Brain.hpp"

Cat::Cat() : brain(new Brain()) {
    std::cout << "CREATING A CATTTTT\n";
    this->type = "Cat";
}
Cat::~Cat() {
    std::cout << "DESTROYING A CATTTTT\n";
    delete this->brain;
}
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        *(this->brain) = *(other.brain);
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "         /\\_/\\   ________________\n";
    std::cout << "        / o o \\ /                \\____________\n";
    std::cout << " MIAOU>(  > <  )                  |\n";
    std::cout << "        \\_____/ \\________________/\n";
}
void Cat::printIdeas(void) const {
    this->brain->printIdeas();
}
