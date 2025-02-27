/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:49:18 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/27 13:18:52 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();

		Cure	&operator=(const Cure &other);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
