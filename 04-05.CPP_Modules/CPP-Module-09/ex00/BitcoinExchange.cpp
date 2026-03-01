/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:14:58 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:15:01 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "* BitcoinExchange default constructor called." << std::endl;
	
	loadData();
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "* BitcoinExchange destructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	std::cout << "* BitcoinExchange copy constructor called." << std::endl;
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	std::cout << "* BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &src)
		_historic = src._historic;
	
	return *this;
}

void	BitcoinExchange::loadData()
{
	std::ifstream	data_file;
	std::string		line;

	data_file.open("data.csv");
	if (data_file.fail())
		throw std::runtime_error("unable to open data file.");

	std::getline(data_file, line);
	if (line != "date,exchange_rate")
		throw std::runtime_error("invalid data file format.");
	try
	{
		while (std::getline(data_file, line))
		{
			std::string	date;
			float		value;
			this->verifyData(line, date, value, ",");

			_historic[date] = value;
		}
	}
	catch(const std::exception &e)
	{
		throw std::runtime_error("corrupt data.csv");
	}
	data_file.close();
}

bool	BitcoinExchange::checkValidDate(const tm &tm)
{
	switch (tm.tm_mon)
	{
		case 0:
		case 2:
		case 4:
		case 6:
		case 7:
		case 9:
		case 11:
			return (tm.tm_mday <= 31);
		case 3:
		case 5:
		case 8:
		case 10:
			return (tm.tm_mday <= 30);
		case 1:
			if (((tm.tm_year + 1900) % 4 == 0 && (tm.tm_year + 1900) % 100 != 0) \
				|| (tm.tm_year + 1900) % 400 == 0)
				return (tm.tm_mday <= 29);
			else
				return (tm.tm_mday <= 28);
		default:
			return (false);
	}
}

float	BitcoinExchange::getValue(std::string const &date)
{
	if (date < _historic.begin()->first || date > (--_historic.end())->first)
		throw std::invalid_argument("date outside database range");

	std::map<std::string, float>::iterator	it;

	it = _historic.find(date);
	if (it == _historic.end())
	{
		it = _historic.lower_bound(date);
		it--;
	}

	return (it->second);
}

void	BitcoinExchange::verifyData(std::string line, std::string &date, float &btc, std::string const &separator)
{
	if (line.find(separator) == std::string::npos)
		throw std::invalid_argument("bad input => " + line);

	date = line.substr(0, line.find(separator));
	std::string	btc_str = line.substr(line.find(separator) + separator.length());
	if (date.empty() || btc_str.empty())
		throw std::invalid_argument("bad input => " + line);

	struct tm	tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || !this->checkValidDate(tm))
		throw std::invalid_argument("invalid date => " + date);

	char	*endptr;
	btc = std::strtof(btc_str.c_str(), &endptr);
	if (*endptr != '\0')
		throw std::invalid_argument("bad input => " + line);
}
