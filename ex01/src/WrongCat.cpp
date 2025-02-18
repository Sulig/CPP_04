/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:57 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/17 19:31:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/WrongCat.hpp"

/* Constructor & destructor */
WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
	return ;
}
WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = copy;
	return ;
}
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/* ----- */

/* Member function */
void	WrongCat::makeSound() const
{
	std::cout << "Meow meow" << std::endl;
}
/* --- */
