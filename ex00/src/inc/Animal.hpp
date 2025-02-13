/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:58:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/13 20:02:29 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal();

		Animal	&operator=(const Animal &other);

		std::string	getType() const;
		virtual void	makeSound() const;

	protected:
		std::string	type;
};

#endif
