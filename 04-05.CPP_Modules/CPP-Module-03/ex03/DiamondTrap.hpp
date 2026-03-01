/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:42:44 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/25 19:42:45 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <string>
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
			std::string	_name;

	public:
			DiamondTrap();
			DiamondTrap(std::string name);
			~DiamondTrap();
			DiamondTrap(DiamondTrap const &src);
			DiamondTrap	&operator=(DiamondTrap const &src);

			void	whoAmI();
};

# endif
