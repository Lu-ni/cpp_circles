/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:14:09 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:21 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <cstddef>

#include "Contact.hpp"

class PhoneBook {
   public:
    static const std::size_t MAX_CONTACTS = 8;

   private:
    Contact contact_list[MAX_CONTACTS];
    std::size_t next_insert_index;
    std::size_t current_size;
    std::string format_and_truncate_string(const std::string& input, int max_width) const;

   public:
    PhoneBook();

    void search();
    void add_contact(const Contact& new_contact);
    void display_contact(std::size_t index) const;
    void display_contacts() const;
    std::size_t get_contact_count() const;
};

#endif  // PHONEBOOK_HPP
