/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:58:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:38:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

/* AAnimal class */
/*	Animal class is an Abstract base class.
*	but it is not pure virtual because it has a constructor.
*
* - Destructor is public and virtual.
* ** bcs is necesary to delete children object.
* ** (virtual) -> Asegure the right order destruction
*---
* - getType() is a getter for type.
* - makeSound() is a pure virtual function.
*---
* - type is protected to be accessed by children.
* - Constructor is protected (only accessed by children).
*/
class	AAnimal
{
	public:
		virtual	~AAnimal();
		std::string	getType() const;
		virtual void	makeSound() const = 0;

	protected:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);

		AAnimal	&operator=(const AAnimal &other);

	protected:
		std::string	type;
};

#endif
