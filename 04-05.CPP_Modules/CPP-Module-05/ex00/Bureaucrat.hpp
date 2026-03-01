/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:00 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/21 18:41:32 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

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
			void		incrementGrade();
			void		decrementGrade();

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
