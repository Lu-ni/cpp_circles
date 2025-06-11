#include <iostream>
#include <memory>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void print_separator() {
    std::cout << "\n----------------------------------------\n" << std::endl;
}

int main() {
    // --- Testing ClapTrap ---
    std::cout << "--- Testing a standard ClapTrap ---" << std::endl;
    {
        ClapTrap claptrap("CT-Unit-734");
        claptrap.attack("a training dummy");
        claptrap.takeDamage(4);
        claptrap.beRepaired(2);
        claptrap.takeDamage(8);
        claptrap.attack("the same dummy");  // Should fail, not enough HP
    }
    print_separator();

    // --- Testing ScavTrap ---
    std::cout << "--- Testing the new ScavTrap ---" << std::endl;
    ScavTrap scavtrap("SV-Bouncer");

    // Test construction chaining: The output should show ClapTrap constructed first, then ScavTrap.

    scavtrap.attack("a particularly tough-looking door");
    scavtrap.takeDamage(25);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();  // Testing the special ability
    scavtrap.takeDamage(900);
    scavtrap.guardGate();  // Testing the ability again after taking lethal damage

    print_separator();

    std::cout << "--- Objects will be destroyed at the end of main ---" << std::endl;

    return 0;
}
