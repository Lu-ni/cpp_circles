/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:54 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:38 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <string>

#include "Weapon.hpp"

class HumanA {
   public:
    HumanA(std::string name, Weapon& weapon);
    void attack(void);
    void seType(std::string type);

   private:
    std::string name_;
    Weapon& weapon_;
};

#endif  // HUMANA_HPP
