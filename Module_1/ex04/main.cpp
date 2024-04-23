/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlarue <jlarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:45:36 by jozy              #+#    #+#             */
/*   Updated: 2024/01/23 14:24:21 by jlarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int	replace(char **av, std::string str)
{
	std::ofstream	outfile;
	int				pos;
	int				i;
	int				size_string;
	int				size_replaced;

	i = 0;
	size_string = str.size();
	size_replaced = (int)std::string(av[2]).size() - 1;
	outfile.open((std::string(av[1]) + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error : cannot open outfile, chmod issue" << std::endl;
		return (1);
	}
	while (i < size_string)
	{
		pos = str.find(av[2], i);
		if (pos != i || pos == -1)
			outfile << str[i];
		else
		{
			if ((int)std::string(av[2]).size() != 0)
				outfile << av[3];
			else
				break ;
			i += size_replaced;
		}
		i++;
	}
	outfile.close();
	return (0);
}

int	main(int ac, char **av)
{
	char			c;
	std::ifstream	infile;
	std::string		str;

	if (ac != 4)
	{
		std::cout << "Error : replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << "Error : cannot open infile, does not exist or chmod issue" << std::endl;
		return (1);
	}
	while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	std::cout << str << std::endl;
	infile.close();
	return (replace(av, str));
}
