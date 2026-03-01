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

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("Unknown AAnimal")
{
	std::cout << "* AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "* AAnimal default destrutor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	*this = src;
	std::cout << "* AAnimal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* AAnimal copy assignment operator called" << std::endl;
	return *this;
}

std::string	AAnimal::getType() const
{
	return _type;
}

void	AAnimal::setType(std::string type)
{
	_type = type;
}

void	AAnimal::makeSound() const
{
	std::cout << "* Undetermined sound... *" << std::endl;
}
