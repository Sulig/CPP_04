/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:10:32 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/01 15:38:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain	&operator=(const Brain &other);

		void		setIdea(std::string idea);
		std::string	getIdea(int index) const;

	protected:
		std::string	ideas[100];
};

#endif
