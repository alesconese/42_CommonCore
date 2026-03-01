/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:08:37 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:08:43 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);

void	randomChump(std::string name);

int	main()
{
	Zombie *z1 = newZombie("Paco");

	randomChump("Pepe");
	z1->announce();
	randomChump("Juan");
	delete z1;
}
