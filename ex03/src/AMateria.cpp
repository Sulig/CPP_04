/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:50:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 11:38:22 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "inc/AMateria.hpp"

/* Constructor & destructor */
AMateria::AMateria()
{
	std::cout << "Base Materia class default constructor called" << std::endl;
	_type = "";
	return ;
}
AMateria::AMateria(std::string const & type)
{
	std::cout << "Base Materia class parameter constructor called" << std::endl;
	_type = type;
	return ;
}
AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Base Materia class copy constructor called" << std::endl;
	*this = copy;
	return ;
}
AMateria::~AMateria()
{
	std::cout << "Base Materia class destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
AMateria	&AMateria::operator=(const AMateria &other)
{
	std::cout << "Base Materia class assignation operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}
/* ----- */

/* Get_Type */
std::string const & AMateria::getType() const { return (_type); }
/* ----- */

/* Member functions */
/// virtual AMateria*	clone() const = 0;

void	AMateria::use(ICharacter &target)
{
	std::cout << "Using " << _type << " on " << target.getName() << std::endl;
}
/* ----- */
