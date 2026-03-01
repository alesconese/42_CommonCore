/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:20:19 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/28 19:20:21 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "* Brain default constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "* Brain default destructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	*this = src;
	std::cout << "* Brain copy operator called" << std::endl;
}

Brain &Brain::operator=(Brain const &src)
{
	if (this != &src)
		for (int i = 0; i < 100; i++)
			_ideas[i] = src._ideas[i];
	std::cout << "* Brain copy assignment operator called" << std::endl;
	return *this;
}
