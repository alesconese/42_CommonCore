/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:17:50 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:17:52 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		std::cout << "* * * * * TEST 1: MUTANT STACK FUNCTIONS * * * * *" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\n* * * * * TEST 2: COMPARING WITH LIST CONTAINER * * * * *" << std::endl;
		std::list<int> mylist;
		mylist.push_back(5);
		mylist.push_back(17);
		std::cout << mylist.back() << std::endl;
		mylist.pop_back();
		std::cout << mylist.size() << std::endl;
		mylist.push_back(3);
		mylist.push_back(5);
		mylist.push_back(737);
		mylist.push_back(0);
		std::list<int>::iterator it = mylist.begin();
		std::list<int>::iterator ite = mylist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mylist);
	}
	return 0;
}