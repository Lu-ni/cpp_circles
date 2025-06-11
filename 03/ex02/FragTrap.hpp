#ifndef FRAGTAP_HPP
#define FRAGTAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap(std::string name);
    virtual ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif  // FRAGTAP_HPP
