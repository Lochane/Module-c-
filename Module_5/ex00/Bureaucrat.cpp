/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:45:27 by lsouquie          #+#    #+#             */
/*   Updated: 2024/04/24 14:53:45 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(37){
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

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name){
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

void Bureaucrat::incrementGrade(){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade(){
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
