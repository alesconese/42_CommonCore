#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "* Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "* Intern destructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "* Intern copy constructor called" << std::endl;
	*this = src;
}
Intern &Intern::operator=(Intern const &src)
{
	std::cout << "* Intern copy assignment constructor called" << std::endl;
	(void)src;
	return *this;
}

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	valid_forms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int 		i = -1;
	AForm		*form_ptr;

	while (++i < 3)
		if (name == valid_forms[i])
			break;
	switch (i)
	{
		case 0:
			form_ptr = new ShrubberyCreationForm(target);
			break;
		case 1:
			form_ptr = new RobotomyRequestForm(target);
			break;
		case 2:
			form_ptr = new PresidentialPardonForm(target);
			break;
		default:
			throw InvalidFormException();
	}
	std::cout << "* " << name << " Form successfully created by Intern" << std::endl;
	return form_ptr;
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Invalid form name. Intern couldn't create the requested form.");
}
