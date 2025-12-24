/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:09 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:09 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

// Default Constructor
AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec)
    : name_(name), is_signed_(0), min_grade_to_sign_(grade_to_sign), min_grade_to_execute_(grade_to_exec) {
    if (grade_to_sign < 1 || grade_to_exec < 1) {
        throw AForm::GradeTooHighException();
    } else if (grade_to_sign > 150 || grade_to_exec > 150) {
        throw AForm::GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}
const char* AForm::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

// Copy Constructor
AForm::AForm(const AForm& other)
    : name_(other.name_),
      is_signed_(other.is_signed_),
      min_grade_to_sign_(other.min_grade_to_sign_),
      min_grade_to_execute_(other.min_grade_to_execute_) {}

// Copy Assignment Operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
    if (this->min_grade_to_sign_ < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    this->is_signed_ = 1;
}

std::ostream& operator<<(std::ostream& os, AForm& form) {
    std::cout << "name(" << form.getName() << ")";
    std::cout << ", is_signed(" << form.isSigned() << ")";
    std::cout << ", grade_to_sign(" << form.getMinGradeToSign() << ")";
    std::cout << ", grade_to_exec(" << form.getMinGradeToExecute() << ")\n";

    return os;
}

// Destructor
AForm::~AForm() {}

std::string AForm::getName(void) const {
    return this->name_;
}
bool AForm::isSigned(void) const {
    return this->is_signed_;
}
int AForm::getMinGradeToSign(void) const {
    return this->min_grade_to_sign_;
}
int AForm::getMinGradeToExecute(void) const {
    return this->min_grade_to_execute_;
}
void AForm::execute(Bureaucrat const& executor) const {
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->min_grade_to_execute_)
        throw AForm::GradeTooLowException();
    this->action();
}
