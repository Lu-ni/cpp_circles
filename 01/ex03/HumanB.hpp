/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:53 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:38 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
   public:
    HumanB(std::string name);
    void attack(void);
    void seType(std::string type);
    void setWeapon(Weapon& weapon);

   private:
    std::string name_;
    Weapon* weapon_;
};

#endif  // HUMANB_HPP
