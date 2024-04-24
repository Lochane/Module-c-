/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:35:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 02:39:01 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Manhattan Project"), _signed(0), _signGrade(5), _execGrade(1){
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade) : _name(name), \
		_signed(0), _signGrade(sign_grade), _execGrade(exec_grade){
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw Form::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(const Form& rhs) : _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade){
	*this = rhs;
}

Form& Form::operator=(const Form& rhs) {
	this->_signed = rhs._signed;
	return *this;
}

Form::~Form() {
}

bool Form::beSigned(Bureaucrat &Bureaucrat){
	if (Bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
	return this->_signGrade;
}

std::string Form::getName() const{
	return (this->_name);
}

int	Form::getSignGrade() const{
	return (this->_signGrade);
}

int Form::getExecGrade() const{
	return (this->_execGrade);
}

bool Form::getSigned() const{
	return (this->_signed);
}

const char* Form::GradeTooHighException::what() const throw(){
	return "Grade too high\n";
}

const char* Form::GradeTooLowException::what() const throw(){
	return "Grade too low\n";
}

std::ostream &operator<<(std::ostream &lhs, const Form &rhs){
	if (rhs.getSigned() == true)
		lhs << rhs.getName() << " form is signed." << std::endl << "\tSignature grade : " \
				<< rhs.getSignGrade() << std::endl << "\tExecution grade : " << rhs.getExecGrade() << std::endl; 
	else
		lhs << rhs.getName() << " form is not signed." << std::endl << "\tSignature grade : " \
				<< rhs.getSignGrade() << std::endl << "\tExecution grade : " << rhs.getExecGrade() << std::endl;
	return lhs;
}