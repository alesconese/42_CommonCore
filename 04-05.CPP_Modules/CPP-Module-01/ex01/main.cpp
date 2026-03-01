/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:11:42 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:12:07 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int	N = 5;
	Zombie *h1 = zombieHorde(N, "Paco");

	for (int i = 0; i < N; i++)
		h1[i].announce();
	delete [] h1;
}
