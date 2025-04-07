#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   private:
    std::string name_;

   public:
    Zombie(std::string zombie_name);
    Zombie();
    ~Zombie();
    void announce(void);
    void setName(std::string name);
};

Zombie* newZombie(std::string);
void randomChump(std::string);
Zombie* zombieHorde(int N, std::string name);

#endif
