/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberryCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:57:38 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 16:32:32 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberryCreationForm : public AForm {
	private :
		const std::string _target;
	
	public :
		ShrubberryCreationForm();
		ShrubberryCreationForm(const std::string target);
		ShrubberryCreationForm(const ShrubberryCreationForm& rhs);
		~ShrubberryCreationForm();
		ShrubberryCreationForm &operator=(const ShrubberryCreationForm& rhs);

		void	executeAction() const;
};

#endif