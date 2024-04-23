#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat constructor called." << std::endl;
	this->_brain = new Brain ();
	if (!this->_brain)
		std::cout << "Memory allocation failed" << std::endl;
}

Cat::Cat(const Cat& rhs) {
	std::cout << "Cat copy constructor called." << std::endl;
	this->_brain = new Brain ();
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	delete this->_brain;
	this->_type = rhs._type;
	_brain = new Brain (*rhs._brain);
	if (!_brain)
		std::cout << "Bad memory allocation" << std::endl;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "Miaou Miaou" << std::endl;
}