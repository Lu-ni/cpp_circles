#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Constructing Animal\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Copy-constructing Animal of type: " << this->type << ".\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Assigning data from another " << other.type << " to this " << this->type << ".\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "DESTROYING Animal\n";
}

std::string Animal::getType() const {
    return this->type;
}
