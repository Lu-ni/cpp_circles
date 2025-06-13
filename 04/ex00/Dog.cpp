#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
    std::cout << "CREATING A DOGGG\n";
    this->type = "Dog";
}
Dog::~Dog() {
    std::cout << "DESTROYING A DOGGG\n";
}
void Dog::makeSound(void) const {
    std::cout << "  / \\__\n";
    std::cout << " (    @\\___\n";
    std::cout << " /         O\n";
    std::cout << "/   (_____/\n";
    std::cout << "/_____/ U   BARKKK!\n";
}
