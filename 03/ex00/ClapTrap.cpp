#include "ClapTrap.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

ClapTrap::ClapTrap(std::string name) : name_(std::move(name)), hit_point_(10), attack_dmg_(0), energy_point_(10) {
    std::cout << "Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name_(other.name_),
      hit_point_(other.hit_point_),
      attack_dmg_(other.attack_dmg_),
      energy_point_(other.energy_point_) {
    std::cout << "Copy Constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called\n";
    if (this != &other) {  // Protect against self-assignment
        this->name_ = other.name_;
        this->hit_point_ = other.hit_point_;
        this->energy_point_ = other.energy_point_;
        this->attack_dmg_ = other.attack_dmg_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called \n";
}

void ClapTrap::attack(const std::string& target) {
    if (this->energy_point_ <= 0 || this->hit_point_ <= 0) {
        std::cout << "Can't perform action !\n";
        return;
    }
    this->energy_point_--;
    std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->attack_dmg_
              << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    this->hit_point_ -= amount;
    this->hit_point_ = std::max(this->hit_point_, (unsigned int)0);
    std::cout << "ClapTrap " << this->name_ << " took " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_point_ <= 0 || this->hit_point_ <= 0) {
        std::cout << "Can't perform action !\n";
        return;
    }
    std::cout << "ClapTrap " << this->name_ << " is being repared for " << amount << " hit points!\n";
    this->energy_point_--;
    this->hit_point_ += amount;
}
