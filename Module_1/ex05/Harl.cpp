#include "Harl.hpp"

Harl::Harl() {
	this->tab_ft[0] = &Harl::debug;
	this->tab_ft[1] = &Harl::info;
	this->tab_ft[2] = &Harl::warning;
	this->tab_ft[3] = &Harl::error;
	this->ref[0] = "debug";
	this->ref[1] = "info";
	this->ref[2] = "warning";
	this->ref[3] = "error";
	return ;
}

Harl::~Harl() {
	std::cout << "Harl has been kicked out of the restaurant" << std::endl;
	return ;
}

void Harl::debug(){
		std::cout << "\"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !\"" << std::endl << std::endl;
		return ;
}

void Harl::info(){
	std::cout << "\"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\"" << std::endl << std::endl;
}

void Harl::warning(){
	std::cout << "\"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\"" << std::endl << std::endl;
	
}

void Harl::error(){
	std::cout << "\"This is unacceptable ! I want to speak to the manager now.\"" << std::endl << std::endl;
	
}

void Harl::complain(std::string level) {
	for (int i = 0; i < 4; i++) {
		if (this->ref[i].compare(level) == 0){
			(this->*tab_ft[i])();
			return ;
		}
	}
}