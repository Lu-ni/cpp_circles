#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type_(type) {}
Weapon::Weapon() {}
const std::string& Weapon::getType() {
    return Weapon::type_;
}
void Weapon::setType(std::string weapon_type) {
    Weapon::type_ = weapon_type;
}
