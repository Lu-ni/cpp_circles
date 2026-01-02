/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:45 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:45 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <ostream>

ScalarConverter::ScalarConverter() {}

bool manageSpecial(const std::string& literal) {
    std::string specialTypes[6] = {"nan", "nanf", "+inf", "+inff", "-inf", "-inff"};
    int n_special = sizeof(specialTypes) / sizeof(specialTypes[0]);
    for (int i = 0; i < n_special; i++) {
        if (literal == specialTypes[i]) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            if (i % 2 == 0) {
                std::cout << "float: " << literal << "f" << std::endl;
                std::cout << "double: " << literal << std::endl;
            } else {
                std::cout << "float: " << literal << std::endl;
                std::string sub = literal.substr(0, literal.length() - 1);
                std::cout << "double: " << sub << std::endl;
            }
            return true;
        }
    }
    return false;
}

void printChar(double& d) {
    std::cout << "char: ";
    if (d < 0 || d > 127) {
        std::cout << "impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(d))) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
    }
}

void printInt(double& d) {
    std::cout << "int: ";
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
}

void printFloat(double& d) {
    float f = static_cast<float>(d);
    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void printDouble(double& d) {
    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    double d;
    char* endptr;

    if (manageSpecial(literal))
        return;

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        d = static_cast<double>(literal[0]);
    } else {
        std::string to_convert = literal;
        if (literal[literal.length() - 1] == 'f' && literal.length() > 1 && literal.find('.') != std::string::npos) {
            to_convert = literal.substr(0, literal.length() - 1);
        }

        d = std::strtod(to_convert.c_str(), &endptr);
        std::cout << "endchar:" << *endptr << "\n";
        if (*endptr != '\0' && !(*endptr == 'f' && *(endptr + 1) == '\0')) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}
