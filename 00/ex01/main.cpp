#include <iostream>
#include <string>

#include "Contact.hpp"  // Assumes rigid-member Contact class
#include "PhoneBook.hpp"

bool fill_contact_from_input(Contact& contact_to_fill) {
    const char* const* contact_field = Contact::get_field_names();
    for (int i = 0; contact_field[i]; ++i) {
        std::string field_name = contact_field[i];
        std::cout << field_name << ": ";
        std::string input_value;
        std::getline(std::cin, input_value);
        if (input_value.empty()) {
            std::cout << "Error: Field cannot be empty." << std::endl;
            return false;
        }
        if (field_name == "first_name") {
            contact_to_fill.set_first_name(input_value);
        } else if (field_name == "last_name") {
            contact_to_fill.set_last_name(input_value);
        } else if (field_name == "nickname") {
            contact_to_fill.set_nickname(input_value);
        } else if (field_name == "phone_number") {
            contact_to_fill.set_phone_number(input_value);
        } else if (field_name == "darkest_secret") {
            contact_to_fill.set_darkest_secret(input_value);
        }
    }
    return true;
}

int main() {
    std::cout << "Welcome to THE phonebook. Use one of the following -> "
                 "(ADD/SEARCH/EXIT)"
              << '\n';
    PhoneBook phonebook;

    while (true) {
        std::cout << "cmd: ";
        std::string cmd;
        if (!std::getline(std::cin, cmd)) {
            if (std::cin.eof()) {
                std::cout << "\n[Info] End of input detected. Exiting." << std::endl;
            } else {
                std::cerr << "[Error] Failed to read command." << std::endl;
            }
            break;  // Exit the loop on EOF or error
        }
        if (cmd == "ADD") {
            Contact temp_contact;
            if (fill_contact_from_input(temp_contact)) {
                phonebook.add_contact(temp_contact);
            } else {
                std::cout << "Failed to add contact (empty field entered)." << std::endl;
            }
        } else if (cmd == "SEARCH") {
            phonebook.search();
        } else if (cmd == "EXIT") {
            return 0;
        } else {
            std::cout << "'" << cmd << "'"
                      << " is not a valid command. Use ADD/SEARCH/EXIT" << std::endl;
        }
    }
}
