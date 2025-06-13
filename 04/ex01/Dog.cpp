#include "Dog.hpp"

#include <iostream>

#include "Brain.hpp"

Dog::Dog() : brain(new Brain()) {
    std::cout << "CREATING A DOGGG\n";
    this->type = "Dog";
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "DESTROYING A DOGGG\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        *(this->brain) = *(other.brain);
    }
    return *this;
}
void Dog::makeSound(void) const {
    std::cout << "  / \\__\n";
    std::cout << " (    @\\___\n";
    std::cout << " /         O\n";
    std::cout << "/   (_____/\n";
    std::cout << "/_____/ U   BARKKK!\n";
}
void Dog::printIdeas(void) const {
    this->brain->printIdeas();
}
