#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& rhs) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal& rhs) {
	std::cout << "Animal copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Animal makeSound called." << std::endl;
}

const std::string& Animal::getType() const {
	return this->_type;
}