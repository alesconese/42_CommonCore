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

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1 * * * * *" << std::endl;
		FragTrap f1("Fraggy");
		ClapTrap c1("Clappy");

		f1.attack("Clappy");
		c1.takeDamage(30);
		f1.beRapaired(100);
		f1.highFivesGuys();
	}

	{
		std::cout << std::endl << "* * * * * TEST 2 * * * * *" << std::endl;
		ClapTrap c1("Clappy");
		ScavTrap s1("Scavvy");
		FragTrap f1("Fraggy");
		
		c1.attack(f1);
		f1.attack(c1);
		s1.attack(f1);
		f1.beRapaired(100);
		f1.highFivesGuys();
	}
	return 0;
}
