/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:19:42 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:19:43 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class C>
MutantStack<T,C>::MutantStack()
{
	std::cout << "* MutantStack default constructor called" << std::endl;
}

template <class T, class C>
MutantStack<T,C>::~MutantStack()
{
	std::cout << "* MutantStack default destructor called" << std::endl;
}

template <class T, class C>
MutantStack<T,C>::MutantStack(MutantStack<T,C> const &src)
{
	std::cout << "* MutantStack copy constructor called" << std::endl;
	*this = src;
}

template <class T, class C>
MutantStack<T,C> &MutantStack<T,C>::operator=(MutantStack const &src)
{
	std::cout << "* MutantStack copy assignment operator called" << std::endl;
	if (this != &src)
		this->c = src.c;
	return *this;
}

template <class T, class C>
typename MutantStack<T,C>::iterator	MutantStack<T,C>::begin()
{
	return this->c.begin();
}

template <class T, class C>
typename MutantStack<T,C>::iterator	MutantStack<T,C>::end()
{
	return this->c.end();
}

template <class T, class C>
typename MutantStack<T,C>::const_iterator	MutantStack<T,C>::begin() const
{
	return this->c.begin();
}

template <class T, class C>
typename MutantStack<T,C>::const_iterator	MutantStack<T,C>::end() const
{
	return this->c.end();
}
