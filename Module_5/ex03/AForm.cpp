/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:35:08 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 02:39:01 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(0), _signGrade(5), _execGrade(1){
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : _name(name), \
		_signed(0), _signGrade(sign_grade), _execGrade(exec_grade){
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw AForm::GradeTooLowException();
	else if (this->_signGrade < 1 || this->_execGrade < 1)
		throw AForm::GradeTooHighException();
	return ;
}

AForm::AForm(const AForm& rhs) : _name(rhs._name), _signGrade(rhs._signGrade), _execGrade(rhs._execGrade){
	*this = rhs;
}

AForm& AForm::operator=(const AForm& rhs) {
	this->_signed = rhs._signed;
	return *this;
}

AForm::~AForm() {
}

bool AForm::beSigned(Bureaucrat &Bureaucrat){
	if (Bureaucrat.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
	return this->_signGrade;
}

std::string AForm::getName() const{
	return (this->_name);
}

int	AForm::getSignGrade() const{
	return (this->_signGrade);
}

int AForm::getExecGrade() const{
	return (this->_execGrade);
}

bool AForm::getSigned() const{
	return (this->_signed);
}

const char* AForm::GradeTooHighException::what() const throw(){
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw(){
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw(){
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &lhs, const AForm &rhs){
	if (rhs.getSigned() == true)
		lhs << rhs.getName() << " form is signed." << std::endl << "\tSignature grade : " \
				<< rhs.getSignGrade() << std::endl << "\tExecution grade : " << rhs.getExecGrade() << std::endl; 
	else
		lhs << rhs.getName() << " form is not signed." << std::endl << "\tSignature grade : " \
				<< rhs.getSignGrade() << std::endl << "\tExecution grade : " << rhs.getExecGrade() << std::endl;
	return lhs;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (this->_execGrade < executor.getGrade())
		throw  AForm::GradeTooLowException();
	if (this->_signed == false)
		throw AForm::FormNotSigned();
	executeAction();
}