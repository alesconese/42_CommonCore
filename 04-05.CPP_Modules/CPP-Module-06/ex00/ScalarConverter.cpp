/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:58:30 by ade-tole          #+#    #+#             */
/*   Updated: 2024/12/05 18:58:32 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "* ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "* ScalarConverter destructor called: " << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	std::cout << "* ScalarConverter copy constructor called" << std::endl;
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
	std::cout << "* ScalarConverter copy assignment constructor called" << std::endl;
	(void)src;
	return *this;
}

void	convertSpecial(std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input.find("inf") != std::string::npos)
	{
		std::cout << "float: " << input[0] << "inff" << std::endl;
		std::cout << "double: " << input[0] << "inf" << std::endl;
	}
	else
	{
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
	}
}

void	convertChar(std::string input)
{
	if (!isprint(input[0]))
		std::cout << "(!) Non-displayable characters not supported." << std::endl;
	else
	{
		std::cout << "char: '" << input[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
	}
}

void	convertNumbers(std::string input)
{
	long double	input_ld = std::strtold(input.c_str(), NULL);

	if (input_ld > std::numeric_limits<char>::max() || \
		input_ld < std::numeric_limits<char>::min())
		std::cout << "char: overflow" << std::endl;
	else if (!isprint(static_cast<char>(input_ld)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input_ld) << "'" << std::endl;

	if (input_ld > std::numeric_limits<int>::max() || input_ld < std::numeric_limits<int>::min())
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input_ld) << std::endl;

	if (input_ld > std::numeric_limits<float>::max() || input_ld < -std::numeric_limits<float>::max())
		std::cout << "float: overflow" << std::endl;
	else if (std::floor(static_cast<float>(input_ld)) == static_cast<float>(input_ld) && input_ld < 1000000)
		std::cout << "float: " << static_cast<float>(input_ld) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(input_ld) << "f" << std::endl;
	
	if (input_ld > std::numeric_limits<double>::max() || input_ld < -std::numeric_limits<double>::max())
		std::cout << "double: overflow" << std::endl;
	else if (std::floor(static_cast<double>(input_ld)) == static_cast<double>(input_ld) && input_ld < 1000000)
		std::cout << "double: " << static_cast<double>(input_ld) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(input_ld) << std::endl;	
}

void	checkNumbers(std::string input)
{
	bool	dot = false;
	bool	error = false;

	for (std::string::iterator it = input.begin(); it != input.end(); it++)
	{
		if (!isdigit(*it))
		{
			if (it == input.begin() && *it == '-')
				continue;
			else if (it == input.end()-1 && *it == 'f')
				continue;
			else if (it != input.begin() && it != input.end()-1 && *it == '.' && isdigit(*(it+1)))
			{
				if (!dot)
					dot = true;
				else
					error = true;
			}
			else
				error = true;
		}
	}
	if (error)
		std::cout << "(!) Wrong argument!\n";
	else
		convertNumbers(input);
}

void	ScalarConverter::convert(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "+inf" || input == "nan")
		convertSpecial(input);
	else if (input.size() == 1 && !isdigit(input[0]))
		convertChar(input);
	else
		checkNumbers(input);
}
