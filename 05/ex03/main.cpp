/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:10 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/26 14:22:53 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    std::srand(std::time(NULL));

    Intern petitLoulou;
    Bureaucrat bob("Bob", 1);
    try {
        AForm* form = petitLoulou.makeForm("robotomy request", "le g");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }

    try {
        AForm* form = petitLoulou.makeForm("wrong", "le g");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }

    try {
        AForm* form = petitLoulou.makeForm("presidential pardon", "le g");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }

    try {
        AForm* form = petitLoulou.makeForm("shrubbery creation", "le g");
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    } catch (std::exception& e) {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
    }
    return 0;
}
