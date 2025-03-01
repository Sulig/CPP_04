/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:43:29 by sadoming         ###   ########.fr       */
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

/* My tests */
void	my_tests(void)
{
	Animal*	meta = new Animal();

	Animal*	j = new Dog();
	Animal*	jj = new Animal(*j);
	Animal*	jjj = j;

	Animal*	i = new Cat();
	Animal*	ii = new Animal(*i);
	Animal*	iii = i;

	WrongAnimal	k = WrongAnimal();
	WrongAnimal	l = WrongCat();
	WrongAnimal	pp = l;

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

	std::cout << "\n Copy constructors " << std::endl;
	std::cout << jj->getType() << " " << std::endl;
	jj->makeSound();
	std::cout << ii->getType() << " " << std::endl;
	ii->makeSound();

	std::cout << "\n Pointers to the same object " << std::endl;
	jjj->makeSound();
	iii->makeSound();
	pp.makeSound();

	// Delete all objects
	delete meta;
	delete j;
	delete jj;

	delete i;
	delete ii;
}
/*---------*/

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

	std::cout << "*---------*" << std::endl;
	std::cout << "Copy Demostration" << std::endl;
	// Demostrate that copies are deep copies
	Dog	dog;
	Cat	cat;

	dog.getBrain()->setIdea("I need to go out");
	std::cout << "DOG's idea: ";
	std::cout << dog.getBrain()->getIdea(0) << std::endl;

	Dog	dog2 = dog;
	std::cout << "DOG2's idea: ";
	std::cout << dog2.getBrain()->getIdea(0);

	cat.getBrain()->setIdea("It's 3:00 am. Time to play");
	std::cout << "CAT's idea: ";
	std::cout << cat.getBrain()->getIdea(0) << std::endl;

	Cat	cat2 = cat;
	std::cout << "CAT2's idea: ";
	std::cout << cat2.getBrain()->getIdea(0);
	std::cout << std::endl << "*---------*" << std::endl;

	return 0;
}
