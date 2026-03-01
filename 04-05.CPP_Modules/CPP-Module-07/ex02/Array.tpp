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

#include "Array.hpp"

template <class T> Array<T>::Array()
{
	std::cout << "* Array default constructor called." << std::endl;
	_size = 0;
	_arr = new T[0];
}

template <class T> Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "* Array constructor called." << std::endl;
	_arr = new T[n];
}

template <class T> Array<T>::~Array()
{
	std::cout << "* Array default destructor called" << std::endl;
	delete [] _arr;
}

template <class T> Array<T>::Array(Array const &src): _size(src._size)
{
	std::cout << "* Array copy constructor called" << std::endl;
	_size = src._size;
	_arr = new T[src._size];
	for (unsigned int i = 0; i < src._size; i++)
		_arr[i] = src._arr[i];
}

template <class T> Array<T> &Array<T>::operator=(Array const &src)
{
	std::cout << "* Array copy assignment operator called" << std::endl;
	if (this != &src)
	{
		delete [] _arr;
		_size = src._size;
		_arr = new T[src._size];
		for (unsigned int i = 0; i < src._size; i++)
			_arr[i] = src._arr[i];
	}
	return *this;
}

template <class T> unsigned int	Array<T>::Size(void) { return _size; }

//needs to be accessible for read but not write on const instances. fix???
template <class T> T const	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _arr[index];
}

template <class T> T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _arr[index];
}

template <class T> const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of range of array.");
}
