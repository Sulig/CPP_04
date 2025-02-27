/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:49 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 20:11:56 by sadoming         ###   ########.fr       */
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
	AAnimal*	j = new Dog();
	Dog*		jj = new Dog(*(Dog*)j);
	AAnimal*	jjj = j;

	AAnimal*	i = new Cat();
	Cat*		ii = new Cat(*(Cat*)i);
	AAnimal*	iii = i;

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
	variousAAnimals();
	//** */

	/// Incorrect --> Abstact class
	/*
	* On uncommented, the following code will not compile
	* bcs "AAnimal" is an abstract class
	*/
	/*
	const AAAnimal *animal = new AAAnimal();
	animal->makeSound();
	delete animal;
	*/
	return 0;
}
