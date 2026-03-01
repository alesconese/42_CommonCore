/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:09:26 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/19 20:09:27 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("(null)"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "* ClapTrap default constructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "* ClapTrap default constructor called: " << _name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "* ClapTrap default destructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
	std::cout << "* ClapTrap copy constructor called: " << _name << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	std::cout << "* ClapTrap copy assignment operator called: " << _name << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (!_hitPoints)
		std::cout << "* ClapTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ClapTrap <" << _name << "> tries to attack <" << target << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* ClapTrap <" << _name << "> attacks <" << target << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::attack(ClapTrap &target)
{
	if (!_hitPoints)
		std::cout << "* ClapTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ClapTrap <" << _name << "> tries to attack <" << target._name << "> but has no energy!" << std::endl;
	else
	{
		std::cout << "* ClapTrap <" << _name << "> attacks <" << target._name << "> for [" << _attackDamage << "] damage!" << std::endl;
		_energyPoints--;
		target.takeDamage(_attackDamage);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "* ClapTrap <" << _name << "> has taken [" << amount << "] damage!" << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "* ClapTrap <" << _name << "> has no HP left and is incapacitated!" << std::endl;
		_hitPoints = 0;
	}
}

void	ClapTrap::beRapaired(unsigned int amount)
{
	if (!_hitPoints)
		std::cout << "* ClapTrap <" << _name << "> has no HP left. It cannot move!" << std::endl;
	else if (!_energyPoints)
		std::cout << "* ClapTrap <" << _name << "> tries to repair itself but has no energy!" << std::endl;
	else
	{
		if (_hitPoints + amount > 10)
			amount = 10 - _hitPoints;
		std::cout << "* ClapTrap <" << _name << "> repairs itself and recovers [" << amount << "] HP!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints == 10)
			std::cout << "* ClapTrap <" << _name << "> is at full HP!" << std::endl;
	}
}
std::string	ClapTrap::getName() const
{
	return _name;
}

int		ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

int		ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

int		ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
	std::cout << "* ClapTrap <" << _name << ">'s HP have been set to " << hitPoints << std::endl;
	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	std::cout << "* ClapTrap <" << _name << ">'s Energy Points have been set to " << energyPoints << std::endl;
	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	std::cout << "* ClapTrap <" << _name << ">'s Attack Damage have been set to " << attackDamage << std::endl;
	_attackDamage = attackDamage;
}

void	ClapTrap::setName(std::string name)
{
	std::cout << "* ClapTrap <" << name << ">'s Attack Damage have been set" << std::endl;
	_name = name;
}
