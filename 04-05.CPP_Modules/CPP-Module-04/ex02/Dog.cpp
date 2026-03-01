/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:37:34 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:37:37 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "* Dog default constructor called" << std::endl;
	_brain = new Brain();
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "* Dog default destrutor called" << std::endl;
}

Dog::Dog(Dog const &src)
{
	*this = src;
	std::cout << "* Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* Dog copy assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "* Bark! Bark! *" << std::endl;
}
