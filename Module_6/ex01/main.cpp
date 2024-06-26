/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:26:00 by lsouquie          #+#    #+#             */
/*   Updated: 2024/05/08 11:05:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.str = "Hello";

    uintptr_t serialized_ptr = Serializer::serialize(&data);

    std::cout << "Serialized: " << serialized_ptr << std::endl;

    Data *ptr = Serializer::deserialize(serialized_ptr);

    std::cout << "Deserialized: " << ptr->str << " " << std::endl;

    return 0;
}


