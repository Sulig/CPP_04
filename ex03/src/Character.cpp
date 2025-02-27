/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:50:54 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 19:38:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Character.hpp"

/* Constructor & destructor */
Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	this->_name = "";
	this->_ground = NULL;
	for (int i = 0; i < CH_MAX_SLOTS; i++)
		_inventory[i] = NULL;
	return ;
}
Character::Character(std::string const & name)
{
	std::cout << "Character parameter constructor called" << std::endl;
	this->_name = name;
	this->_ground = NULL;
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
		_inventory[i] = NULL;
	}

	if (this->_ground)
	{
		for (int i = 0; this->_ground[i]; i++) {
			delete this->_ground[i];
			this->_ground[i] = NULL;
		}
		delete[] this->_ground;
		this->_ground = NULL;
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
		if (other._inventory)
		{
			for (int i = 0; i < CH_MAX_SLOTS; i++)
			{
				if (_inventory[i])
					delete (_inventory[i]);
				if (other._inventory[i])
					_inventory[i] = other._inventory[i]->clone();
				else
					_inventory[i] = NULL;
			}
		}
		else
		{
			for (int i = 0; i < CH_MAX_SLOTS; i++)
				_inventory[i] = NULL;
		}
		if (this->_ground)
		{
			int i = 0;
			while (this->_ground[i])
			{
				delete this->_ground[i];
				i++;
			}
			delete[] this->_ground;
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

/* Check if the inventory is full */
bool	Character::isInventoryFull(void) const
{
	for (int i = 0; i < CH_MAX_SLOTS; i++)
	{
		if (_inventory[i] == NULL)
			return (false);
	}
	return (true);
}

/* Equip Materia m to the Character
** If the inventory is full, do nothing
*/
void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << YELLOW;
		std::cout << "The pointer to Materia is NULL." << std::endl;
		std::cout << RESET;
		return ;
	}

	for (int i = 0; i < CH_MAX_SLOTS; i++)
	{
		if (_inventory[i] == NULL)
		{
			std::cout << GREEN;
			std::cout << "Equipping " << m->getType() << " to " << _name << " in position " << i << std::endl;
			_inventory[i] = m;
			std::cout << RESET;
			return ;
		}
	}
	std::cout << RED;
	std::cout << Character::getName() << " has the inventory full" << std::endl;
	std::cout << RESET;
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
			std::cout << BLUE;
			std::cout << "Unequipping " << _inventory[idx]->getType() << " from " << _name << " in position " << idx << std::endl;
			addToGround(_inventory[idx]);
			_inventory[idx] = NULL;
			std::cout << RESET;
		}
		else
		{
			std::cout << YELLOW;
			std::cout << Character::getName() << " has no materia at this index" << std::endl;
			std::cout << RESET;
		}
	}
	else
	{
		std::cout << RED;
		std::cout << "Index out of bounds for" << Character::getName() << std::endl;
		std::cout << RESET;
	}
}

/* Use the Materia at idx on target
** If idx is out of bounds, do nothing
*/
void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < CH_MAX_SLOTS)
	{
		if (_inventory[idx])
			_inventory[idx]->use(target);
		else
		{
			std::cout << YELLOW;
			std::cout << Character::getName() << " has no materia at this index" << std::endl;
			std::cout << RESET;
		}
	}
	else
	{
		std::cout << RED;
		std::cout << "Index out of bounds for " << Character::getName() << std::endl;
		std::cout << RESET;
	}
}
/* ----- */

/* Utilities */
void	Character::addToGround(AMateria *m)
{
	if (this->_ground == NULL)
	{
		this->_ground = new AMateria*[2];
		this->_ground[0] = m;
		this->_ground[1] = NULL;
		return ;
	}
	else
	{
		AMateria**	tmp;
		int i = 0;

		// Lenght of the array ground
		while (this->_ground[i])
			i++;

		tmp = NULL;
		tmp = new AMateria*[i + 2];

		for (int j = 0; j < i; j++)
			tmp[j] = this->_ground[j];
		tmp[i] = m;
		tmp[i + 1] = NULL;

		delete[] this->_ground;

		this->_ground = tmp;
	}
}
/* ----- */
/*#################################################*/
