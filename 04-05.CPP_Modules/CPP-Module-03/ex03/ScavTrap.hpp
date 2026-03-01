/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:07:30 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/20 19:07:31 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
			ScavTrap();
			ScavTrap(std::string name);
			~ScavTrap();
			ScavTrap(ScavTrap const &src);
			ScavTrap	&operator=(ScavTrap const &src);

			void	attack(const std::string &target);
			void	attack(ClapTrap &target);
			void	takeDamage(unsigned int amount);
			void	beRapaired(unsigned int amount);
			void	guardGate();
};

#endif
