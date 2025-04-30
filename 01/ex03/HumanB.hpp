#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>

#include "Weapon.hpp"

class HumanB {
   public:
    HumanB(std::string name);
    void attack(void);
    void seType(std::string type);
    void setWeapon(Weapon& weapon);

   private:
    std::string name_;
    Weapon* weapon_;
};

#endif  // HUMANB_HPP
