/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:05:57 by ade-tole          #+#    #+#             */
/*   Updated: 2024/09/02 21:05:59 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;

    if (argc == 2)
        harl.complain(argv[1]);
    else
        std::cout << "[ Probably complaining about insignificcant problems ]" << std::endl;

    return 0;
}
