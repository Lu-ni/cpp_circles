/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:08 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:08 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    grade_ = grade;
    std::cout << this->name_ << " was created with grade " << this->grade_ << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        grade_ = other.grade_;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const {
    return this->name_;
}

int Bureaucrat::getGrade(void) const {
    return this->grade_;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
    return os;
}

void Bureaucrat::decrementGrade(void) {
    if (this->grade_ + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade_++;
}
void Bureaucrat::incrementGrade(void) {
    if (this->grade_ - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade_--;
}
void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << this->name_ << " signs " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->name_ << " cannot sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form) {
    try {
        form.execute(*this);
        std::cout << this->name_ << " executed " << form.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->name_ << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
