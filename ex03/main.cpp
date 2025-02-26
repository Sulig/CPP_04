/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:55:28 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/19 17:50:22 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ICharacter.hpp"
#include "inc/AMateria.hpp"

/* Test from subject */
void	test_from_subject(void)
{
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
}
/*------------*/

int	main()
{
	// Test from subject
	std::cout << "Test from subject:" << std::endl;
	test_from_subject();

	// My tests
	std::cout << "\nMy tests:" << std::endl;
	//my_tests();
	//** */
	return 0;
}
