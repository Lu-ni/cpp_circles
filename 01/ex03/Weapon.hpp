/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:56 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:41 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon {
   private:
    std::string type_;

   public:
    const std::string& getType();
    void setType(std::string);
    Weapon();
    Weapon(std::string type);
};

#endif
