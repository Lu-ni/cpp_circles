/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:56 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:56 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name_(name), weapon_(weapon) {}

void HumanA::attack(void) {
    std::cout << HumanA::name_ << " attacks with their " << HumanA::weapon_.getType() << "\n";
}
