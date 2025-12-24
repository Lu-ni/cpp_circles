/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:59 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:44 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>  // Include for std::cout

#include "Harl.hpp"

int main(void) {

    Harl harl;

    std::cout << "Testing DEBUG level:" << '\n';
    harl.complain("DEBUG");

    std::cout << "Testing INFO level:"
              << "\n";
    harl.complain("INFO");

    std::cout << "Testing WARNING level:"
              << "\n";
    harl.complain("WARNING");

    std::cout << "Testing ERROR level:"
              << "\n";
    harl.complain("ERROR");

    std::cout << "Testing an unknown level:"
              << "\n";
    harl.complain("WHINING");

    std::cout << "Testing another unknown level:"
              << "\n";
    harl.complain("CONFUSED");

    std::cout << "--- Harl seems done for now ---"
              << "\n";

    return 0;
}
