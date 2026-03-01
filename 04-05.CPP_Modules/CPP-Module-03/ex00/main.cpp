/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:20:00 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/19 20:20:01 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1 * * * * *" << std::endl;
		ClapTrap c1("Clappy");
		ClapTrap c2("Trappy");

		for (int i = 0; i < 10; i++)
		{
			c1.attack("Trappy");
			c2.takeDamage(0);
		}
		c1.attack("Trappy");
		c2.beRapaired(10);
	}
	
	{
		std::cout << std::endl << "* * * * * TEST 2 * * * * *" << std::endl;
		ClapTrap c1("Clappy");
		ClapTrap c2("Trappy");
		
		c1.setAttackDamage(5);
		c1.attack(c2);
		c2.beRapaired(10);
		c1.attack(c2);
		c1.attack(c2);
		c2.attack(c1);
		c2.beRapaired(10);
	}
	return 0;
}
