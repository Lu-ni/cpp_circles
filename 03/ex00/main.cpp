/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:07:30 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/12 13:55:36 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    std::cout << "--- Test 1: Basic functionality ---" << std::endl;
    ClapTrap clappy("Clappy");
    clappy.attack("a scary rock");
    clappy.takeDamage(5);
    clappy.beRepaired(3);
    clappy.takeDamage(8);
    clappy.beRepaired(10);              // Should not be able to repair, no hit points
    clappy.attack("a harmless bunny");  // Should not be able to attack, no hit points

    std::cout << "\n--- Test 2: Energy depletion ---" << std::endl;
    ClapTrap energyBot("EnergyBot");
    energyBot.attack("target 1");
    energyBot.attack("target 2");
    energyBot.attack("target 3");
    energyBot.attack("target 4");
    energyBot.attack("target 5");
    energyBot.beRepaired(1);
    energyBot.beRepaired(1);
    energyBot.beRepaired(1);
    energyBot.beRepaired(1);
    energyBot.beRepaired(1);
    energyBot.attack("out of energy attack");  // No energy left
    energyBot.beRepaired(1);                   // No energy left

    std::cout << "\n--- Test 3: Copy constructor and assignment operator ---" << std::endl;
    ClapTrap original("Original");
    original.attack("a clone");

    ClapTrap copy(original);
    copy.attack("the original");

    ClapTrap assign("Assignee");
    assign = original;
    assign.attack("the world");

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
