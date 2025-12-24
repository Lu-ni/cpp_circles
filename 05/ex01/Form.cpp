/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:02 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:02 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

// Default Constructor
Form::Form(std::string name, int grade_to_sign, int grade_to_exec)
    : name_(name), is_signed_(0), min_grade_to_sign_(grade_to_sign), min_grade_to_execute_(grade_to_exec) {
    if (grade_to_sign < 1 || grade_to_exec < 1) {
        throw Form::GradeTooHighException();
    } else if (grade_to_sign > 150 || grade_to_exec > 150) {
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

// Copy Constructor
Form::Form(const Form& other)
    : name_(other.name_),
      is_signed_(other.is_signed_),
      min_grade_to_sign_(other.min_grade_to_sign_),
      min_grade_to_execute_(other.min_grade_to_execute_) {}

// Copy Assignment Operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
    if (this->min_grade_to_sign_ < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    this->is_signed_ = 1;
}

std::ostream& operator<<(std::ostream& os, Form& form) {
    std::cout << "name(" << form.getName() << ")";
    std::cout << ", is_signed(" << form.isSigned() << ")";
    std::cout << ", grade_to_sign(" << form.getMinGradeToSign() << ")";
    std::cout << ", grade_to_exec(" << form.getMinGradeToExecute() << ")\n";

    return os;
}

// Destructor
Form::Form::~Form() {}

std::string Form::getName(void) const {
    return this->name_;
}
bool Form::isSigned(void) const {
    return this->is_signed_;
}
int Form::getMinGradeToSign(void) const {
    return this->min_grade_to_sign_;
}
int Form::getMinGradeToExecute(void) const {
    return this->min_grade_to_execute_;
}
