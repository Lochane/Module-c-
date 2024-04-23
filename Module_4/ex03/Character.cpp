#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	// std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& rhs) {
	// std::cout << "Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	*this = rhs;
}

Character& Character::operator=(const Character& rhs) {
	// std::cout << "Character copy assignation called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
	}
	_name = rhs._name;
	return *this;
}

Character::~Character() {
	// std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			// std::cout << _name << " has equiped " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Inventory full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0)
			return ;
	if (_inventory[idx]){
		_inventory[idx] = NULL;
		std::cout << _name << " has droped an item" << std::endl;
	}
	else
		std::cout << _name << " can't drop a Materia." << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx > 3 || idx < 0)
			return ;
	if (_inventory[idx]){
		_inventory[idx]->use(target);
	}
	else 
		std::cout << "No materia equiped." << std::endl;
	return ;
}