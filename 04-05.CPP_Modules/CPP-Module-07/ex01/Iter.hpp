/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:35:17 by ade-tole          #+#    #+#             */
/*   Updated: 2025/02/26 17:35:19 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template	<typename T, typename F>
void	iter(T *arr, unsigned int len, F func)
{
	for (unsigned int i = 0; i < len; i++)
		func(arr[i]);
}

#endif
