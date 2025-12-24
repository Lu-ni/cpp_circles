/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:41 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:16 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main(void) {
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }
    //custom tests
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << "Initial values:\n";
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;

        std::cout << "\nIncrement tests:\n";
        std::cout << "++a: " << ++a << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "a++: " << a++ << std::endl;
        std::cout << "a: " << a << std::endl;

        std::cout << "\nDecrement tests:\n";
        std::cout << "--a: " << --a << std::endl;
        std::cout << "a: " << a << std::endl;
        std::cout << "a--: " << a-- << std::endl;
        std::cout << "a: " << a << std::endl;

        std::cout << "\nArithmetic tests:\n";
        Fixed x(3.5f);
        Fixed y(1.75f);
        std::cout << "x: " << x << ", y: " << y << std::endl;
        std::cout << "x + y: " << (x + y) << std::endl;
        std::cout << "x - y: " << (x - y) << std::endl;
        std::cout << "x * y: " << (x * y) << std::endl;
        std::cout << "x / y: " << (x / y) << std::endl;

        std::cout << "\nComparison tests:\n";
        std::cout << "x == y: " << (x == y) << std::endl;
        std::cout << "x != y: " << (x != y) << std::endl;
        std::cout << "x > y: " << (x > y) << std::endl;
        std::cout << "x < y: " << (x < y) << std::endl;
        std::cout << "x >= y: " << (x >= y) << std::endl;
        std::cout << "x <= y: " << (x <= y) << std::endl;

        std::cout << "\nMin/Max tests:\n";
        Fixed& minRef = Fixed::min(a, x);
        Fixed& maxRef = Fixed::max(a, x);
        std::cout << "min(a, x): " << minRef << std::endl;
        std::cout << "max(a, x): " << maxRef << std::endl;

        const Fixed cx(10.5f);
        const Fixed cy(42.42f);
        std::cout << "min(const): " << Fixed::min(cx, cy) << std::endl;
        std::cout << "max(const): " << Fixed::max(cx, cy) << std::endl;
    }

    return 0;
}
