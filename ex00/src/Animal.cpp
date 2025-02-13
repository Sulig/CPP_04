/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:57:40 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/13 20:08:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Animal.hpp"

/* Constructor & destructor */
Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
	return ;
}
Animal::Animal(std::string type)
{
	std::cout << "Animal type constructor called" << std::endl;
	this->type = type;
	return ;
}
Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Get */
std::string	Animal::getType() const {	return (this->type); }
/* --- */

/* Member function */
void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
/* --- */
