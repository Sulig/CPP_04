/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:55:11 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/26 19:58:57 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_materias[4];
		int			_index;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &copy);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &other);

		void		learnMateria(AMateria *m);
		AMateria*	createMateria(std::string const & type);
};

#endif
