/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:11:38 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 18:11:39 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>

class AAnimal
{
	protected:
			std::string	_type;

	public:
			AAnimal();
			virtual ~AAnimal();
			AAnimal(AAnimal const &src);
			AAnimal	&operator=(AAnimal const &src);

			virtual std::string	getType() const;
			virtual void	setType(std::string type);

			virtual void	makeSound() const = 0;
};

#endif
