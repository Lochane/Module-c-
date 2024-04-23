#include "AMateria.hpp"

AMateria::AMateria() : _type(""){
	// std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& rhs) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = rhs;
}

AMateria& AMateria::operator=(const AMateria& rhs) {
	// std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria() {
	// std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const{
	return _type;
}

AMateria* AMateria::clone() const {
	return (AMateria*)this;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria " << _type << "has been used on " << target.getName() << std::endl;	
}