/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:55:36 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/12 13:55:36 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->hit_point_ = 100;
    this->energy_point_ = 50;
    this->attack_dmg_ = 20;

    std::cout << "ScavTrap " << this->name_ << " has been assembled from the finest scraps!" << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name_ << " is being disassembled for parts." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energy_point_ > 0 && this->hit_point_ > 0) {
        std::cout << "ScavTrap " << this->name_ << " aggressively attacks " << target << ", causing "
                  << this->attack_dmg_ << " points of damage! Get rekt!" << std::endl;
        this->energy_point_--;
    } else {
        std::cout << "ScavTrap " << this->name_ << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    if (this->hit_point_ > 0 && this->energy_point_ > 0) {
        std::cout << "ScavTrap " << this->name_ << " is now in Gate keeper mode. None shall pass!" << std::endl;
        this->energy_point_--;
    } else {
        std::cout << "ScavTrap " << this->name_ << " can't enter Gate keeper mode, it's broken!" << std::endl;
    }
}
