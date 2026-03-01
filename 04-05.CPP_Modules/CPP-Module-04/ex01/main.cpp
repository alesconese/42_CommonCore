/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:22:54 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:22:55 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Cats & Dogs * * * * *" << std::endl;
		Animal *cats_and_dogs[10];
		for (int i = 0; i < 10; i++)
		{
			std::cout << "[ " << i << " ]" << std::endl;
			if (i % 2 == 0)
				cats_and_dogs[i] = new Cat();
			else
				cats_and_dogs[i] = new Dog();
			cats_and_dogs[i]->makeSound();
		}
		std::cout << std::endl << "[ DESTRUCTORS ]" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			delete cats_and_dogs[i];
		}
	}
	
	{
		std::cout << std::endl << "* * * * * TEST 2: DEEP COPY * * * * *" << std::endl;
		const Cat *c1 = new Cat();
		const Cat *c2 = c1;
		const Animal *c3 = new Cat();
		const Animal *c4 = c3;
		
		std::cout << "C1: " << c1 << std::endl;
		c1->makeSound();
		std::cout << "C2: " << c2 << std::endl;
		c2->makeSound();
		std::cout << "C3: " << c3 << std::endl;
		c3->makeSound();
		std::cout << "C4: " << c4 << std::endl;
		c4->makeSound();

		delete c1;
		//delete c2;
		delete c3;
		//delete c4;
	}
}
