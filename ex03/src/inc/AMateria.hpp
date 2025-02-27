/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:51:00 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 13:43:45 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "Character.hpp"
# include "Colors.hpp"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &copy);
		virtual ~AMateria();

		AMateria	&operator=(const AMateria &other);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
