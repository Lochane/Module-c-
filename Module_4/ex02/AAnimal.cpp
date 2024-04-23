#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs) {
	std::cout << "AAnimal copy constructor called." << std::endl;
	*this = rhs;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	std::cout << "AAnimal copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal makeSound called." << std::endl;
}

const std::string& AAnimal::getType() const {
	return this->_type;
}