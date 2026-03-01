/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:03:15 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/08 19:03:17 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon Form", 25, 5), _target("Undefined target")
{
	std::cout << "* Presidential Pardon Form Default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "* Presidential Pardon Form constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "* Presidential Pardon Form destructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "* Presidential Pardon Form copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "* Presidential Pardon Form copy assignment constructor called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
		std::cout << "* The Honorable President Zaphod Beeblebrox has pardoned " << _target << std::endl;
}
