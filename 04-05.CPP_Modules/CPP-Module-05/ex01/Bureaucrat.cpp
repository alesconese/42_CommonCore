/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:29 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/21 18:42:09 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Undefined"), _grade(150)
{
	std::cout << "* Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
	std::cout << "* Bureaucrat constructor called: " << _name << ", grade " << _grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "* Bureaucrat destructor called: " << _name << ", grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name)
{
	std::cout << "* Bureaucrat copy constructor called" << std::endl;
	*this = src;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "* Bureaucrat copy assignment constructor called" << std::endl;
	if (this != &src)
		_grade = src._grade;
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	std::cout << "* Bureaucrat " << _name << " tries to sign Form " << form.getName() << std::endl;
	if (form.getSigned())
	{
		std::cout << "(!) ERROR: Form already signed. Bureaucrat " << _name << " couldn't sign Form " << form.getName() << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << "* Bureaucrat " << _name << " successfully signed Form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "(!) ERROR: " << e.what();
		std::cout << " Bureaucrat " << _name << " couldn't sign Form " << form.getName() << std::endl;
	}
	
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade cannot be higher than 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade cannot be lower than 150.");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}
