#include "Bureaucrat.hpp"

#include <iostream>

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
