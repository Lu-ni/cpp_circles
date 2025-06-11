#include <iostream>
#include <memory>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
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
    {
        std::cout << "\n\n--- Testing the new ScavTrap ---" << std::endl;
        ScavTrap scavtrap("SV-Bouncer");

        scavtrap.attack("a particularly tough-looking door");
        scavtrap.takeDamage(25);
        scavtrap.beRepaired(10);
        scavtrap.guardGate();  // Testing the special ability
        scavtrap.takeDamage(900);
        scavtrap.guardGate();  // Testing the ability again after taking lethal damage

        std::cout << "\n\n--- Objects will be destroyed at the end of main ---" << std::endl;
    }
    {
        std::cout << "\n\n--- Testing the new FragTrap ---" << std::endl;
        FragTrap fragtap("ST-Fragger");

        fragtap.attack("a particularly tough-looking door");
        fragtap.takeDamage(25);
        fragtap.beRepaired(10);
        fragtap.highFivesGuys();
        fragtap.takeDamage(900);
        fragtap.highFivesGuys();

        std::cout << "\n\n--- Objects will be destroyed at the end of main ---" << std::endl;
    }

    return 0;
}
