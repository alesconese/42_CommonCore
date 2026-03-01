/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:23:55 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:16:09 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: ADDING NUMBERS MANUALLY * * * * *" << std::endl;
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "* Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n\n* * * * * TEST 2: ADDING MANY NUMBERS * * * * *" << std::endl;
		Span	sp = Span(20000);

		sp.addMany(10000);
		sp.addMany(10000);

		std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "* Longest Span: " << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n\n* * * * * TEST 3: EXCEPTIONS * * * * *" << std::endl;
		Span	sp = Span(5);
		
		try
		{
			std::cout << "* Shortest Span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}

		try
		{
			std::cout << "* Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}

		try
		{
			sp.addMany(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}

		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(42);
		}
		catch(const std::exception& e)
		{
			std::cerr << "(!) ERROR: " << e.what() << '\n';
		}
	}

	return 0;
}
