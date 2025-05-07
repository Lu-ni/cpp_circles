/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:15:38 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:48 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
   private:
    std::string name_;

   public:
    Zombie(std::string zombie_name);
    ~Zombie();
    void announce(void);
};

Zombie* newZombie(std::string);
void randomChump(std::string);

#endif
