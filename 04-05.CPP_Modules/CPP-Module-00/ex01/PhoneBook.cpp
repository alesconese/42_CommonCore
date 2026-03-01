/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:32:16 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 19:40:28 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_n_contact = 0;
	_full = 0;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::show_commands()
{
	std::cout << "* Available commands: 'ADD', 'SEARCH', 'EXIT'" << std::endl;
}

void	PhoneBook::add_contact()
{
	if (_n_contact > 7)
	{
		_n_contact = 0;
		_full = 1;
	}
	std::cout << "* Storing contact #" << _n_contact+1 << std::endl;
	if (_full)
		std::cout << "* Caution! Overwriting previously stored contact." << std::endl;
	_contacts[_n_contact].add_info();
	std::cout << "* Successfully stored contact #" << _n_contact+1 << std::endl;
	_n_contact++;
}

void	PhoneBook::search_contact()
{
	std::string	buff;
	
	if (_n_contact == 0 && _full == 0)
	{
		std::cout << "! PhoneBook empty. Search command unavailable." << std::endl;
		return;
	}
	std::cout << std::right << "|" << std::setw(10) << "Index";
	std::cout << std::right << "|" << std::setw(10) << "First Name";
	std::cout << std::right << "|" << std::setw(10) << "Last Name";
	std::cout << std::right << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
		_contacts[i].display_short(i);
	std::cout << "* Enter contact index to display full information, or 0 to exit." << std::endl;
	while (!buff.length())
	{
		std::cout << "* Index: ";
		if (!std::getline(std::cin, buff))
			return;
		if (buff.length() == 1 && buff[0] == '0')
			return;
		if (!(buff.length() == 1) || buff[0] < '0' || buff[0] > '8')
		{
			std::cout << "! Invalid index." << std::endl;
			buff.erase();
		}
	}
	_contacts[buff[0] - '0' - 1].display_full();
}
