/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 18:52:27 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/14 19:15:26 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

#define ELEMENTS 10

int	main()
{
	std::vector<int>	vi;
	int	element;
	int	pos;

	std::cout << "* Created vector: { ";
	srand(time(NULL));
	for (int i = 0; i < ELEMENTS; i++)
	{
		element = rand() % 10;
		vi.push_back(element);
		std::cout << element << " ";
	}
	std::cout << "}" << std::endl;
	
	element = rand() % 15;
	std::cout << std::endl << "* searching for element " << element << " in vector..." << std::endl;
	pos = easyfind(vi, element);
	if (pos == -1)
		std::cout << "* element not present in vector" << std::endl;
	else
		std::cout << "* found element in vector position: " << pos << std::endl;

	return 0;
}
