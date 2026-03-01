/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:51:29 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:51:30 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Unknown WrongAnimal")
{
	std::cout << "* WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "* WrongAnimal default destrutor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	*this = src;
	std::cout << "* WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* Undetermined sound... *" << std::endl;
}
