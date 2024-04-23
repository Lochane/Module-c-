#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& rhs) {
	// std::cout << "Cure copy constructor called" << std::endl;
	*this = rhs;
}

Cure& Cure::operator=(const Cure& rhs) {
	// std::cout << "Cure assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const {
	return (new Cure(*this));}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}