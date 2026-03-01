/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:03:15 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/08 19:03:17 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Undefined target")
{
	std::cout << "* Robotomy Request Form Default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << "* Robotomy Request Form constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "* Robotomy Request Form destructor called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "* Robotomy Request Form copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	std::cout << "* Robotomy Request Form copy assignment constructor called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
	{
		std::cout << "* Performing robotomy on " << _target << std::endl;
		sleep(1);
		std::cout << "* 🤖🔫 BRRRRRRRRR..." << std::endl;
		sleep(1);
		std::srand(std::time(0));
		if (rand() % 2)
			std::cout << "* Robotomy successfully performed on " << _target << std::endl;
		else
			std::cout << "* Robotomy on " << _target << " FAILED!" << std::endl;
	}
}
