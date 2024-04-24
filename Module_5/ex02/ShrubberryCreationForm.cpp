/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:41:16 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 16:38:12 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberryCreationForm.hpp"
#include "AForm.hpp"

ShrubberryCreationForm::ShrubberryCreationForm() : AForm("Shrubberry", 145, 137), _target("Default"){}

ShrubberryCreationForm::ShrubberryCreationForm(const std::string target) : AForm("Shrubberry", 145, 137), _target(target){}

ShrubberryCreationForm::ShrubberryCreationForm(const ShrubberryCreationForm& rhs) : AForm(rhs), _target(rhs._target) {
	*this = rhs;	
}

ShrubberryCreationForm& ShrubberryCreationForm::operator=(const ShrubberryCreationForm& rhs) {
	(void)rhs;
	return *this;
}

ShrubberryCreationForm::~ShrubberryCreationForm() {}

void ShrubberryCreationForm::executeAction() const{
	std::ofstream file(std::string(this->_target + "_shruberry").c_str());
	if (file.is_open())
	{
		file << "                                  # #### ####" << std::endl;
		file << "                                ### //#|### |/####" << std::endl;
		file << "                               ##//#/ /||/##/_/##/_#" << std::endl;
		file << "                             ###  //###|/ // # ###" << std::endl;
		file << "                           ##_/_#/_/## | #/###_/_####" << std::endl;
		file << "                          ## #### # / #| /  #### ##/##" << std::endl;
		file << "                           __#_--###`  |{,###---###-~" << std::endl;
		file << "                                      /}{" << std::endl;
		file << "                                      }}{" << std::endl;
		file << "                                      }}{" << std::endl;
		file << "                                 ejm  {{}" << std::endl;
		file << "                                , -=-~{ .-^- _" << std::endl;
		file.close();
	} else {
		std::cout << "Error : Can't open file" << std::endl;
	}
}