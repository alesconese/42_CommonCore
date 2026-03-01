/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:31:00 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:31:02 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(std::string input)
{
	//std::cout << "* RPN constructor called." << std::endl;

	this->isValidInput(input);
	std::cout << this->getResult(input) << std::endl;
}

RPN::RPN(RPN const &src)
{
	//std::cout << "* RPN copy constructor called" << std::endl;

	*this = src;
}

RPN::~RPN()
{
	//std::cout << "* RPN destructor called." << std::endl;
}

RPN &RPN::operator=(RPN const &src)
{
	//std::cout << "* RPN copy assignment operator called" << std::endl;

	if(this != &src)
		_operands = src._operands;

	return *this;
}

void	RPN::isValidInput(std::string input)
{
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("invalid characters in input");
	
	if (input.find_first_of("+-*/") == std::string::npos)
		throw std::invalid_argument("no operators in input");
}

float	RPN::getResult(std::string input)
{
	std::istringstream	iss(input);
	std::string			token;

	while (iss >> token)
	{
		if (token.length() != 1)
		{
			if (token[0] == '-' && isdigit(token[1]) && token.length() == 2)
				_operands.push(std::strtof(token.c_str(), NULL));
			else if (token.find_first_not_of("0123456789") == std::string::npos)
				throw std::invalid_argument("operands must be single-digit numbers");
			else
				throw std::invalid_argument("operands and operators must be separated by a space");
		}
		else if (isdigit(token[0]))
			_operands.push(std::strtof(token.c_str(), NULL));
		else if (token.find_first_of("+-*/") != std::string::npos)
		{
			if (_operands.size() < 2)
				throw std::invalid_argument("not enough operands for operator");

			float second = _operands.top();
			_operands.pop();
			float first = _operands.top();
			_operands.pop();

			switch (token[0])
			{
				case '+':
					_operands.push(first + second);
					break;
				case '-':
					_operands.push(first - second);
					break;
				case '*':
					_operands.push(first * second);
					break;
				case '/':
					if (second == 0)
						throw std::invalid_argument("division by zero");
					_operands.push(first / second);
					break;
			}
		}
	}
	if (_operands.size() != 1)
		throw std::invalid_argument("not enough operators");
	return _operands.top();
}
