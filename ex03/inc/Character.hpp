/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:59:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/26 20:00:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_materias[4];
		int			_index;

	public:
		Character();
		Character(std::string const & name);
		Character(const Character &copy);
		~Character();

		Character	&operator=(const Character &other);

		std::string const & getName() const;

		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);
};
#endif
