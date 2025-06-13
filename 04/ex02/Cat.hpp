#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
   public:
    Cat();
    ~Cat();
    void makeSound(void) const;
    void printIdeas(void) const;
    Cat& operator=(const Cat& other);

   private:
    Brain* brain;
};
