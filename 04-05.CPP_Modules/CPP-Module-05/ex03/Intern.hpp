#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public:
			Intern();
			~Intern();
			Intern(Intern const &src);
			Intern &operator=(Intern const &src);

			AForm	*makeForm(std::string name, std::string target);

			class InvalidFormException : public std::exception
			{
				const char *what() const throw();
			};
};

#endif
