/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:07:41 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/20 19:07:43 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "* ScavTrap default constructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "* ScavTrap default constructor called: " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "* ScavTrap default destructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	*this = src;
	std::cout << "* ScavTrap copy constructor called: " << _name << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	std::cout << "* ScavTrap copy assignment operator called: " << _name << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!_hitPoints)
		std::cout << "* ScavTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ScavTrap <" << _name << "> tries to attack <" << target << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* ScavTrap <" << _name << "> attacks <" << target << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::attack(ClapTrap &target)
{
	if (!_hitPoints)
		std::cout << "* ScavTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ScavTrap <" << _name << "> tries to attack <" << target.getName() << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* ScavTrap <" << _name << "> attacks <" << target.getName() << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
		target.takeDamage(_attackDamage);
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "* ScavTrap <" << _name << "> has taken [" << amount << "] damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "* ScavTrap <" << _name << "> has no HP left and is incapacitated!" << std::endl;
		_hitPoints = 0;
	}
}

void	ScavTrap::beRapaired(unsigned int amount)
{
	if (!_hitPoints)
		std::cout << "* ScavTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ScavTrap <" << _name << "> tries to repair itself but has no energy!" << std::endl;
	else
	{
		if (_hitPoints + amount > 100)
			amount = 100 - _hitPoints;
		std::cout << "* ScavTrap <" << _name << "> repairs itself and recovers [" << amount << "] HP!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints == 100)
			std::cout << "* ScavTrap <" << _name << "> is at full HP!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "* ScavTrap <" << _name << "> is now guarding the Gate!" << std::endl;
}
