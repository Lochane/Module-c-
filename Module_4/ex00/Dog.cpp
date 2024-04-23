#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& rhs) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Wouf Wouf" << std::endl;
}