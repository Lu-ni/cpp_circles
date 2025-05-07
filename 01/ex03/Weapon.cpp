/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:54 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:54 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}
Weapon::Weapon() {}
const std::string& Weapon::getType() {
    return Weapon::type_;
}
void Weapon::setType(std::string weapon_type) {
    Weapon::type_ = weapon_type;
}
