/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:40 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:15 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    virtual ~Fixed();
    Fixed(const int);
    Fixed(const float);

    void setRawBits(int const raw);
    int getRawBits(void) const;
    float toFloat(void) const;
    int toInt(void) const;

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment/Decrement operators
    Fixed& operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement

    // Min/Max static member functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

   private:
    static const int N_FRACTIONAL_BITS = 8;
    int raw_bits_;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_point);

#endif  // FIXED_HPP
