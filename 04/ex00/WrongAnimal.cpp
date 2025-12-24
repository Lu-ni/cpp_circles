/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:40 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:35:45 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "Constructing WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "Copy-constructing WrongAnimal of type: " << this->type << ".\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Assigning data from another " << other.type << " to this " << this->type << ".\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "DESTROYING WrongAnimal\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Make the sound of all the  wrong animals ... yeah yeah that's noisy!\n";
}
std::string WrongAnimal::getType() const {
    return this->type;
}
