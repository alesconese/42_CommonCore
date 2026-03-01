/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:54:12 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:54:13 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>
# include <iostream>

class WrongCat : public WrongAnimal
{
	public:
			WrongCat();
			~WrongCat();
			WrongCat(WrongCat const &src);
			WrongCat	&operator=(WrongCat const &src);

			void	makeSound() const;
};

#endif
