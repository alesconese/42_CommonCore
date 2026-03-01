/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:17:09 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:17:10 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon &weapon): _name(name), _weapon(&weapon)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	std::cout << _name << " attacks with their ";
	if (_weapon)
		std::cout << _weapon->getType(); 
	else
		std::cout << "bare hands";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
