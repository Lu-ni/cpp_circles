#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   private:
    std::string name_;

   public:
    Zombie(std::string zombie_name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string);
void randomChump(std::string);

#endif
