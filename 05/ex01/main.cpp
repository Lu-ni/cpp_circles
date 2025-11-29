#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;
int main(void) {

    Bureaucrat bob("bob", 12);
    Form aa("OlaForm", 11, 11);
    std::cout << aa;
    try {
        aa.beSigned(bob);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << aa;
    bob.signForm(aa);
    bob.incrementGrade();
    bob.signForm(aa);

    std::cout << "#######################################################################\n";
    Form bb(aa);
    std::cout << bb;
    Form cc("new Form", 42, 42);
    bb = cc;
    std::cout << bb;

    return 0;
}
