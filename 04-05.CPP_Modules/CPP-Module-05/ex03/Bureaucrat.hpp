#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
			std::string const	_name;
			unsigned int		_grade;

	public:
			Bureaucrat();
			Bureaucrat(std::string const &name, int const &grade);
			~Bureaucrat();
			Bureaucrat(Bureaucrat const &src);
			Bureaucrat &operator=(Bureaucrat const &src);

			std::string		getName() const;
			unsigned int	getGrade() const;

			void	incrementGrade();
			void	decrementGrade();
			void	signForm(AForm &form);
			void	executeForm(AForm const &form) const;

			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &src);

#endif
