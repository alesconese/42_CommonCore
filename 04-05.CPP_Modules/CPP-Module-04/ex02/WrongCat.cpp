/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:54:01 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:54:03 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "* WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "* WrongCat default destrutor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src)
{
	*this = src;
	std::cout << "* WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		_type = src._type;
	std::cout << "* WrongCat copy assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "* Meowww... *" << std::endl;
}
