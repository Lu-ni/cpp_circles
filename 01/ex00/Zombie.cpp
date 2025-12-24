/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:15:20 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:30 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
