/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:12 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 18:16:16 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private :
		const std::string _name;
		bool		_signed;
		const int	_signGrade;
		const int	_execGrade;
		virtual void executeAction() const = 0;
			
	public :
		AForm();
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(const AForm& rhs);
		virtual ~AForm();
		AForm &operator=(const AForm& rhs);

		bool beSigned(Bureaucrat &Bureaucrat);
		std::string getName() const;
		int	getSignGrade() const;
		int getExecGrade() const;
		bool getSigned() const;
		void execute(Bureaucrat const & executor) const;

	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormNotSigned : public std::exception
	{
		virtual const char* what() const throw();
	};
};

	std::ostream &operator<<(std::ostream &lhs, const AForm &rhs);

#endif