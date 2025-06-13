#pragma once
#include <string>
class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    virtual ~WrongAnimal();
    void makeSound(void) const;
    std::string getType() const;

   protected:
    std::string type;
};
