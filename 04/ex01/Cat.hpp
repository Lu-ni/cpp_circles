#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound(void) const;
    void printIdeas(void) const;

   private:
    Brain* brain;
};
