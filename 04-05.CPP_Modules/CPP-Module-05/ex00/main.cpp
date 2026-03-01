/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:19:09 by ade-tole          #+#    #+#             */
/*   Updated: 2024/11/21 18:41:18 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Grade too high * * * * *" << std::endl;
		try
		{
			Bureaucrat b1("Mike", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 2: Grade too low * * * * *" << std::endl;
		try
		{
			Bureaucrat b2("Bob", 999);
		}
		catch (std::exception &e)
		{
			std::cout << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 3: Increment too high * * * * *" << std::endl;
		Bureaucrat b3("Jim", 5);
		try
		{
			for (int i = 0; i < 10; i++)
			{
				b3.incrementGrade();
				std::cout << b3 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 4: Decrement too low * * * * *" << std::endl;
		Bureaucrat b4("Bill", 146);
		try
		{
			for (int i = 0; i < 10; i++)
			{
				b4.decrementGrade();
				std::cout << b4 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "(!) ERROR: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n* * * * * TEST 5: grades OK * * * * *" << std::endl;
		try
		{
			Bureaucrat b5("Joe", 99);
			for (int i = 0; i < 5; i++)
			{
				b5.incrementGrade();
				std::cout << b5 << std::endl;
				b5.decrementGrade();
				std::cout << b5 << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << "(!) ERROR: " << e.what() << std::endl;
		}
	}
}
