/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:14:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:37:24 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Brain.hpp"

/* Constructor & destructor */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
	return ;
}
Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
	return ;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}
/* ----- */

/* Operator */
Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}
/* ----- */

/* Member function */
void	Brain::setIdea(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->ideas[i].empty())
		{
			this->ideas[i] = idea;
			std::cout << "Idea set in position: " << i<< std::endl;
			return ;
		}
	}
	std::cout << "No more space for ideas" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cout << "Invalid index" << std::endl;
		return ("");
	}
	return (this->ideas[index]);
}
/* --- */
