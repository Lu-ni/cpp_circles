/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:40 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:40 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : raw_bits_(0) {
    std::cout << "Default constructor called"
              << "\n";
}

Fixed::Fixed(const Fixed& other) : raw_bits_(0) {
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

Fixed::Fixed(int int_value) : raw_bits_(0) {
    this->setRawBits(int_value << Fixed::N_FRACTIONAL_BITS);
    std::cout << "Int constuctor"
              << "\n";
}

Fixed::Fixed(float float_value) : raw_bits_(0) {
    int raw_value_to_set = roundf(float_value * (1 << Fixed::N_FRACTIONAL_BITS));
    this->setRawBits(raw_value_to_set);
    std::cout << "floatt constuctor"
              << "\n";
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << Fixed::N_FRACTIONAL_BITS);
}

int Fixed::toInt(void) const {
    return (this->getRawBits() >> Fixed::N_FRACTIONAL_BITS);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp) {
    os << fp.toFloat();

    return os;
}
