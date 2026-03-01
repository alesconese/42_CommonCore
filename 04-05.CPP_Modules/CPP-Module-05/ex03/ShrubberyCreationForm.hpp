/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:30:48 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:30:51 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <fstream>
# include <cstring>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
			std::string	_target;

	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			~ShrubberyCreationForm();
			ShrubberyCreationForm(ShrubberyCreationForm const &src);
			ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &src);

			void	execute(Bureaucrat const &executor) const;
};

#endif
