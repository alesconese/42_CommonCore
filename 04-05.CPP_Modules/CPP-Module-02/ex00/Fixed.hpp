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

# include <iostream>

class Fixed
{
	private:
			int					_value;
			static const int	_fractional = 8;
	
	public:
    		Fixed();
    		~Fixed();
			Fixed(Fixed const &src);
			Fixed &operator=(Fixed const &src);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif
