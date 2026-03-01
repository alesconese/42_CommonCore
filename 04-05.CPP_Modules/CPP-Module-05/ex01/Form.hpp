/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:59 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:20:00 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
			std::string const	_name;
			bool				_signed;
			unsigned int const	_sign_grade;
			unsigned int const	_exec_grade;

	public:
			Form();
			Form(std::string name, unsigned int sign_grade, unsigned int exec_grade);
			~Form();
			Form(Form const &src);
			Form &operator=(Form const &src);

			std::string		getName() const;
			bool			getSigned() const;
			unsigned int	getSignGrade() const;
			unsigned int	getExecGrade() const;

			void	beSigned(Bureaucrat const &bureaucrat);

			class GradeTooHighException : public std::exception
			{
				const char *what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				const char *what() const throw();
			};
};

std::ostream	&operator<<(std::ostream &os, Form const &src);

#endif
