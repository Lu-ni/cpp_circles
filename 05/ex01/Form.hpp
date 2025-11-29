#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };

    Form(std::string name, int grade_to_sign, int grade_to_exec);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    std::string getName(void) const;
    bool isSigned(void) const;
    int getMinGradeToSign(void) const;
    int getMinGradeToExecute(void) const;
    void beSigned(Bureaucrat& bureaucrat);

   private:
    const std::string name_;
    bool is_signed_;
    int min_grade_to_sign_;
    int min_grade_to_execute_;
};
std::ostream& operator<<(std::ostream& os, Form& form);
