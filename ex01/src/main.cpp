/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/18 17:34:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Animal.hpp"
#include "inc/Dog.hpp"
#include "inc/Cat.hpp"

#include "inc/WrongAnimal.hpp"
#include "inc/WrongCat.hpp"

/* Test from subject */
void	test_from_subject(void)
{
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;//should not create a leak
	delete i;
}
/*------------*/

/* My tests */
void	my_tests(void)
{
	const	Animal*	meta = new Animal();
	const	Animal*	j = new Dog();
	const	Animal*	i = new Cat();

	const	WrongAnimal	k = WrongAnimal();
	const	WrongAnimal	l = WrongCat();

	std::cout << " Correct classes " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << "\n Wrong classes " << std::endl;
	std::cout << k.getType() << " " << std::endl;
	k.makeSound();
	std::cout << l.getType() << " " << std::endl;
	l.makeSound(); // Will print Wrong Animal output

	delete meta;
	delete j;
	delete i;
}

void	variousAnimals()
{
	const	Animal*	meta[10];

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
	// Test from subject
	std::cout << "Test from subject:" << std::endl;
	test_from_subject();

	// My tests
	std::cout << "\nMy tests:" << std::endl;
	my_tests();

	// Various animals
	std::cout << "\nVarious animals:" << std::endl;
	variousAnimals();
	//** */
	return 0;
}
