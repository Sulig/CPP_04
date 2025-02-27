/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:50:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 12:18:17 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Character.hpp"

/* Constructor & destructor */
Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "";
	this->_slots = 0;
	for (int i = 0; i < CH_MAX_SLOTS; i++)
		_inventory[i] = NULL;
	return ;
}
Character::Character(std::string const & name)
{
	std::cout << "Character parameter constructor called" << std::endl;
	this->_name = name;
	this->_slots = 0;
	for (int i = 0; i < CH_MAX_SLOTS; i++)
		_inventory[i] = NULL;
	return ;
}
Character::Character(const Character &copy)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < CH_MAX_SLOTS; i++)
	{
		if (_inventory[i])
			delete (_inventory[i]);
	}
	return ;
}
/* ----- */

/* Operator */
Character	&Character::operator=(const Character &other)
{
	std::cout << "Character assignation operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_slots = other._slots;
		for (int i = 0; i < CH_MAX_SLOTS; i++)
		{
			if (_inventory[i])
				delete (_inventory[i]);
			_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}
/* ----- */

/* Get_Type */
AMateria	*Character::getMateriaAt(int idx) const
{
	if (idx >= 0 && idx < CH_MAX_SLOTS)
		return (_inventory[idx]);
	else
		return (NULL);
}
std::string const & Character::getName() const	{ return (_name); }
/* ----- */

/* Member functions */
/* Equip Materia m to the Character
** If the inventory is full, do nothing
*/
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "The pointer to Materia is NULL." << std::endl;
		return ;
	}
	else if (_slots < CH_MAX_SLOTS && m)
	{
		std::cout << "Equipping " << m->getType() << " to " << _name << " in position:" << _slots << std::endl;
		_inventory[_slots] = m;
		_slots++;
	}
	else
		std::cout << "Inventory full" << std::endl;
}

/* Unequip the Materia at idx (no delete)
** If idx is out of bounds, do nothing
*	* This will not save the pointer in a tmp variable
*/
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < CH_MAX_SLOTS)
	{
		if (_inventory[idx])
		{
			std::cout << "Unequipping " << _inventory[idx]->getType() << " from " << _name << "in position:" << idx << std::endl;
			_inventory[idx] = NULL;
			_slots--;
		}
		else
			std::cout << "No materia at this index" << std::endl;
	}
	else
		std::cout << "Index out of bounds" << std::endl;
}

/* Use the Materia at idx on target
** If idx is out of bounds, do nothing
*/
void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < CH_MAX_SLOTS)
	{
		if (_inventory[idx])
		{
			std::cout << "Using " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
			_inventory[idx]->use(target);
		}
		else
			std::cout << "No materia at this index" << std::endl;
	}
	else
		std::cout << "Index out of bounds" << std::endl;
}
/* ----- */
/*#################################################*/
