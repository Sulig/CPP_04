/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:57 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/26 17:29:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Cat.hpp"

/* Constructor & destructor */
Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	return ;
}
Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Member function */
void	Cat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
/* --- */
