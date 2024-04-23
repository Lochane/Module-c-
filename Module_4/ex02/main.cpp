#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const Cat k;
	//const AAnimal p;

	delete i;
	delete j;
	k.makeSound();
	// i->makeSound();
	const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat()};
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}

	return 0;
}