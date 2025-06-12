/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:55:36 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/12 13:55:36 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->hit_point_ = 100;
    this->energy_point_ = 100;
    this->attack_dmg_ = 30;

    std::cout << "FragTrap " << this->name_ << " has been assembled from the finest scraps!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << this->name_ << " is being disassembled for parts." << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (this->energy_point_ > 0 && this->hit_point_ > 0) {
        std::cout << "FragTrap " << this->name_ << " aggressively attacks " << target << ", causing "
                  << this->attack_dmg_ << " points of damage! Get rekt!" << std::endl;
        this->energy_point_--;
    } else {
        std::cout << "FragTrap " << this->name_ << " has no energy or hit points left to attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    if (this->energy_point_ <= 0 || this->hit_point_ <= 0) {
        std::cout << "Can't perform action !\n";
        return;
    }

    std::cout << "HIGH FIVEEEEE BRO'sss\n";
}
