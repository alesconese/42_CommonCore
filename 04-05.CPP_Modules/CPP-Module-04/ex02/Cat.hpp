/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:10:51 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/26 19:10:53 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>
# include <iostream>

class Cat : public AAnimal
{
	private:
			Brain	*_brain;
			
	public:
			Cat();
			~Cat();
			Cat(Cat const &src);
			Cat	&operator=(Cat const &src);

			void	makeSound() const;
};

#endif
