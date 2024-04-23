#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	this->_type = rhs._type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Miaou Miaou" << std::endl;
}