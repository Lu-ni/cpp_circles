#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
   public:
    Dog();
    ~Dog();
    void makeSound(void) const;
    void printIdeas(void) const;
    Dog& operator=(const Dog& other);

   private:
    Brain* brain;
};
