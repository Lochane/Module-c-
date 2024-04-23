#ifndef AANIMAL_H
#define AANIMAL_H

#include <iostream>

class AAnimal {
	
	protected : 
		std::string _type;
	
	public :
		AAnimal();
		AAnimal(const std::string type);
		AAnimal(const AAnimal& rhs);
		virtual ~AAnimal();
		AAnimal &operator=(const AAnimal& rhs);
		
		virtual void makeSound() const = 0;
		const std::string& getType() const;
} ;

#endif
