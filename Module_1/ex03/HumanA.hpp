#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

	private :
		std::string name;
		Weapon &weapon;

	public :
		HumanA(std::string sname, Weapon& sweapon);
		~HumanA();
		void attack();
} ;

#endif