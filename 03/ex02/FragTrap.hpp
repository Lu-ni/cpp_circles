/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:55:36 by lnicolli          #+#    #+#             */
/*   Updated: 2025/06/12 13:55:36 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTAP_HPP
#define FRAGTAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   public:
    FragTrap(std::string name);
    virtual ~FragTrap();

    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif  // FRAGTAP_HPP
