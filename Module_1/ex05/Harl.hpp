#ifndef HARL_HPP
#define HARL_HPP


#include <iostream>
#include <string>

class Harl {
	private : 
		void (Harl::*tab_ft[4])(void);
		std::string ref[4];
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public :

		Harl();
		~Harl();
		void complain(std::string level) ;
};

#endif