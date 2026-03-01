/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:12:43 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:12:51 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "* A Zombie has come back to life!" << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "* Zombie " << _name << " has come back to life!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "* Zombie " << _name << " has died (again)..." << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}
