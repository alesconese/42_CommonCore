/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:32:23 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 19:38:25 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class   PhoneBook
{
	private:
		Contact _contacts[8];
		int     _n_contact;
		int		_full;

	public:
		PhoneBook();
		~PhoneBook();

		void    show_commands();
		void    add_contact();
		void    search_contact();
};

#endif
