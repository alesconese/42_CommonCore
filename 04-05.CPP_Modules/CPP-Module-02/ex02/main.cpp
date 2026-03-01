/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:25:12 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/12 18:25:14 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Fixed		a( 3.1309f );
	Fixed const	b( 3.1270f );

	std::cout << "* a is " << a << std::endl;
	std::cout << "* b is " << b << std::endl;

	std::cout << "* COMPARISON OPERATORS *" << std::endl;
	std::cout << "* {>}: a is ";
	if (!(a > b))
		std::cout << "NOT ";
	std::cout << "bigger than b" << std::endl;
	std::cout << "* {<}: a is ";
	if (!(a < b))
		std::cout << "NOT ";
	std::cout << "smaller than b" << std::endl;
	std::cout << "* {>=}: a is ";
	if (!(a >= b))
		std::cout << "NOT ";
	std::cout << "bigger or equal to b" << std::endl;
	std::cout << "* {<=}: a is ";
	if (!(a <= b))
		std::cout << "NOT ";
	std::cout << "smaller or equal to b" << std::endl;
	std::cout << "* {==}: a is ";
	if (!(a == b))
		std::cout << "NOT ";
	std::cout << "equal to b" << std::endl;
	std::cout << "* {!=}: a is ";
	if (!(a != b))
		std::cout << "NOT ";
	std::cout << "not equal to b" << std::endl;

	std::cout << "* COMPARISON OPERATORS *" << std::endl;
	std::cout << "* {+}: a + b is " << (a + b) << std::endl;
	std::cout << "* {-}: a - b is " << (a - b) << std::endl;
	std::cout << "* {*}: a * b is " << (a * b) << std::endl;
	std::cout << "* {/}: a / b is " << (a / b) << std::endl;

	std::cout << "* INCREMENT/DECREMENT OPERATORS *" << std::endl;
	Fixed		c;
	Fixed const	d(Fixed(5.05f) * Fixed(2));

	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;

	std::cout << "* MIN/MAX FUNCTIONS *" << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "* {min}: ";
	if (Fixed::min(c,d) == c)
		std::cout << "c ( " << c;
	else
		std::cout << "d ( " << d;
	std::cout << " ) is the smallest" << std::endl;
	std::cout << "* {max}: ";
	if (Fixed::max(c,d) == c)
		std::cout << "c ( " << c;
	else
		std::cout << "d ( " << d;
	std::cout << " ) is the greatest" << std::endl;

	return 0;
}
