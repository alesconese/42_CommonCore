/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foo.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:05 by ade-tole          #+#    #+#             */
/*   Updated: 2025/02/26 17:35:06 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOO_HPP
# define FOO_HPP

# include <iostream>

template	<typename T>
void	swap(T &x, T &y)
{
	T	z = x;
	x = y;
	y = z;
}

template	<typename T>
T	min(T x, T y)
{
	if (x < y)
		return x;
	else
		return y;
}

template	<typename T>
T	max(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}

#endif
