/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:37:57 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/02 20:37:59 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug() const
{
	std::cout << "[ DEBUG ]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info() const
{
	std::cout << "[ INFO ]\n I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() const
{
	std::cout << "[ WARNING ]\n I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error() const
{
	std::cout << "[ ERROR ]\n This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{
	std::string	level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f_arr[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i=0; i < 4; i++)
	{
		if (level_arr[i] == level)
			return ((this->*f_arr[i])());
	}
	std::cout << "! Invalid complain level <" << level << ">. Available options: [ DEBUG ], [ INFO ], [ WARNING ], [ ERROR ]" << std::endl;
}
