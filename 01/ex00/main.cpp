/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:15:23 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:33 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
int main(void) {
    randomChump("random Bob");
    Zombie* zombie = newZombie("allocated Bob");
    zombie->announce();
    delete zombie;
}
