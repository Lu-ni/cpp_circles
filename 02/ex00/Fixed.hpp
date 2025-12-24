/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:39 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:12 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    virtual ~Fixed();

    void setRawBits(int const raw);
    int getRawBits(void) const;

   private:
    static const int N_FRACTIONAL_BITS = 8;
    int raw_bits_;
    // Private members go here
};

#endif  // FIXED_HPP
