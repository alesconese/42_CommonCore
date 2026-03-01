/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:24:21 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:15:10 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T> int easyfind(T first, int second)
{
	typename T::iterator	it = std::find(first.begin(), first.end(), second);

	if (it != first.end())
		 return (std::distance(first.begin(), it));
	return (-1);
}

#endif
