/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:40 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/13 19:35:40 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
    std::cout << "CREATING A WRONG CATTTTT\n";
    this->type = "WrongCat";
}
WrongCat::~WrongCat() {
    std::cout << "DESTROYING A WRONG CATTTTT\n";
}
void WrongCat::makeSound(void) const {
    std::cout << "         /\\_/\\   ________________\n";
    std::cout << "        / o o \\ /                \\____________\n";
    std::cout << " MIAOU>(  > <  )                  |\n";
    std::cout << "        \\_____/ \\________________/\n";
}
