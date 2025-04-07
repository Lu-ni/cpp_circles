#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string zombie_name) : name_(zombie_name) {}
void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..."
              << "\n";
}
Zombie::~Zombie() {
    std::cout << "Destroying :" << name_ << "\n";
}
void Zombie::setName(std::string name) {
    name_ = name;
}
Zombie::Zombie() {}
