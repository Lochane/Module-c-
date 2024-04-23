#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& rhs) {
	*this = rhs;
}

MateriaSource &MateriaSource::operator=(const MateriaSource& rhs) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = rhs._inventory[i];
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++){
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
		return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++){
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}