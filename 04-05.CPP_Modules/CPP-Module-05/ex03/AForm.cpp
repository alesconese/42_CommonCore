/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:42 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:21:44 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unnamed Form"), _signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "* AForm Default constructor called.\n";
}

AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "* AForm constructor called: " << _name << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	std::cout << "* AForm destructor called: " << _name << std::endl;
}
	
AForm::AForm(AForm const &src) : _name(src._name), _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "* AForm copy constructor called\n";
	*this = src;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << "* AForm copy assignment constructor called" << std::endl;
	if (this != &src)
		_signed = src._signed;
	return *this;
}

std::string		AForm::getName() const { return _name; }

bool	AForm::getSigned() const { return _signed; }

unsigned int	AForm::getSignGrade() const { return _sign_grade; }

unsigned int	AForm::getExecGrade() const { return _exec_grade; }

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _sign_grade)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this form.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this form.");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed yet.");
}

std::ostream	&operator<<(std::ostream &os, AForm const &src)
{
	os << src.getName() << ". Sign Grade " << src.getSignGrade() << ", Execute Grade " << src.getExecGrade() << ". ";
	if (src.getSigned())
		os << "Signed.";
	else
		os << "Unsigned.";
	return os;
}
