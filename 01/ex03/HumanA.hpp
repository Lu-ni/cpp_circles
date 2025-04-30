#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(std::string name, Weapon& weapon);
    void attack(void);
    void seType(std::string type);

   private:
    std::string name_;
    Weapon& weapon_;
};

#endif  // HUMANA_HPP
