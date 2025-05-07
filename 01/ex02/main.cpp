/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:18:57 by lnicolli          #+#    #+#             */
/*   Updated: 2025/05/07 10:18:57 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void) {
    std::string var = "HI THIS IS BRAIN";
    std::string* stringPTR = &var;
    std::string& stringREF = var;

    std::cout << &var << "\n";
    std::cout << &stringPTR << "\n";
    std::cout << &stringREF << "\n";

    std::cout << var << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
}
