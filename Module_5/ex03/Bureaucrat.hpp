/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:30:04 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 16:25:27 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"


class AForm;

class Bureaucrat {
	
	private : 
		const std::string	_name;
		int					_grade;
	
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& rhs);

		const std::string	getName();
		int					getGrade();
		const std::string	getName() const;
		int					getGrade() const;

		void	signForm(AForm &form);
		void	incrementGrade();
		void	decrementGrade();
		void	executeForm(AForm const & form) const;
		
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

} ;
	std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);

#endif