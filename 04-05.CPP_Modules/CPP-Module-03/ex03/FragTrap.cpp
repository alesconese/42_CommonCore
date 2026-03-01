/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:28:22 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/20 20:28:23 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "* FragTrap default constructor called: " << _name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "* FragTrap default constructor called: " << _name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "* FragTrap default destructor called: " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
	*this = src;
	std::cout << "* FragTrap copy constructor called: " << _name << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	std::cout << "* FragTrap copy assignment operator called: " << _name << std::endl;
	return *this;
}

void	FragTrap::attack(const std::string &target)
{
	if (!_hitPoints)
		std::cout << "* FragTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* FragTrap <" << _name << "> tries to attack <" << target << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* FragTrap <" << _name << "> attacks <" << target << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
	}
}

void	FragTrap::attack(ClapTrap &target)
{
	if (!_hitPoints)
		std::cout << "* FragTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* FragTrap <" << _name << "> tries to attack <" << target.getName() << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* FragTrap <" << _name << "> attacks <" << target.getName() << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
		target.takeDamage(_attackDamage);
	}
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "* FragTrap <" << _name << "> has taken [" << amount << "] damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "* FragTrap <" << _name << "> has no HP left and is incapacitated!" << std::endl;
		_hitPoints = 0;
	}
}

void	FragTrap::beRapaired(unsigned int amount)
{
	if (!_hitPoints)
		std::cout << "* FragTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* FragTrap <" << _name << "> tries to repair itself but has no energy!" << std::endl;
	else
	{
		if (_hitPoints + amount > 100)
			amount = 100 - _hitPoints;
		std::cout << "* FragTrap <" << _name << "> repairs itself and recovers [" << amount << "] HP!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints == 100)
			std::cout << "* FragTrap <" << _name << "> is at full HP!" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	std::cout << "* FragTrap <" << _name << "> offers you a high five!" << std::endl;
}
