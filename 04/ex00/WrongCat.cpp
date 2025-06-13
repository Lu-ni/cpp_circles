#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
    std::cout << "CREATING A WRONG CATTTTT\n";
    this->type = "WrongCat";
}
WrongCat::~WrongCat() {
    std::cout << "DESTROYING A WRONG CATTTTT\n";
}
void WrongCat::makeSound(void) const {
    std::cout << "         /\\_/\\   ________________\n";
    std::cout << "        / o o \\ /                \\____________\n";
    std::cout << " MIAOU>(  > <  )                  |\n";
    std::cout << "        \\_____/ \\________________/\n";
}
