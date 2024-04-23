#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {
	
	protected : 
		std::string _type;
	
	public :
		WrongAnimal();
		WrongAnimal(const std::string type);
		WrongAnimal(const WrongAnimal& rhs);
		 ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal& rhs);
		
		void makeSound() const;
		const std::string& getType() const;
} ;

#endif
