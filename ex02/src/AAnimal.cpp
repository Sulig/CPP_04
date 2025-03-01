/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:40 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:37:57 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/AAnimal.hpp"

/* Constructor & destructor */
AAnimal::AAnimal()
{
	std::cout << "AAnimal, base class default constructor called" << std::endl;
	this->type = "Animal";
	return ;
}
AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal, base class type constructor called" << std::endl;
	this->type = type;
	return ;
}
AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "AAnimal, base class copy constructor called" << std::endl;
	*this = copy;
	return ;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal, base class destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal, base class assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Get */
std::string	AAnimal::getType() const	{	return (this->type); }
/* --- */

/// void	Animal::makeSound() const = 0;
