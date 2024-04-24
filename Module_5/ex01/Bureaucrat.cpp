/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:45:27 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 02:06:50 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Brigitte de la compta"), _grade(37){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
		if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name) {
	*this = rhs;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	this->_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName(){
	return this->_name;
}

int	Bureaucrat::getGrade(){
	return this->_grade;
}

const std::string Bureaucrat::getName() const{
	return this->_name;
}

int	Bureaucrat::getGrade() const{
	return this->_grade;
}

void Bureaucrat::signForm(Form &form){
	try {
		form.beSigned(*this);
	}
	catch(std::exception &e){
		std::cout << (*this).getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
		std::cout << (*this).getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::increment(){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high, must be from 1 to 150\n";
};

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low, must be from 1 to 150\n";
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs){
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() <<  "." << std::endl;
	return lhs;
}