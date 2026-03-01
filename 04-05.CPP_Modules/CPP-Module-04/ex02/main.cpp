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

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	std::cout << "* * * * * TEST 1: Abstract Class * * * * *" << std::endl;
	//AAnimal is an abstract class so it cannot be instantiated.
	//Program will not compile if uncommented.
	//AAnimal *a1 = new AAnimal();
	AAnimal *c1 = new Cat();
	AAnimal *d1 = new Dog();

	//a1->makeSound();
	c1->makeSound();
	d1->makeSound();

	//delete a1;
	delete c1;
	delete d1;
}
