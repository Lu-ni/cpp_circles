/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:41 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:35:57 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

Brain::Brain() {
    std::cout << "Constructing Brain\n";
    for (int i = 0; i < NUMBER_IDEAS; ++i) {
        this->ideas_[i] = "idea";
    }
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy-constructing Brain of \n";
    for (int i = 0; i < NUMBER_IDEAS; ++i) {
        this->ideas_[i] = other.ideas_[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Assigning Brain\n";
    if (this != &other) {
        for (int i = 0; i < NUMBER_IDEAS; ++i) {
            this->ideas_[i] = other.ideas_[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "DESTROYING Brain\n";
}
void Brain::printIdeas(void) const {
    for (int i = 0; i < NUMBER_IDEAS / 25; ++i) {
        std::cout << this->ideas_[i] << "\n";
    }
}
