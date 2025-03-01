/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:30:19 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:37:51 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();

		Dog	&operator=(const Dog &other);

		Brain*	getBrain() const;

		virtual void	makeSound() const;

	private:
		Brain*	brain;
};

#endif
