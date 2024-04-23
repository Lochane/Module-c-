#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice& rhs) {
	// std::cout << "Ice copy constructor called" << std::endl;
	*this = rhs;
}

Ice& Ice::operator=(const Ice& rhs) {
	// std::cout << "Ice assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Ice destructor called" << std::endl;
}

AMateria* Ice::clone() const {
	return (new Ice(*this));}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}