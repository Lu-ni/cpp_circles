/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:03 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:03 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    const int min_grade_to_sign_;
    const int min_grade_to_execute_;
};
std::ostream& operator<<(std::ostream& os, Form& form);
