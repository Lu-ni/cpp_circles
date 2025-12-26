/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:05 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/26 14:22:48 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <ostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
       public:
        const char* what() const throw();
    };

    AForm(std::string name, int grade_to_sign, int grade_to_exec);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    std::string getName(void) const;
    bool isSigned(void) const;
    int getMinGradeToSign(void) const;
    int getMinGradeToExecute(void) const;
    void beSigned(Bureaucrat& bureaucrat);
    void execute(Bureaucrat const& executor) const;
    virtual void action(void) const = 0;

   private:
    const std::string name_;
    bool is_signed_;
    const int min_grade_to_sign_;
    const int min_grade_to_execute_;
};
std::ostream& operator<<(std::ostream& os, AForm& form);
