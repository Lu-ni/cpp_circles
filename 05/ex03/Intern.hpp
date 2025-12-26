/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:22:47 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/26 14:22:47 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

#include "AForm.hpp"
class AForm;
class Intern {
   public:
    class FormNotFound : public std::exception {
       public:
        const char* what() const throw();
    };
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm* makeForm(const std::string& form, const std::string& form_target);

   private:
};
