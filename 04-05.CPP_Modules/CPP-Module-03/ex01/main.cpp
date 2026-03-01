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

#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1 * * * * *" << std::endl;
		ScavTrap s1("Scavvy");
		ClapTrap c1("Clappy");

		s1.attack("Trappy");
		c1.takeDamage(20);
		s1.beRapaired(100);
		s1.guardGate();
	}

	{
		std::cout << std::endl << "* * * * * TEST 2 * * * * *" << std::endl;
		ClapTrap c1("Clappy");
		ScavTrap s1("Scavvy");
		ScavTrap s2("Trappy");
		
		c1.setAttackDamage(50);
		c1.attack(s1);
		s1.beRapaired(100);
		s1.attack(c1);
		s1.attack(s2);
	}
	return 0;
}
