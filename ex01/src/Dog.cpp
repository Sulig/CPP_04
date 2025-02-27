/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:40 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 20:07:14 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Dog.hpp"

/* Constructor & destructor */
Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
	return ;
}
Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
	return ;
}
/* ----- */

/* Operator */
Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Member function */
void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
/* --- */
