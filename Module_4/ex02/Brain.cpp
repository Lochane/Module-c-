#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain& rhs) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = rhs;
}

Brain& Brain::operator=(const Brain& rhs) {
	std::cout << "Brain copy assignment operator called." << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}