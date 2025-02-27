/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:52:39 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 11:46:30 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/Cure.hpp"

/* Constructor & destructor */
Cure::Cure() : AMateria("cure") { return ; }
Cure::Cure(const Cure &copy) : AMateria(copy) { return ; }
Cure::~Cure() { return ; }
/* ----- */

/* Operator */
Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}
/* ----- */

/* Member functions */
AMateria*	Cure::clone() const	{ return (new Cure(*this)); }

void		Cure::use(ICharacter& target)
{
	std::cout << BGREEN;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	std::cout << RESET;
}
/* ----- */

