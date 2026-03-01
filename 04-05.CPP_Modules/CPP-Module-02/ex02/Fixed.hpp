/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:21:05 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/06 19:21:07 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
	private:
			int					_value;
			static const int	_fractional = 8;
	
	public:
    		Fixed();
    		~Fixed();
			Fixed(int const int_v);
			Fixed(float const fp_v);
			Fixed(Fixed const &src);

			Fixed	&operator=(Fixed const &other);
			Fixed	operator+(Fixed const &other) const;
			Fixed	operator-(Fixed const &other) const;
			Fixed	operator*(Fixed const &other) const;
			Fixed	operator/(Fixed const &other) const;

			bool	operator>(Fixed const &other) const;
			bool	operator<(Fixed const &other) const;
			bool	operator>=(Fixed const &other) const;
			bool	operator<=(Fixed const &other) const;
			bool	operator==(Fixed const &other) const;
			bool	operator!=(Fixed const &other) const;

			Fixed	&operator++();
			Fixed	operator++(int);
			Fixed	&operator--();
			Fixed	operator--(int);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;

			static Fixed		&min(Fixed &f1, Fixed &f2);
			static Fixed const	&min(Fixed const &f1, Fixed const &f2);
			static Fixed		&max(Fixed &f1, Fixed &f2);
			static Fixed const	&max(Fixed const &f1, Fixed const &f2);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &src);

#endif
