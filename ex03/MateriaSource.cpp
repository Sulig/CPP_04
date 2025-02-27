/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:48:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 12:17:13 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/MateriaSource.hpp"

/* Constructor & destructor */
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->_slots = 0;
	for (int i = 0; i < MS_MAX_SLOTS; i++)
		_materias[i] = NULL;
	return ;
}
MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = copy;
	return ;
}
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MS_MAX_SLOTS; i++)
	{
		if (_materias[i])
			delete (_materias[i]);
	}
	return ;
}
/* ----- */

/* Operator */
MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_slots = other._slots;
		for (int i = 0; i < MS_MAX_SLOTS; i++)
		{
			if (_materias[i])
				delete (_materias[i]);
			_materias[i] = other._materias[i]->clone();
		}
	}
	return (*this);
}
/* ----- */

/* Member functions */
/* Learn Materia m
** If the inventory is full, do nothing
*/
void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "The pointer to Materia is NULL." << std::endl;
		return ;
	}
	else if (_slots < 4 && m)
	{
		std::cout << "Learning " << m->getType() << " in position:" << _slots << std::endl;
		_materias[_slots] = m;
		_slots++;
	}
	else
		std::cout << "Inventory full" << std::endl;
}

/* Create Materia of type
** If the type is not found, return NULL
*/
AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MS_MAX_SLOTS; i++)
	{
		if (_materias[i] && _materias[i]->getType() == type)
		{
			std::cout << "Creating " << type << std::endl;
			return (_materias[i]->clone());
		}
	}
	std::cout << "Type is unknown" << std::endl;
	return (NULL);
}
/* ----- */
/*#################################################*/
