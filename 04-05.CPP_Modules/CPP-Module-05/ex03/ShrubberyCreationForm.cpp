/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:03:15 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/08 19:03:17 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), _target("Undefined target")
{
	std::cout << "* Shrubbery Creation Form Default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "* Shrubbery Creation Form constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "* Shrubbery Creation Form destructor called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target)
{
	std::cout << "* Shrubbery Creation Form copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "* Shrubbery Creation Form copy assignment constructor called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::NotSignedException();
	else
	{
		std::ofstream	ofs;

		ofs.open((_target + "_shrubbery").c_str());
		if (ofs.fail())
			std::cout << "(!) ERROR: Unable to create new file. " << std::strerror(errno) << std::endl;
		else
		{
			ofs << "     &&&&&&&&                 &&&&&&&&                 &&&&&&&&                 &&&&&&&&" << std::endl;
			ofs << "  &&&&&&&&&&&& &&&&        &&&&&&&&&&&& &&&&        &&&&&&&&&&&& &&&&        &&&&&&&&&&&& &&&&" << std::endl;
			ofs << " &&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&&&" << std::endl;
			ofs << "&&&&&&&&& &&& &&&&&&&&&  &&&&&&&&& &&& &&&&&&&&&  &&&&&&&&& &&& &&&&&&&&&  &&&&&&&&& &&& &&&&&&&&&" << std::endl;
			ofs << "  &&&&&&  && &&&&&&&&      &&&&&&  && &&&&&&&&      &&&&&&  && &&&&&&&&      &&&&&&  && &&&&&&&&" << std::endl;
			ofs << "      \\\\\\//  /&&&&             \\\\\\//  /&&&&             \\\\\\//  /&&&&             \\\\\\//  /&&&&" << std::endl;
			ofs << "        \\\\\\////                  \\\\\\////                  \\\\\\////                  \\\\\\////" << std::endl;
			ofs << "         ||||/                    ||||/                    ||||/                    ||||/" << std::endl;
			ofs << "         ||||\\                    ||||\\                    ||||\\                    ||||\\" << std::endl;
			ofs << "         |||||                    |||||                    |||||                    |||||" << std::endl;
			ofs << "......../|||||\\................../|||||\\................../|||||\\................../|||||\\........" << std::endl;
			ofs.close();
			std::cout << "* Successfully created " << _target << "_shrubbery" << std::endl;
		}
	}
}
