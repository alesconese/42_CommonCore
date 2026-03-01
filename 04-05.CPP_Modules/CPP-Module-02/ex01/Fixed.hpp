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
			Fixed &operator=(Fixed const &other);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &src);

#endif
