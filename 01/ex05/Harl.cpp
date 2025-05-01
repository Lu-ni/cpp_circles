#include "Harl.hpp"

#include <iostream>

Harl::Harl() {
    this->function_map_[0] = &Harl::debug;
    this->function_map_[1] = &Harl::info;
    this->function_map_[2] = &Harl::warning;
    this->function_map_[3] = &Harl::error;

    this->name_map_[0] = "DEBUG";
    this->name_map_[1] = "INFO";
    this->name_map_[2] = "WARNING";
    this->name_map_[3] = "ERROR";
}

void Harl::complain(std::string level) {
    for (unsigned long i = 0; i < sizeof(this->function_map_) / sizeof(this->function_map_[0]); i++) {
        if (level == this->name_map_[i]) {
            (this->*function_map_[i])();
            return;
        }
    }
    std::cout << "Error: log level \'" << level << "\' is not in DEBUG INFO WARNING ERROR"
              << "\n";
}
void Harl::debug(void) {
    std::cout << "[ DEBUG ] "
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.I really do!"
              << "\n";
}

void Harl::info(void) {
    std::cout << "[ INFO ] "
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If "
              << "you did, I wouldn’t be asking for more!"
              << "\n";
}

void Harl::warning(void) {
    std::cout << "[ WARNING ] "
              << "I think I deserve to have some extra bacon for FREE. I’ve been coming for years, whereas you started"
              << "working here just last month."
              << "\n";
}

void Harl::error(void) {
    std::cout << "[ ERROR ] "
              << "This is unacceptable! I want to speak to the manager now."
              << "\n";
}
