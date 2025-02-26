/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:54:57 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/18 19:16:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"

class ICharacter
{
	public:
		ICharacter();
		ICharacter(std::string name);
		ICharacter(const ICharacter &copy);
		virtual	~ICharacter() {}

		ICharacter	&operator=(const ICharacter &other);

		virtual std::string const & getName() const = 0;

		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;

	private:
		std::string	name;
		AMateria*	inventory[4];
};

#endif
