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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal
{
	protected:
			std::string	_type;

	public:
			Animal();
			virtual ~Animal();
			Animal(Animal const &src);
			Animal	&operator=(Animal const &src);

			std::string	getType() const;
			void	setType(std::string type);

			virtual void	makeSound() const;
};

#endif
