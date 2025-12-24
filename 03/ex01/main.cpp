/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:55:36 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:35:37 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "--- Testing a standard ClapTrap ---" << std::endl;
    {
        ClapTrap claptrap("CT-Unit-734");
        claptrap.attack("a training dummy");
        claptrap.takeDamage(4);
        claptrap.beRepaired(2);
        claptrap.takeDamage(8);
        claptrap.attack("the same dummy");  // Should fail, not enough HP
    }

    std::cout << "--- Testing the new ScavTrap ---" << std::endl;
    ScavTrap scavtrap("SV-Bouncer");

    scavtrap.attack("a particularly tough-looking door");
    scavtrap.takeDamage(25);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();  // Testing the special ability
    scavtrap.takeDamage(900);
    scavtrap.guardGate();  // Testing the ability again after taking lethal damage

    std::cout << "--- Objects will be destroyed at the end of main ---" << std::endl;

    return 0;
}
