/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:28 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 11:43:40 by sadoming         ###   ########.fr       */
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
	std::cout << "My tests:" << std::endl;

	///code here

	std::cout << "*************" << std::endl;
}
/*---------*/

int	main()
{
	// Test from subject
	std::cout << "Test from subject:" << std::endl;
	test_from_subject();

	// My tests
	std::cout << "\nMy tests:" << std::endl;
	my_tests();
	//** */
	return 0;
}
