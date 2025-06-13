#pragma once
#include <string>
class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    virtual void makeSound(void) const = 0;
    std::string getType() const;

   protected:
    std::string type;
};
