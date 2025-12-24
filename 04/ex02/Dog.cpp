/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:41 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:35:58 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

#include "Brain.hpp"

Dog::Dog() : brain(new Brain()) {
    std::cout << "CREATING A DOGGG\n";
    this->type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*(other.brain))) {
    std::cout << "Copy-constructing Dog\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Assigning Dog\n";
    if (this != &other) {
        Animal::operator=(other);
        *(this->brain) = *(other.brain);
    }
    return *this;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "DESTROYING A DOGGG\n";
}
void Dog::makeSound(void) const {
    std::cout << "  / \\__\n";
    std::cout << " (    @\\___\n";
    std::cout << " /         O\n";
    std::cout << "/   (_____/\n";
    std::cout << "/_____/ U   BARKKK!\n";
}
void Dog::printIdeas(void) const {
    this->brain->printIdeas();
}
