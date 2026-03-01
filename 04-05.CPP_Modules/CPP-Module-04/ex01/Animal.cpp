/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:02:42 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:02:44 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Unknown Animal")
{
	std::cout << "* Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "* Animal default destrutor called" << std::endl;
}

Animal::Animal(Animal const &src)
{
	*this = src;
	std::cout << "* Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* Animal copy assignment operator called" << std::endl;
	return *this;
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

void	Animal::makeSound() const
{
	std::cout << "* Undetermined sound... *" << std::endl;
}
