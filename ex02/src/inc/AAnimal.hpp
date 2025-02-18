/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:58:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/02/18 17:53:28 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class	AAnimal
{
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &copy);
		virtual	~AAnimal();

		AAnimal	&operator=(const AAnimal &other);

		std::string	getType() const;

		virtual void	makeSound() const =0;

	protected:
		std::string	type;
};

#endif
