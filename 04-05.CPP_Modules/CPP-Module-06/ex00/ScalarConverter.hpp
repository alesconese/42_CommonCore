/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:34:48 by ade-tole          #+#    #+#             */
/*   Updated: 2024/12/05 18:34:50 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>

class ScalarConverter
{
	private:
			ScalarConverter();
			~ScalarConverter();
			ScalarConverter(ScalarConverter const &src);
			ScalarConverter &operator=(ScalarConverter const &src);

	public:
			static void	convert(std::string input);
};

#endif
