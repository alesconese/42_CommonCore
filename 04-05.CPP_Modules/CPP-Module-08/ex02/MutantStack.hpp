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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>
# include <iostream>

template	<class T, class C = std::deque<T> >
class MutantStack : public std::stack<T,C>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(MutantStack const &src);
		MutantStack &operator=(MutantStack const &src);

		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;

		iterator	begin();
		iterator	end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

# include "MutantStack.tpp"

#endif