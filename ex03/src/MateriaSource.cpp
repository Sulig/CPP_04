/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:48:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 19:38:12 by sadoming         ###   ########.fr       */
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
			delete _materias[i];
		_materias[i] = NULL;
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
		if (other._materias)
		{
			for (int i = 0; i < MS_MAX_SLOTS; i++)
			{
				if (_materias[i])
					delete (_materias[i]);
				if (other._materias[i])
					_materias[i] = other._materias[i]->clone();
				else
					_materias[i] = NULL;
			}
		}
		else
		{
			for (int i = 0; i < MS_MAX_SLOTS; i++)
				_materias[i] = NULL;
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
		std::cout << YELLOW;
		std::cout << "The pointer to Materia is NULL." << std::endl;
		std::cout << RESET;
		return ;
	}
	else if (_slots < 4 && m)
	{
		std::cout << BMAGENTA;
		std::cout << "Learning " << m->getType() << " in position:" << _slots << std::endl;
		_materias[_slots] = m;
		_slots++;
		std::cout << RESET;
	}
	else
	{
		std::cout << RED;
		std::cout << "Inventory full" << std::endl;
		std::cout << RESET;
	}
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
			std::cout << BWHITE;
			std::cout << "Creating " << type << std::endl;
			std::cout << RESET;
			return (_materias[i]->clone());
		}
	}
	std::cout << RED;
	std::cout << "Type is unknown" << std::endl;
	std::cout << RESET;
	return (NULL);
}
/* ----- */
/*#################################################*/
