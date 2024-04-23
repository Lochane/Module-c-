#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog constructor called." << std::endl;
	this->_brain = new Brain ();
	if (!this->_brain)
		std::cout << "Memory allocation failed" << std::endl;
}

Dog::Dog(const Dog& rhs) {
	std::cout << "Dog copy constructor called." << std::endl;
	this->_brain = new Brain ();
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
	std::cout << "Dog copy assignment operator called." << std::endl;
	delete this->_brain;
	this->_type = rhs._type;
	_brain = new Brain (*rhs._brain);
	if (!_brain)
		std::cout << "Bad memory allocation" << std::endl;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Wouf Wouf" << std::endl;
}