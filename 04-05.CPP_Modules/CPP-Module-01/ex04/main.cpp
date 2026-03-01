/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-tole <ade-tole@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 20:23:09 by ade-tole          #+#    #+#             */
/*   Updated: 2024/08/17 20:23:11 by ade-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>

std::string	ft_replace(std::string line, std::string old_str, std::string new_str)
{
	size_t	i = line.find(old_str, 0);

	while (i != std::string::npos)
	{
		line = line.substr(0, i) + new_str+ line.substr(i + old_str.length());
		i = line.find(old_str, i + new_str.length());
	}
	return (line);
}

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		line;

	if (argc != 4)
		return ((std::cerr << "! Error: Wrong parameters. Use ./sed <file> <old_string> <new_string>." << std::endl), 1);
	ifs.open(argv[1]);
	if (ifs.fail())
		return ((std::cerr << "! Error: Unable to open file <" << argv[1] << ">. " << std::strerror(errno) << std::endl), 1);
	ofs.open(((std::string(argv[1])).append(".replace")).c_str());
	if (ofs.fail())
		return ((std::cerr << "! Error: Unable to create new file. " << std::strerror(errno) << std::endl), 1);
	while(std::getline(ifs, line))
	{
		line = ft_replace(line, std::string(argv[2]), std::string(argv[3]));
		ofs << line;
		if (!ofs.eof())
			ofs << std::endl;
	}
	ifs.close();
	ofs.close();

	return (0);
}
