/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:55 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:55 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

void HumanB::attack(void) {
    if (HumanB::weapon_ == NULL)
        std::cout << HumanB::name_ << " attacks with their their bare hand... Give him a weapon god damnit !"
                  << "\n";
    else {
        std::cout << HumanB::name_ << " attacks with their " << HumanB::weapon_->getType() << "\n";
    }
}

void HumanB::setWeapon(Weapon& weapon) {
    HumanB::weapon_ = &weapon;
}
