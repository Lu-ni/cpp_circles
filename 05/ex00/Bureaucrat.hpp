/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:00 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:00 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <ostream>
#include <string>

class Bureaucrat {
   public:
    class GradeTooHighException : public std::exception {
       public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        const char* what() const throw();
    };
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    virtual ~Bureaucrat();
    std::string getName(void) const;
    int getGrade(void) const;
    void incrementGrade(void);
    void decrementGrade(void);

   private:
    const std::string name_;
    int grade_;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
