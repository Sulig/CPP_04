/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:40 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/17 19:30:32 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/WrongAnimal.hpp"

/* Constructor & destructor */
WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal, base class default constructor called" << std::endl;
	this->type = "WrongAnimal";
	return ;
}
WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal base class type constructor called" << std::endl;
	this->type = type;
	return ;
}
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal base class copy constructor called" << std::endl;
	*this = copy;
	return ;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal base class destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal base class assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Get */
std::string	WrongAnimal::getType() const {	return (this->type); }
/* --- */

/* Member function */
void	WrongAnimal::makeSound() const
{
	std::cout << "*Undefined type of noise*" << std::endl;
}
/* --- */
