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

int	main()
{
	{
		std::cout << "* * * * * TEST 1: Correct Inheritance * * * * *" << std::endl;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << "* " << meta->getType() << ": ";
		meta->makeSound();
		std::cout << "* " << j->getType() << ": ";
		j->makeSound();
		std::cout << "* " << i->getType() << ": ";
		i->makeSound();
		
		delete i;
		delete j;
		delete meta;
	}
	
	{
		std::cout << std::endl << "* * * * * TEST 2: Wrong Inheritance * * * * *" << std::endl;

		const WrongAnimal* wmeta = new WrongAnimal();
		const WrongAnimal* wi = new WrongCat();
		const WrongCat* wj = new WrongCat();

		std::cout << "* " << wmeta->getType() << ": ";
		wmeta->makeSound();
		std::cout << "* " << wi->getType() << ": ";
		wi->makeSound();
		std::cout << "* " << wj->getType() << ": ";
		wj->makeSound();

		delete wj;
		delete wi;
		delete wmeta;
	}
}
