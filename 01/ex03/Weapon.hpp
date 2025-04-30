#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon {
   private:
    std::string type_;

   public:
    const std::string& getType();
    void setType(std::string);
    Weapon();
    Weapon(std::string type);
};

#endif
