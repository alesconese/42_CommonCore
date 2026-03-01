/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 20:28:15 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/20 20:28:16 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class FragTrap : public ClapTrap
{
	public:
			FragTrap();
			FragTrap(std::string name);
			~FragTrap();
			FragTrap(FragTrap const &src);
			FragTrap	&operator=(FragTrap const &src);

			void	attack(const std::string &target);
			void	attack(ClapTrap &target);
			void	takeDamage(unsigned int amount);
			void	beRapaired(unsigned int amount);
			void	highFivesGuys(void);
};

#endif
