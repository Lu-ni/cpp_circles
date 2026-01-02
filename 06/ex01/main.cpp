/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <lucas.nicollier@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:36:48 by lnicolli          #+#    #+#             */
/*   Updated: 2025/12/24 15:36:48 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main() {
    Data data;
    data.id = 42;
    data.s1 = "Hello";
    data.s2 = "World";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data) {
        std::cout << "Success: Deserialized pointer matches original pointer." << std::endl;
        std::cout << "Data content: " << ptr->id << ", " << ptr->s1 << ", " << ptr->s2 << std::endl;
        std::cout << "### Modification ###" << std::endl;
        ptr->id = 1;
        ptr->s1 = "Ola";
        ptr->s2 = "Che tal";
        std::cout << "Data content: " << data.id << ", " << data.s1 << ", " << data.s2 << std::endl;
    } else {
        std::cout << "Failure: Deserialized pointer does not match original pointer." << std::endl;
    }

    return 0;
}
