/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:57 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:38:02 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Cat.hpp"

/* Constructor & destructor */
Cat::Cat() : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
	return ;
}
Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
	this->brain = NULL;
	return ;
}
/* ----- */

/* Operator */
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}
/* ----- */

/* Member function */
Brain*	Cat::getBrain() const { return (this->brain); }

void	Cat::makeSound() const { std::cout << "Meow meow" << std::endl; }
/* --- */
