/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:30:48 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:30:51 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <cstdlib>
# include <ctime>
# include <unistd.h>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			std::string	_target;

	public:
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			~RobotomyRequestForm();
			RobotomyRequestForm(RobotomyRequestForm const &src);
			RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);

			void	execute(Bureaucrat const &executor) const;
};

#endif
