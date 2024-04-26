/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:47:37 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 18:17:32 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		const std::string _target;
	
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);

		void	executeAction() const;
};

#endif