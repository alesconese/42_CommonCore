/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:37:26 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:37:28 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Dog : public Animal
{
	private:
			Brain	*_brain;
			
	public:
			Dog();
			~Dog();
			Dog(Dog const &src);
			Dog	&operator=(Dog const &src);

			void	makeSound() const;
};

#endif
