#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : next_insert_index(0), current_size(0) {}
void PhoneBook::add_contact(const Contact& new_contact) {
    contact_list[next_insert_index] = new_contact;
    next_insert_index = (next_insert_index + 1) % MAX_CONTACTS;
    if (current_size < MAX_CONTACTS) {
        current_size++;
    }
}
void PhoneBook::display_contact(std::size_t) const {}
void PhoneBook::display_contacts() const {
    for (std::size_t i = 0; i < current_size; i++) {
        std::cout << contact_list[i].get_nickname() << std::endl;
    }
}
