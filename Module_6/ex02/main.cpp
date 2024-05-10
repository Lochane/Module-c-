/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:40:05 by marvin            #+#    #+#             */
/*   Updated: 2024/05/08 11:40:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
 	srand(time(NULL));
	int RandNb = rand() % 3;
		switch (RandNb) {
			case 0:
				return new A;
			case 1:
				return new B;
			case 2:
				return new C;
		}
	return NULL;
}

void identify(Base *p){

		if (dynamic_cast<A *>(p))
			std::cout << "A" << std::endl;
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << std::endl;
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << std::endl;
		else
		std::cout << "Unknown object type" << std::endl;
	}

void identify(Base& p) {
    try {
        if (dynamic_cast<A*>(&p)) {
            std::cout << "A" << std::endl;
        } else if (dynamic_cast<B*>(&p)) {
            std::cout << "B" << std::endl;
        } else if (dynamic_cast<C*>(&p)) {
            std::cout << "C" << std::endl;
        }
    } catch(std::exception &e) {
        std::cout << "Unknown object type" << std::endl;
    }
}

int main() {
    Base* randomObject = generate();

    identify(randomObject);

    identify(*randomObject);

    delete randomObject;

    return 0;
}
