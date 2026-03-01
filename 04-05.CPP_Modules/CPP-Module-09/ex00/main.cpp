/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:15:18 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:15:19 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ((std::cout << "(!) ERROR: Invalid input argument.\n"), 1);
	
	std::ifstream	ifs;

	ifs.open(argv[1]);
	if (ifs.fail())
		return ((std::cout << "(!) ERROR: Unable to open input file.\n"), 1);

	std::string	line;
	
	std::getline(ifs, line);
	if (line != "date | value")
		return ((std::cout << "(!) ERROR: Invalid input file format.\n"), 1);

	try
	{
		BitcoinExchange	exchange;

		while (std::getline(ifs, line))
		{
			try
			{
				std::string	date;
				float		btc;
				exchange.verifyData(line, date, btc, " | ");
				if (btc < 0)
					throw std::invalid_argument("not a positive number");
				if (btc > 1000)
					throw std::invalid_argument("too large a number");

				float	value = btc * exchange.getValue(date);

				std::cout << date << " => " << btc << " = " << value << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "(!) ERROR: " << e.what() << std::endl;
			}
		}
		ifs.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "(!) ERROR: " << e.what() << std::endl;
	}

	return 0;
}
