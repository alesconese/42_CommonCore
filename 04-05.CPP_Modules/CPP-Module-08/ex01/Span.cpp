/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:02:01 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:16:45 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

struct RandomGenerator
{
	int	_max;
	RandomGenerator(int max) : _max(max) {}

	int	operator()() const
	{
		return std::rand() % _max;
	}
};

Span::Span(): _N(0)
{
	std::cout << "* Span default constructor called. Capacity: 0" << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
	std::cout << "* Span constructor called. Capacity: " << _N << std::endl;
}

Span::~Span()
{
	std::cout << "* Span default destructor called" << std::endl;
}

Span::Span(Span const &src): _N(src._N)
{
	std::cout << "* Span copy constructor called" << std::endl;
	*this = src;
}

Span &Span::operator=(Span const &src)
{
	std::cout << "* Span copy assignment operator called" << std::endl;
	if (this != &src)
	{
		_N = src._N;
		_numbers = src._numbers;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (_numbers.size() == _N)
		throw MaxCapacityException();
	_numbers.push_back(num);
	std::cout << "* Number added to container: " << num << std::endl;
}

void	Span::addMany(unsigned int amount)
{
	unsigned int	prev = _numbers.size();

	if (prev + amount > _N)
		throw MaxCapacityException();

	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}

	_numbers.resize(prev + amount);
	std::generate_n(_numbers.begin() + prev, amount, RandomGenerator(amount * 10));

	std::cout << "* Added " << amount << " numbers to container." << std::endl;
}

int		Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	
	std::sort(_numbers.begin(), _numbers.end());

	int	shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _numbers.size() - 1; i++)
	{
		if (shortest > _numbers[i + 1] - _numbers[i])
			shortest = _numbers[i + 1] - _numbers[i];
	}

	return shortest;
}

int		Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}

const char *Span::MaxCapacityException::what() const throw()
{
	return ("Container max capacity reached.");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers in container.");
}
