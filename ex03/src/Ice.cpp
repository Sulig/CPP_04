/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:52:39 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 13:26:25 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/Ice.hpp"

/* Constructor & destructor */
Ice::Ice() : AMateria("ice") { return ; }
Ice::Ice(const Ice &copy) : AMateria(copy) { return ; }
Ice::~Ice() { return ; }
/* ----- */

/* Operator */
Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}
/* ----- */

/* Member functions */
AMateria*	Ice::clone() const
{
	AMateria	*clone = new Ice(*this);
	return (clone);
}

void		Ice::use(ICharacter& target)
{
	std::cout << BCYAN;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << RESET;
}
/* ----- */

