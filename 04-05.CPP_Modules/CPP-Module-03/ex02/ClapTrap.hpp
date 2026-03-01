/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:01:25 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/19 20:01:30 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
	protected:
			std::string	_name;
			int			_hitPoints;
			int			_energyPoints;
			int			_attackDamage;
	
	public:
			ClapTrap();
			ClapTrap(std::string name);
			~ClapTrap();
			ClapTrap(ClapTrap const &src);
			ClapTrap	&operator=(ClapTrap const &src);

			void	attack(const std::string &target);
			void	attack(ClapTrap &target);
			virtual void	takeDamage(unsigned int amount);
			void	beRapaired(unsigned int amount);

			std::string	getName() const;
			int			getHitPoints() const;
			int			getEnergyPoints() const;
			int			getAttackDamage() const;
			void		setName(std::string name);
			void		setHitPoints(unsigned int hitPoints);
			void		setEnergyPoints(unsigned int energyPoints);
			void		setAttackDamage(unsigned int attackDamage);
};

#endif
