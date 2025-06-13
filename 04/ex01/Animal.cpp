/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:41 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/13 19:35:41 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "Constructing Animal\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Copy-constructing Animal of type: " << this->type << ".\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Assigning data from another " << other.type << " to this " << this->type << ".\n";
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "DESTROYING Animal\n";
}

void Animal::makeSound() const {
    std::cout << "Make the sound of all the animals ... yeah yeah that's noisy!\n";
}
std::string Animal::getType() const {
    return this->type;
}
