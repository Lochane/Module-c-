#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "SUBJECT TEST" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl;


	std::cout << "OTHER TEST" << std::endl << std::endl;
	IMateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	AMateria* test = src2->createMateria("cure");
	delete test;
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Ice());

	Character* me2 = new Character("louis");

	tmp = src2->createMateria("ice");
	me2->equip(tmp);
	tmp = src2->createMateria("cure");
	me2->equip(tmp);
	AMateria* tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	tmp = src2->createMateria("cure");
	me2->equip(tmp);
	tmp = src2->createMateria("cure");
	me2->equip(tmp);
	delete tmp;

	ICharacter* cpy = new Character(*me2);
	ICharacter* dummy = new Character("dummy");

	std::cout << std::endl;

	cpy->use(0, *dummy);
	cpy->use(1, *dummy);
	cpy->use(2, *dummy);
	cpy->use(3, *dummy);
	cpy->use(4, *dummy);

	me2->unequip(2);
	me2->use(2, *dummy);
	delete tmp2;

	std::cout << std::endl;

	delete cpy;
	delete me2;
	delete dummy;
	delete src2;

	return 0;

}