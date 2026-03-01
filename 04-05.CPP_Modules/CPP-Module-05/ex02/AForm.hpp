/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:21:56 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:21:57 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
			std::string const	_name;
			bool				_signed;
			unsigned int const	_sign_grade;
			unsigned int const	_exec_grade;

	public:
			AForm();
			AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade);
			virtual ~AForm();
			AForm(AForm const &src);
			AForm &operator=(AForm const &src);

			std::string		getName() const;
			bool			getSigned() const;
			unsigned int	getSignGrade() const;
			unsigned int	getExecGrade() const;

			void	beSigned(Bureaucrat const &bureaucrat);
			virtual void	execute(Bureaucrat const &executor) const = 0;

			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};

			class NotSignedException : public std::exception
			{
				const char *what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &os, AForm const &src);

#endif
