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

Fixed::Fixed() : raw_bits_(0) {}

Fixed::Fixed(const Fixed& other) : raw_bits_(0) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->raw_bits_ = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return this->raw_bits_;
}

void Fixed::setRawBits(int const raw) {
    this->raw_bits_ = raw;
}

Fixed::Fixed(int int_value) : raw_bits_(0) {
    this->setRawBits(int_value << Fixed::N_FRACTIONAL_BITS);
}

Fixed::Fixed(float float_value) : raw_bits_(0) {
    int raw_value_to_set = roundf(float_value * (1 << Fixed::N_FRACTIONAL_BITS));
    this->setRawBits(raw_value_to_set);
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
// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->getRawBits() > other.getRawBits();
}
bool Fixed::operator<(const Fixed& other) const {
    return this->getRawBits() < other.getRawBits();
}
bool Fixed::operator>=(const Fixed& other) const {
    return this->getRawBits() >= other.getRawBits();
}
bool Fixed::operator<=(const Fixed& other) const {
    return this->getRawBits() <= other.getRawBits();
}
bool Fixed::operator==(const Fixed& other) const {
    return this->getRawBits() == other.getRawBits();
}
bool Fixed::operator!=(const Fixed& other) const {
    return this->getRawBits() != other.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    int raw_product = (this->getRawBits() * other.getRawBits()) >> Fixed::N_FRACTIONAL_BITS;
    result.setRawBits(raw_product);
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    int raw_div = (this->getRawBits() << Fixed::N_FRACTIONAL_BITS) / other.getRawBits();
    result.setRawBits(raw_div);
    return result;
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}
Fixed& Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

// Min/Max static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() < b.getRawBits()) {
        return a;
    }
    return b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    if (a.getRawBits() > b.getRawBits()) {
        return a;
    }
    return b;
}
