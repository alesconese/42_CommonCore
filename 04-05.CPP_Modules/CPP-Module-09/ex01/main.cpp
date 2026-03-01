/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:17:04 by ade-tole          #+#    #+#             */
/*   Updated: 2025/03/21 19:17:05 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return ((std::cout << "(!) ERROR: wrong arguments" << std::endl), 1);

	try
	{
		RPN	rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << "(!) ERROR: " << e.what() << std::endl;
	}
	
	return 0;
}
