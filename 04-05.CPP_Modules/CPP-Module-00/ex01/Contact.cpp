/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:32:00 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 19:36:56 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	add_field(std::string field)
{
	std::string	buff;

	while (!buff.length())
	{
		std::cout << "* " << field << ": ";
		if (!std::getline(std::cin, buff))
			break;
		if (!buff.length())
			std::cout << "! Empty field." << std::endl;
	}
	return (buff);
}

std::string	add_number(std::string field)
{
	std::string	buff;

	while (!buff.length())
	{
		buff = add_field(field);
		if (!buff.length())
			break;
		for (unsigned int i = 0; i < buff.length(); i++)
			if (buff[i] < '0' || buff[i] > '9')
			{
				std::cout << "! Invalid number." << std::endl;
				buff.erase();
			}
	}
	return (buff);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

void    Contact::add_info()
{
	_first_name = add_field("First Name");
	_last_name = add_field("Last Name");
	_nickname = add_field("Nickame");
	_phone_number = add_number("Phone Number");
	_darkest_secret = add_field("Darkest Secret");
}

void	Contact::display_short(int index)
{
	if(!_first_name.length())
		return;
	std::cout << std::right << "|" << std::setw(10) << index+1;
	if (_first_name.length() > 10)
		std::cout << std::right << "|" << _first_name.substr(0, 9) << ".";
	else
		std::cout << std::right << "|" << std::setw(10) << _first_name;
	if (_last_name.length() > 10)
		std::cout << std::right << "|" << _last_name.substr(0, 9) << ".";
	else
		std::cout << std::right << "|" << std::setw(10) << _last_name;
	if (_nickname.length() > 10)
		std::cout << std::right << "|" << _nickname.substr(0, 9) << ".|" << std::endl;
	else
		std::cout << std::right << "|" << std::setw(10) << _nickname << "|" << std::endl;
}

void	Contact::display_full()
{
	if(!_first_name.length())
	{
		std::cout << "! Contact is not stored." << std::endl;
		return;
	}
	std::cout << "* First Name: " << _first_name << std::endl;
	std::cout << "* Last Name: " << _last_name << std::endl;
	std::cout << "* Nickname: " << _nickname << std::endl;
	std::cout << "* Phone Number: " << _phone_number << std::endl;
	std::cout << "* Darkest Secret: " << _darkest_secret << std::endl;
}
