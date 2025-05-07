/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:11:24 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:43 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() : next_insert_index(0), current_size(0) {}
void PhoneBook::add_contact(const Contact& new_contact) {
    contact_list[next_insert_index] = new_contact;
    next_insert_index = (next_insert_index + 1) % MAX_CONTACTS;
    if (current_size < MAX_CONTACTS) {
        current_size++;
    }
}
std::string PhoneBook::format_and_truncate_string(const std::string& input, int max_width = 10) const {
    if (max_width <= 0) {
        return "";
    }
    size_t max_w = static_cast<size_t>(max_width);

    if (input.length() > max_w) {
        if (max_w > 0) {
            return input.substr(0, max_w - 1) + ".";
        }
        return "";
    }
    return input;
}

void PhoneBook::search() {
    if (this->current_size == 0) {
        std::cout << "Phonebook is empty. Nothing to search." << std::endl;
        return;
    }

    this->display_contacts();

    size_t index;
    while (true) {
        std::cout << "Enter index of contact to display (0-" << (this->current_size > 0 ? this->current_size - 1 : 0)
                  << ") or type 'EXIT': ";

        std::string line;
        if (!std::getline(std::cin, line)) {
            if (std::cin.eof()) {
                std::cout << "\n[Info] End of input detected. Cancelling search." << std::endl;
                std::cin.clear();
            } else {
                std::cerr << "[Error] Input stream failed." << std::endl;
                std::cin.clear();
            }
            return;
        }

        if (line == "EXIT") {
            std::cout << "[Info] Exiting search." << std::endl;
            exit(0);
        }

        if (line.length() == 1 && line[0] >= '0' && line[0] <= '7') {
            size_t potential_index = static_cast<size_t>(line[0] - '0');

            if (potential_index < this->current_size) {
                index = potential_index;
                break;
            } else {
                std::cout << "[Error] Index out of range for current contacts (max is "
                          << (this->current_size > 0 ? this->current_size - 1 : 0) << ")." << std::endl;
            }
        } else {
            std::cout << "[Error] Invalid input. Please enter a single digit between 0 and "
                      << (this->current_size > 0 ? this->current_size - 1 : 0) << " or type 'exit'." << std::endl;
        }
    }

    this->display_contact(index);
}

void PhoneBook::display_contact(std::size_t index) const {
    std::cout << std::left << std::setw(20) << "first_name:" << contact_list[index].get_first_name() << std::endl;
    std::cout << std::left << std::setw(20) << "last_name:" << contact_list[index].get_last_name() << std::endl;
    std::cout << std::left << std::setw(20) << "nickname:" << contact_list[index].get_nickname() << std::endl;
    std::cout << std::left << std::setw(20) << "phone_number:" << contact_list[index].get_phone_number() << std::endl;
    std::cout << std::left << std::setw(20) << "darkest_secret:" << contact_list[index].get_darkest_secret()
              << std::endl;
}
void PhoneBook::display_contacts() const {
    std::string border = "+----------+----------+----------+----------+\n";
    for (std::size_t i = 0; i < current_size; i++) {
        std::cout << border << "|" << std::right << std::setw(10) << i << "|" << std::right << std::setw(10)
                  << format_and_truncate_string(contact_list[i].get_first_name()) << "|" << std::right << std::setw(10)
                  << format_and_truncate_string(contact_list[i].get_last_name()) << "|" << std::right << std::setw(10)
                  << format_and_truncate_string(contact_list[i].get_nickname()) << "|" << std::endl
                  << border;
    }
}
