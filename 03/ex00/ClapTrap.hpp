#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
class ClapTrap {
   public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

   private:
    std::string name_;
    unsigned int hit_point_;  //health
    unsigned int attack_dmg_;
    unsigned int energy_point_;
};

#endif  // CLAPTRAP_HPP
