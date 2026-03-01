/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:26:01 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/12 18:26:03 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const int_v): _value(int_v << _fractional)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fp_v): _value(roundf(fp_v * (1 << _fractional)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	_value = src.getRawBits();
	return *this;
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed	Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

bool 	Fixed::operator>(Fixed const &other) const
{
	if (_value > other.getRawBits())
		return true;
	return false;
}

bool 	Fixed::operator<(Fixed const &other) const
{
	if (_value < other.getRawBits())
		return true;
	return false;
}

bool	 Fixed::operator>=(Fixed const &other) const
{
	if (_value >= other.getRawBits())
		return true;
	return false;
}

bool 	Fixed::operator<=(Fixed const &other) const
{
	if (_value <= other.getRawBits())
		return true;
	return false;
}

bool 	Fixed::operator==(Fixed const &other) const
{
	if (_value == other.getRawBits())
		return true;
	return false;
}

bool 	Fixed::operator!=(Fixed const &other) const
{
	if (_value != other.getRawBits())
		return true;
	return false;
}

Fixed	&Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	_value++;
	return tmp;
}

Fixed	&Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	_value--;
	return tmp;
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractional));
}

int		Fixed::toInt(void) const
{
	return (_value >> _fractional);
}

Fixed		&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed const	&Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed		&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

Fixed const	&Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1 > f2)
		return f1;
	return f2;
}

std::ostream	&operator<<(std::ostream &os, Fixed const &src)
{
	os << src.toFloat();
	return os;
}
