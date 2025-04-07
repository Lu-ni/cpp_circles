#include "Zombie.hpp"
int main(void) {
    randomChump("random Bob");
    Zombie* zombie = newZombie("allocated Bob");
    zombie->announce();
    delete zombie;
}
