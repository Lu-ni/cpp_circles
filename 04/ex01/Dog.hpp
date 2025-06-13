#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
    void makeSound(void) const;
    void printIdeas(void) const;

   private:
    Brain* brain;
};
