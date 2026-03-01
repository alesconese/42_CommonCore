/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:50:25 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:51:21 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
			std::string	_type;

	public:
			WrongAnimal();
			~WrongAnimal();
			WrongAnimal(WrongAnimal const &src);
			WrongAnimal	&operator=(WrongAnimal const &src);

			std::string	getType() const;
			void	setType(std::string type);

			void	makeSound() const;
};

#endif
