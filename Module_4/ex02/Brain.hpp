#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private :
		std::string _ideas[100];
	
	public :
		Brain();
		Brain(const Brain& rhs);
		Brain &operator=(const Brain & rhs);
		~Brain();

		// const std::string* getType();
} ;

#endif