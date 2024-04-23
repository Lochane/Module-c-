#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	
	public :
		WrongCat();
		WrongCat(const WrongCat& rhs);
		~WrongCat();
		WrongCat &operator=(const WrongCat& rhs);
		
		void makeSound() const;
} ;

#endif