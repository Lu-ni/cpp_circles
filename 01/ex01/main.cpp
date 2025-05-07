/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:52 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:52 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Zombie.hpp"

int main(void) {
    int const hord_size = 10;
    Zombie* zombs = NULL;
    zombs = zombieHorde(hord_size, "bob");
    if (zombs == NULL) {
        std::cout << "Failed to allocate zombie horde!" << std::endl;
        return 1;
    }
    for (int i = 0; i < hord_size; i++) {
        zombs[i].announce();
    }
    delete[] zombs;
}
