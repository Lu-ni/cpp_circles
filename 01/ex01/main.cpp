#include <iostream>

#include "Zombie.hpp"

int main(void) {
    int const hord_size = 10;
    Zombie* zombs = NULL;
    zombs = zombieHorde(hord_size, "bob");
    if (zombs == nullptr) {
        std::cout << "Failed to allocate zombie horde!" << std::endl;
        return 1;
    }
    for (int i = 0; i < hord_size; i++) {
        zombs[i].announce();
    }
    delete[] zombs;
}
