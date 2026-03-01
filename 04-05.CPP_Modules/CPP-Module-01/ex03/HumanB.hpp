/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:17:01 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:17:04 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>
# include <iostream>

class	HumanB
{
	private:
			std::string	_name;
			Weapon		*_weapon;

	public:
			HumanB(std::string name);
			HumanB(std::string name, Weapon &weapon);
			~HumanB();

			void	attack(void) const;
			void	setWeapon(Weapon &weapon);
};

#endif
