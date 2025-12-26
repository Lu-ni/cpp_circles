/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:22:52 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/26 14:22:52 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <string>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Default Constructor
Intern::Intern() {}

// Copy Constructor
Intern::Intern(const Intern& other) {
    (void)other;
}

// Copy Assignment Operator
Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
        (void)other;
    }
    return *this;
}

// Destructor
Intern::Intern::~Intern() {}

const char* Intern::FormNotFound::what() const throw() {
    return "Can't find it, please stoooooop";
}
int getIndex(const std::string form) {
    std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    for (unsigned long i = 0; i < sizeof(forms); i++)
        if (forms[i] == form)
            return i;
    return -1;
}
AForm* Intern::makeForm(const std::string& form, const std::string& form_target) {
    switch (getIndex(form)) {
        case 0:
            return new PresidentialPardonForm(form_target);
        case 1:
            return new RobotomyRequestForm(form_target);
        case 2:
            return new ShrubberyCreationForm(form_target);
        default:
            throw Intern::FormNotFound();
    }
}
