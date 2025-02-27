/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:28 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 19:38:23 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AMateria.hpp"
#include "inc/Character.hpp"
#include "inc/Cure.hpp"
#include "inc/Ice.hpp"
#include "inc/MateriaSource.hpp"

/* Test from subject */
void	test_from_subject(void)
{
	std::cout << "Test from subject:" << std::endl;

	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter*	bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << "*************" << std::endl;
}
/*------------*/

/* My tests */
void	my_tests(void)
{
	std::cout << "----------- My tests: -----------------" << std::endl;

	MateriaSource*	cast = new MateriaSource();

	Character*		fabMag = new Character("Faboluous Magician");
	Character*		trnMan = new Character("Training Mannequin");

	AMateria*		ice = new Ice();
	AMateria*		iceCl = ice->clone();
	AMateria*		cure = new Cure();
	AMateria*		cureCl = cure->clone();

	// Learn materia
	cast->learnMateria(NULL);
	cast->learnMateria(ice);
	cast->learnMateria(cure);
	cast->learnMateria(iceCl);
	cast->learnMateria(cureCl);

	// Equip materia
	fabMag->equip(NULL);
	for (int i = 0; i < 5; i++)
	{
		AMateria* tmp = NULL;
		if (i % 2 == 0)
			tmp = cast->createMateria("ice");
		else
			tmp = cast->createMateria("cure");

		if (tmp)
		{
			fabMag->equip(tmp);
			// If equip failed (inventory full), delete tmp
			bool equipped = false;
			for (int j = 0; j < CH_MAX_SLOTS; j++)
			{
				if (fabMag->getMateriaAt(j) == tmp)
				{
					equipped = true;
					break;
				}
			}
			if (!equipped)
				delete tmp;
		}
	}

	// Use materia
	for (int i = 0; i < 5; i++)
		fabMag->use(i, *trnMan);

	// Try to let use the mannequin a materia that is not equipped
	trnMan->use(0, *fabMag);
	trnMan->use(4, *fabMag);

	// Unequip materia
	fabMag->unequip(2);

	// Use materia //** Position 2 is null, so it will do nothing */
	for (int i = 0; i < 5; i++)
		fabMag->use(i, *trnMan);

	// Delete
	delete cast;
	delete fabMag;
	delete trnMan;

	std::cout << "*************" << std::endl;
}
/*---------*/

int	main()
{
	// Test from subject
	test_from_subject();

	// My tests
	my_tests();
	//** */
	return 0;
}
