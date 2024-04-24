/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:51:12 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 03:11:55 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {

	private :
		const std::string _name;
		bool		_signed;
		const int	_signGrade;
		const int	_execGrade;
			
	public :
		Form();
		Form(const std::string name, const int sign_grade, const int exec_grade);
		Form(const Form& rhs);
		~Form();
		Form &operator=(const Form& rhs);

		bool beSigned(Bureaucrat &Bureaucrat);
		std::string getName() const;
		int	getSignGrade() const;
		int getExecGrade() const;
		bool getSigned() const;

	
	class GradeTooHighException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

	std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif