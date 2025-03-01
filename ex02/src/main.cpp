/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:38:05 by sadoming         ###   ########.fr       */
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
	Dog*	j = new Dog();
	Dog*	jj = new Dog(*(Dog*)j);
	Dog*	jjj = j;

	Cat*	i = new Cat();
	Cat*	ii = new Cat(*(Cat*)i);
	Cat*	iii = i;

	WrongAnimal	k = WrongAnimal();
	WrongAnimal	l = WrongCat();
	WrongAnimal	pp = l;

	std::cout << " Correct classes " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();

	std::cout << "\n Wrong classes " << std::endl;
	std::cout << k.getType() << " " << std::endl;
	k.makeSound();
	std::cout << l.getType() << " " << std::endl;
	l.makeSound(); // Will print Wrong AAnimal output

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
	delete j;
	delete jj;

	delete i;
	delete ii;
}
/*---------*/

void	variousAAnimals()
{
	const	Cat*		cat[5];
	const	Dog*		dog[5];

	for (int i = 0; i < 5; i++)
	{
		cat[i] = new Cat();
		dog[i] = new Dog();
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << cat[i]->getType() << " ";
		cat[i]->makeSound();
		std::cout << dog[i]->getType() << " ";
		dog[i]->makeSound();
	}
	for (int i = 0; i < 5; i++)
	{
		delete cat[i];
		cat[i] = NULL;
		delete dog[i];
		dog[i] = NULL;
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
	variousAAnimals();
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
	/*--*/

	/// Incorrect --> Abstact class
	/* On uncommented, the following code will not compile
	*	bcs "AAnimal" is an abstract class
	*/
	/*
	const AAnimal *animal = new AAnimal();
	animal->makeSound();
	delete animal;
	*/
	return 0;
}
