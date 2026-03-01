/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:30:48 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/07 19:30:51 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
			std::string	_target;

	public:
			PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
			~PresidentialPardonForm();
			PresidentialPardonForm(PresidentialPardonForm const &src);
			PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

			void	execute(Bureaucrat const &executor) const;
};

#endif
