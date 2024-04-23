#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& rhs) {
	std::cout << "Cat copy constructor called." << std::endl;
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
	std::cout << "Cat copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Miaou Miaou" << std::endl;
}