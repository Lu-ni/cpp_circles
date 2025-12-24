/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:38 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:11 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : raw_bits_(0) {
    std::cout << "Default constructor called"
              << "\n";
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called"
              << "\n";
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called"
              << "\n";
    if (this != &other) {
        this->raw_bits_ = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called"
              << "\n";
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called"
              << "\n";
    return this->raw_bits_;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called"
              << "\n";
    this->raw_bits_ = raw;
}
