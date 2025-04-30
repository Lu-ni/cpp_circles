#include "HumanB.hpp"

#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {}

void HumanB::attack(void) {
    if (HumanB::weapon_ == nullptr)
        std::cout << HumanB::name_ << " attacks with their their bare hand... Give him a weapon god damnit !"
                  << "\n";
    else {
        std::cout << HumanB::name_ << " attacks with their " << HumanB::weapon_->getType() << "\n";
    }
}

void HumanB::setWeapon(Weapon& weapon) {
    HumanB::weapon_ = &weapon;
}
