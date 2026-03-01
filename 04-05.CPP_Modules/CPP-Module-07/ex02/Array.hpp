/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:36:03 by ade-tole          #+#    #+#             */
/*   Updated: 2025/02/26 17:36:04 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template	<class T>
class Array
{
	private:
			T				*_arr;
			unsigned int	_size;
	
	public:
			Array();
			Array(unsigned int n);
			~Array();
			Array(Array const &src);
			Array &operator=(Array const &src);

			unsigned int Size(void);
			T &operator[](unsigned int index);
			T const	&operator[](unsigned int index) const;

			class OutOfBoundsException : public std::exception
			{
				const char *what() const throw();
			};
};

#include "Array.tpp"

#endif
