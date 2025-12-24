/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:08 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:08 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_ = other.target_;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action(void) const {
    std::string fileName = this->target_ + "_shrubbery";
    std::ofstream outFile(fileName.c_str());

    if (outFile.is_open()) {
        outFile << "       _-_" << std::endl;
        outFile << "    /~~   ~~\\";
        outFile << " /~~         ~~\\";
        outFile << "{               }" << std::endl;
        outFile << " "
                << "\\  _-     -_  /";
        outFile << "   ~  \\\\ //  ~";
        outFile << "_- -   | | _- _";
        outFile << "  _ -  | |   -_";
        outFile << "      // \\";
        outFile.close();
    } else {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
    }
}
