#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	std::cout << "WrongAnimal copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal makeSound called." << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return this->_type;
}