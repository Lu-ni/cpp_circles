#include <iostream>

#include "Bureaucrat.hpp"

int main(void) {
    try {
        Bureaucrat bob("bob", -1);
        std::cout << bob;
    } catch (const std::exception& e) {
        std::cerr << "Error creating bob(-1): " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("bob", 1);
        std::cout << bob;
        bob.decrementGrade();
        std::cout << bob;
        bob.decrementGrade();
        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
        bob.incrementGrade();
        std::cout << bob;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("bob", 1000);
        std::cout << bob;
    } catch (const std::exception& e) {
        std::cerr << "Error creating bob(1000): " << e.what() << std::endl;
    }

    return 0;
}
