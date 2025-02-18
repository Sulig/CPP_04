/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:14:56 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/18 17:16:34 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Brain.hpp"

/* Constructor & destructor */
Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
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
