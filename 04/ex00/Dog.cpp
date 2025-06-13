/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:40 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/13 19:35:40 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() {
    std::cout << "CREATING A DOGGG\n";
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Copy-constructing Dog\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assigning Dog\n";
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "DESTROYING A DOGGG\n";
}
void Dog::makeSound(void) const {
    std::cout << "  / \\__\n";
    std::cout << " (    @\\___\n";
    std::cout << " /         O\n";
    std::cout << "/   (_____/\n";
    std::cout << "/_____/ U   BARKKK!\n";
}
