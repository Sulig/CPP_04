/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/18 17:58:58 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AAnimal.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"

#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"

/* My tests */
void	my_tests(void)
{
	const	AAnimal*	j = new Dog();
	const	AAnimal*	i = new Cat();

	const	WrongAnimal	k = WrongAnimal();
	const	WrongAnimal	l = WrongCat();

	std::cout << " Correct classes " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << "\n Wrong classes " << std::endl;
	std::cout << k.getType() << " " << std::endl;
	k.makeSound();
	std::cout << l.getType() << " " << std::endl;
	l.makeSound(); // Will print Wrong Animal output

	delete j;
	delete i;
}

void	variousAnimals()
{
	const	AAnimal*	meta[10];

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		std::cout << meta[i]->getType() << " ";
		meta[i]->makeSound();
		delete meta[i];
	}
}
/*---------*/

int main()
{
	// My tests
	std::cout << "\nMy tests:" << std::endl;
	my_tests();

	// Various animals
	std::cout << "\nVarious animals:" << std::endl;
	variousAnimals();
	//** */

	/// Incorrect --> Abstact class
	/*
	* On uncommented, the following code will not compile
	* bcs "Animal" is an abstract class
	*/
	/*
	const AAnimal *animal = new AAnimal();
	animal->makeSound();
	delete animal;
	*/
	return 0;
}
