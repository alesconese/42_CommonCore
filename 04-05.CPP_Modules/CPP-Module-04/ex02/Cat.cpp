/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:13:25 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:13:26 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "* Cat default constructor called" << std::endl;
	_brain = new Brain();
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "* Cat default destrutor called" << std::endl;
}

Cat::Cat(Cat const &src)
{
	*this = src;
	std::cout << "* Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* Cat copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "* Meowww... *" << std::endl;
}
