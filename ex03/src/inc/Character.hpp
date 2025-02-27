/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:59:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 13:43:03 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Colors.hpp"

# define CH_MAX_SLOTS	4

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[CH_MAX_SLOTS];
		int			_slots;

	public:
		Character();
		Character(std::string const & name);
		Character(const Character &copy);
		~Character();

		Character	&operator=(const Character &other);

		AMateria	*getMateriaAt(int idx) const;
		std::string const & getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};
#endif
