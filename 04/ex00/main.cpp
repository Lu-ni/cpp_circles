/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:35:41 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:35:48 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void breakLine() {
    std::cout << "\n";
    std::cout << "################################################################################\n";
    std::cout << "\n";
}
int main(void) {
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();  //will output the cat sound! j->makeSound();
        j->makeSound();  //will output the cat sound! j->makeSound();
        meta->makeSound();
        delete i;
        delete j;
        delete meta;
    }
    breakLine();
    {
        Animal animal;
        animal.makeSound();
    }
    breakLine();
    {
        Cat cat;
        cat.makeSound();
        std::cout << cat.getType() << "\n";
    }
    breakLine();
    {
        Dog dog;
        dog.makeSound();
        std::cout << dog.getType() << "\n";
    }
    breakLine();
    {
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();  //will output the animal sound! j->makeSound();
        meta->makeSound();
        delete i;
        delete meta;
    }
    breakLine();
}
