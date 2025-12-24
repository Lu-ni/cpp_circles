/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:10 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:10 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    std::srand(std::time(NULL));

    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Ford Prefect");

        std::cout << "\n--- Shrubbery Creation ---\n";
        alice.signForm(shrub);     // Fail
        bob.signForm(shrub);       // Success
        alice.executeForm(shrub);  // Fail
        bob.executeForm(shrub);    // Success

        std::cout << "\n--- Robotomy Request ---\n";
        bob.signForm(robot);
        bob.executeForm(robot);
        bob.executeForm(robot);
        bob.executeForm(robot);

        std::cout << "\n--- Presidential Pardon ---\n";
        bob.signForm(pardon);
        bob.executeForm(pardon);

        std::cout << "\n--- Exceptions ---\n";
        try {
            Bureaucrat low("Low", 150);
            PresidentialPardonForm p2("Nobody");
            low.signForm(p2);
        } catch (std::exception& e) {
            std::cerr << "Caught: " << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }

    return 0;
}
